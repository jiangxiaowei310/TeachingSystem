#include "teacherpage.h"
#include "ui_teacherpage.h"
#include "addteacherdialog.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QDebug>

TeacherPage::TeacherPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeacherPage)
{
    ui->setupUi(this);

    // 初始化 TableView 模型
    model = new QSqlRelationalTableModel(this);
    model->setTable("teachers");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    // 设置关系（显示名称而不是ID）
    model->setRelation(model->fieldIndex("college_id"), QSqlRelation("colleges", "college_id", "college_name"));

    model->select();
    ui->tableView->setModel(model);
}

TeacherPage::~TeacherPage()
{
    delete ui;
}

void TeacherPage::loadTeachers()
{
    model->setFilter("");
    model->select();
}

void TeacherPage::on_addBtn_clicked()
{
    AddTeacherDialog dialog(this);
    if (dialog.exec() != QDialog::Accepted)
        return;

    QString teacherNo = dialog.getTeacherNo();
    QString name = dialog.getName();
    QString gender = dialog.getGender();
    int collegeId = dialog.getCollegeId();
    QString phone = dialog.getPhone();
    QString email = dialog.getEmail();

    // 使用工号作为用户名，默认密码123456
    QString username = teacherNo;
    QString password = "123456";

    if (teacherNo.isEmpty() || name.isEmpty()) {
        QMessageBox::warning(this, "警告", "工号和姓名不能为空！");
        return;
    }

    // 调试输出
    qDebug() << "teacherNo:" << teacherNo;
    qDebug() << "name:" << name;
    qDebug() << "collegeId:" << collegeId;
    qDebug() << "email:" << email;

    QSqlDatabase db = QSqlDatabase::database();
    db.transaction();

    // 插入 users 表
    QSqlQuery query;
    query.prepare(R"(
        INSERT INTO users (username, password, role, create_time)
        VALUES (:username, :password, 'teacher', NOW())
    )");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (!query.exec()) {
        qDebug() << "Users SQL Error:" << query.lastError().text();
        db.rollback();
        QMessageBox::critical(this, "错误", "创建账号失败：\n" + query.lastError().text());
        return;
    }

    int userId = query.lastInsertId().toInt();
    qDebug() << "Inserted user id:" << userId;

    // 插入 teachers 表（使用正确的字段名 tea_no）
    query.prepare(R"(
        INSERT INTO teachers (user_id, tea_no, name, gender, college_id, phone, email)
        VALUES (:uid, :tno, :name, :gender, :cid, :phone, :email)
    )");
    query.bindValue(":uid", userId);
    query.bindValue(":tno", teacherNo);
    query.bindValue(":name", name);
    query.bindValue(":gender", gender);
    query.bindValue(":cid", collegeId);
    query.bindValue(":phone", phone);
    query.bindValue(":email", email);

    if (!query.exec()) {
        qDebug() << "Teachers SQL Error:" << query.lastError().text();
        db.rollback();
        QMessageBox::critical(this, "错误", "添加教师失败：\n" + query.lastError().text());
        return;
    }

    db.commit();
    QMessageBox::information(this, "成功", "教师添加成功！\n用户名：" + username + "\n密码：123456");
    loadTeachers();
}

void TeacherPage::on_editBtn_clicked()
{
    QMessageBox::information(this, "提示", "编辑功能可后续扩展");
}

void TeacherPage::on_deleteBtn_clicked()
{
    int row = ui->tableView->currentIndex().row();
    if (row < 0) {
        QMessageBox::warning(this, "提示", "请选择一行");
        return;
    }

    int userId = model->data(model->index(row, 1)).toInt(); // user_id 在第2列(index=1)
    QSqlDatabase db = QSqlDatabase::database();
    db.transaction();

    QSqlQuery q;
    q.prepare("DELETE FROM teachers WHERE user_id = ?");
    q.addBindValue(userId);
    q.exec();

    q.prepare("DELETE FROM users WHERE id = ?");
    q.addBindValue(userId);
    q.exec();

    db.commit();
    loadTeachers();
}

void TeacherPage::on_searchBtn_clicked()
{
    QString key = ui->searchEdit->text();
    if (key.isEmpty()) {
        loadTeachers();
        return;
    }
    model->setFilter(QString("name like '%%1%' or tea_no like '%%1%'").arg(key));
    model->select();
}
