#include "userpage.h"
#include "ui_userpage.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>

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
    QMessageBox::information(this, "提示", "添加用户功能可后续扩展");
}

void UserPage::on_editBtn_clicked()
{
    QMessageBox::information(this, "提示", "编辑功能可后续扩展");
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
    QString key = ui->searchEdit->text();
    if (key.isEmpty()) {
        loadUsers();
        return;
    }
    model->setFilter(QString("username like '%%1%'").arg(key));
    model->select();
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
