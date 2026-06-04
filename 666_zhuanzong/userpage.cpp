#include "userpage.h"
#include "ui_userpage.h"
#include "adduserdialog.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QSqlQueryModel>

UserPage::UserPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserPage)
{
    ui->setupUi(this);

    // 初始化 TableView 模型
    model = new QSqlRelationalTableModel(this);
    model->setTable("users");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    // 设置列标题
    model->setHeaderData(model->fieldIndex("id"), Qt::Horizontal, "ID");
    model->setHeaderData(model->fieldIndex("username"), Qt::Horizontal, "用户名");
    model->setHeaderData(model->fieldIndex("role"), Qt::Horizontal, "角色");
    model->setHeaderData(model->fieldIndex("create_time"), Qt::Horizontal, "创建时间");

    // 隐藏密码列
    ui->tableView->setColumnHidden(model->fieldIndex("password"), true);

    // 默认加载所有用户
    loadUsers();

    ui->tableView->setModel(model);
}

UserPage::~UserPage()
{
    delete ui;
}

void UserPage::loadUsers()
{
    model->setFilter("");
    model->select();
}

void UserPage::on_addBtn_clicked()
{
    AddUserDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString username = dialog.getUsername();
        QString password = dialog.getPassword();
        QString role = dialog.getRole();

        if (username.isEmpty()) {
            QMessageBox::warning(this, "警告", "用户名不能为空！");
            return;
        }

        if (password.isEmpty()) {
            password = "123456";
        }

        QSqlQuery query;
        query.prepare(R"(
            INSERT INTO users (username, password, role)
            VALUES (:username, :password, :role)
        )");
        query.bindValue(":username", username);
        query.bindValue(":password", password);
        query.bindValue(":role", role);

        if (query.exec()) {
            QMessageBox::information(this, "成功", "用户添加成功！");
            loadUsers();
        } else {
            QMessageBox::critical(this, "错误", "添加失败：" + query.lastError().text());
        }
    }
}

void UserPage::on_editBtn_clicked()
{
    int row = ui->tableView->currentIndex().row();
    if (row < 0) {
        QMessageBox::warning(this, "提示", "请选择一行");
        return;
    }

    int userId = model->data(model->index(row, 0)).toInt();
    QString username = model->data(model->index(row, model->fieldIndex("username"))).toString();
    QString role = model->data(model->index(row, model->fieldIndex("role"))).toString();

    // 获取密码
    QString password = "";
    QSqlQuery query;
    query.prepare("SELECT password FROM users WHERE id = ?");
    query.addBindValue(userId);
    if (query.exec() && query.next()) {
        password = query.value(0).toString();
    }

    AddUserDialog dialog(this);
    dialog.setUserData(userId, username, password, role);

    if (dialog.exec() == QDialog::Accepted) {
        QString newUsername = dialog.getUsername();
        QString newPassword = dialog.getPassword();
        QString newRole = dialog.getRole();

        if (newUsername.isEmpty()) {
            QMessageBox::warning(this, "警告", "用户名不能为空！");
            return;
        }

        if (newPassword.isEmpty()) {
            newPassword = "123456";
        }

        query.prepare(R"(
            UPDATE users SET username = :username, password = :password, role = :role
            WHERE id = :id
        )");
        query.bindValue(":username", newUsername);
        query.bindValue(":password", newPassword);
        query.bindValue(":role", newRole);
        query.bindValue(":id", userId);

        if (query.exec()) {
            QMessageBox::information(this, "成功", "用户信息更新成功！");
            loadUsers();
        } else {
            QMessageBox::critical(this, "错误", "更新失败：" + query.lastError().text());
        }
    }
}

void UserPage::on_deleteBtn_clicked()
{
    int row = ui->tableView->currentIndex().row();
    if (row < 0) {
        QMessageBox::warning(this, "提示", "请选择一行");
        return;
    }

    int userId = model->data(model->index(row, 0)).toInt();
    QString username = model->data(model->index(row, model->fieldIndex("username"))).toString();

    if (QMessageBox::question(this, "确认删除", QString("确定要删除用户 %1 吗？").arg(username)) != QMessageBox::Yes) {
        return;
    }

    QSqlQuery query;
    query.prepare("DELETE FROM users WHERE id = ?");
    query.addBindValue(userId);

    if (query.exec()) {
        QMessageBox::information(this, "成功", "删除成功！");
        loadUsers();
    } else {
        QMessageBox::critical(this, "错误", "删除失败：" + query.lastError().text());
    }
}

void UserPage::on_searchBtn_clicked()
{
    QString key = ui->searchEdit->text().trimmed();
    if (key.isEmpty()) {
        loadUsers();
        ui->tableView->setModel(model);
        return;
    }
    
    QSqlQuery query;
    query.prepare("SELECT id, username, role, create_time FROM users WHERE username LIKE ?");
    query.addBindValue("%" + key + "%");
    
    if (query.exec()) {
        QSqlQueryModel *tempModel = new QSqlQueryModel(this);
        tempModel->setQuery(query);
        
        tempModel->setHeaderData(0, Qt::Horizontal, "ID");
        tempModel->setHeaderData(1, Qt::Horizontal, "用户名");
        tempModel->setHeaderData(2, Qt::Horizontal, "角色");
        tempModel->setHeaderData(3, Qt::Horizontal, "创建时间");
        
        ui->tableView->setModel(tempModel);
    } else {
        QMessageBox::critical(this, "错误", "搜索失败：" + query.lastError().text());
    }
}

void UserPage::on_resetPwdBtn_clicked()
{
    int row = ui->tableView->currentIndex().row();
    if (row < 0) {
        QMessageBox::warning(this, "提示", "请选择一行");
        return;
    }

    int userId = model->data(model->index(row, 0)).toInt();
    QString username = model->data(model->index(row, model->fieldIndex("username"))).toString();

    if (QMessageBox::question(this, "确认重置密码", QString("确定要将用户 %1 的密码重置为默认密码 123456 吗？").arg(username)) != QMessageBox::Yes) {
        return;
    }

    QSqlQuery query;
    query.prepare("UPDATE users SET password = '123456' WHERE id = ?");
    query.addBindValue(userId);

    if (query.exec()) {
        QMessageBox::information(this, "成功", "密码已重置为：123456");
    } else {
        QMessageBox::critical(this, "错误", "重置密码失败：" + query.lastError().text());
    }
}
