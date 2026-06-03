#include "studentpage.h"
#include "ui_studentpage.h"
#include "addstudentdialog.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>

StudentPage::StudentPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentPage)
{
    ui->setupUi(this);

    // 初始化 TableView 模型
    model = new QSqlRelationalTableModel(this);
    model->setTable("students");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    // 设置关系（显示名称而不是ID）
    model->setRelation(model->fieldIndex("college_id"), QSqlRelation("colleges", "college_id", "college_name"));
    model->setRelation(model->fieldIndex("major_id"), QSqlRelation("majors", "major_id", "major_name"));
    model->setRelation(model->fieldIndex("class_id"), QSqlRelation("classes", "class_id", "class_name"));

    model->select();
    ui->tableView->setModel(model);
}

StudentPage::~StudentPage()
{
    delete ui;
}

// 刷新表格
void StudentPage::loadStudents()
{
    model->setFilter("");
    model->select();
}

// 添加学生
void StudentPage::on_addBtn_clicked()
{
    AddStudentDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString stuNo = dialog.getStuNo();
        QString name = dialog.getName();
        QString gender = dialog.getGender();
        int collegeId = dialog.getCollegeId();
        int majorId = dialog.getMajorId();
        int classId = dialog.getClassId();
        QString grade = dialog.getGrade();
        QString phone = dialog.getPhone();
        QString email = dialog.getEmail();

        // 使用学号作为用户名，默认密码123456
        QString username = stuNo;
        QString password = "123456";

        if (stuNo.isEmpty() || name.isEmpty()) {
            QMessageBox::warning(this, "警告", "学号和姓名不能为空！");
            return;
        }

        QSqlDatabase db = QSqlDatabase::database();
        db.transaction();

        // 插入 users
        QSqlQuery query;
        query.prepare(R"(
            INSERT INTO users (username, password, role, create_time)
            VALUES (:username, :password, 'student', NOW())
        )");
        query.bindValue(":username", username);
        query.bindValue(":password", password);

        if (!query.exec()) {
            db.rollback();
            QMessageBox::critical(this, "错误", "创建账号失败：" + query.lastError().text());
            return;
        }

        int userId = query.lastInsertId().toInt();

        // 插入 students
        query.prepare(R"(
            INSERT INTO students (user_id, stu_no, name, gender, college_id, major_id, class_id, grade, phone, email)
            VALUES (:uid, :sno, :name, :gender, :cid, :mid, :clid, :grade, :phone, :email)
        )");
        query.bindValue(":uid", userId);
        query.bindValue(":sno", stuNo);
        query.bindValue(":name", name);
        query.bindValue(":gender", gender);
        query.bindValue(":cid", collegeId);
        query.bindValue(":mid", majorId);
        query.bindValue(":clid", classId);
        query.bindValue(":grade", grade);
        query.bindValue(":phone", phone);
        query.bindValue(":email", email);

        if (!query.exec()) {
            db.rollback();
            QMessageBox::critical(this, "错误", "添加学生失败：" + query.lastError().text());
            return;
        }

        db.commit();
        QMessageBox::information(this, "成功", "学生添加成功！\n用户名：" + username + "\n密码：123456");
        loadStudents();
    }
}

// 编辑
void StudentPage::on_editBtn_clicked()
{
    QMessageBox::information(this, "提示", "编辑功能可后续扩展");
}

// 删除
void StudentPage::on_deleteBtn_clicked()
{
    int row = ui->tableView->currentIndex().row();
    if (row < 0) {
        QMessageBox::warning(this, "提示", "请选择一行");
        return;
    }

    int userId = model->data(model->index(row, 0)).toInt();
    QSqlDatabase db = QSqlDatabase::database();
    db.transaction();

    QSqlQuery q;
    q.prepare("DELETE FROM students WHERE user_id = ?");
    q.addBindValue(userId);
    q.exec();

    q.prepare("DELETE FROM users WHERE id = ?");
    q.addBindValue(userId);
    q.exec();

    db.commit();
    loadStudents();
}

// 搜索
void StudentPage::on_searchBtn_clicked()
{
    QString key = ui->searchEdit->text();
    if (key.isEmpty()) {
        loadStudents();
        return;
    }
    model->setFilter(QString("name like '%%1%' or stu_no like '%%1%'").arg(key));
    model->select();
}
