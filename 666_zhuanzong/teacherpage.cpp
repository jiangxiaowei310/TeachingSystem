#include "teacherpage.h"
#include "ui_teacherpage.h"
#include "addteacherdialog.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlRecord>
TeacherPage::TeacherPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeacherPage)
{
    ui->setupUi(this);

    // 初始化 TableView 模型
    model = new QSqlQueryModel(this);

    currentPage = 1;
    pageSize = 20;

    loadTeachers();
}

TeacherPage::~TeacherPage()
{
    delete ui;
}

void TeacherPage::loadTeachers()
{
    QSqlQuery countQuery;

    countQuery.exec(
        "SELECT COUNT(*) FROM teachers");

    if(countQuery.next())
    {
        totalRecords =
            countQuery.value(0).toInt();
    }

    totalPages =
        (totalRecords + pageSize - 1)
        / pageSize;

    if(totalPages <= 0)
    {
        totalPages = 1;
    }

    if(currentPage > totalPages)
    {
        currentPage = totalPages;
    }

    if(currentPage < 1)
    {
        currentPage = 1;
    }

    int offset =
        (currentPage - 1) * pageSize;

    QSqlQuery query;

    query.prepare(R"(
        SELECT
            t.teacher_id,
            t.user_id,
            t.tea_no,
            t.name,
            t.gender,
            c.college_name,
            t.phone,
            t.email
        FROM teachers t
        LEFT JOIN colleges c
        ON t.college_id = c.college_id
        LIMIT :offset,:size
    )");

    query.bindValue(":offset", offset);
    query.bindValue(":size", pageSize);

    query.exec();

    model->setQuery(std::move(query));

    ui->tableView->setModel(model);

    ui->totalLabel->setText(
        QString("共 %1 条")
            .arg(totalRecords));

    ui->pageLabel->setText(
        QString("%1 / %2")
            .arg(currentPage)
            .arg(totalPages));
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
    int row = ui->tableView->currentIndex().row();

    if(row < 0)
    {
        QMessageBox::warning(
            this,
            "提示",
            "请选择一行");
        return;
    }

    // 获取教师信息
    int userId =
        model->data(model->index(row,1)).toInt();

    QString teacherNo =
        model->data(model->index(row,2)).toString();

    QString name =
        model->data(model->index(row,3)).toString();

    QString gender =
        model->data(model->index(row,4)).toString();

    QString phone =
        model->data(model->index(row,6)).toString();

    QString email =
        model->data(model->index(row,7)).toString();

    // 获取学院ID
    int collegeId = -1;

    QSqlQuery query;

    query.prepare(
        "SELECT college_id "
        "FROM teachers "
        "WHERE user_id = ?");

    query.addBindValue(userId);

    if(query.exec() && query.next())
    {
        collegeId =
            query.value(0).toInt();
    }

    AddTeacherDialog dialog(this);

    dialog.setTeacherData(
        userId,
        teacherNo,
        name,
        gender,
        "",
        collegeId,
        phone,
        email);

    if(dialog.exec() == QDialog::Accepted)
    {
        QString newName =
            dialog.getName();

        QString newGender =
            dialog.getGender();

        int newCollegeId =
            dialog.getCollegeId();

        QString newPhone =
            dialog.getPhone();

        QString newEmail =
            dialog.getEmail();

        QSqlDatabase db =
            QSqlDatabase::database();

        db.transaction();

        query.prepare(R"(
            UPDATE teachers
            SET
                name = :name,
                gender = :gender,
                college_id = :cid,
                phone = :phone,
                email = :email
            WHERE user_id = :uid
        )");

        query.bindValue(":name",newName);
        query.bindValue(":gender",newGender);
        query.bindValue(":cid",newCollegeId);
        query.bindValue(":phone",newPhone);
        query.bindValue(":email",newEmail);
        query.bindValue(":uid",userId);

        if(!query.exec())
        {
            db.rollback();

            QMessageBox::critical(
                this,
                "错误",
                "更新教师信息失败："
                    + query.lastError().text());

            return;
        }

        db.commit();

        QMessageBox::information(
            this,
            "成功",
            "教师信息更新成功！");

        loadTeachers();
    }
}

void TeacherPage::on_deleteBtn_clicked()
{
    int row = ui->tableView->currentIndex().row();

    if (row < 0)
    {
        QMessageBox::warning(this, "提示", "请选择一名教师");
        return;
    }

    int userId =
        model->data(
                model->index(row,1))
                .toInt();

    QString teacherName =
            model->data(
            model->index(row,3))
            .toString();

    int ret = QMessageBox::question(
        this,
        "确认删除",
        QString("确定删除教师【%1】吗？").arg(teacherName),
        QMessageBox::Yes | QMessageBox::No
        );

    if (ret != QMessageBox::Yes)
        return;

    QSqlDatabase db = QSqlDatabase::database();

    if (!db.transaction())
    {
        QMessageBox::critical(this, "错误", "开启事务失败");
        return;
    }

    QSqlQuery q;

    // 删除教师信息
    q.prepare("DELETE FROM teachers WHERE user_id = ?");
    q.addBindValue(userId);

    if (!q.exec())
    {
        db.rollback();

        QMessageBox::critical(
            this,
            "删除失败",
            "删除教师信息失败：\n" + q.lastError().text()
            );

        return;
    }

    // 删除登录账号
    q.prepare("DELETE FROM users WHERE id = ?");
    q.addBindValue(userId);

    if (!q.exec())
    {
        db.rollback();

        QMessageBox::critical(
            this,
            "删除失败",
            "删除用户信息失败：\n" + q.lastError().text()
            );

        return;
    }

    db.commit();

    QMessageBox::information(
        this,
        "成功",
        "教师删除成功！"
        );

    loadTeachers();
}

void TeacherPage::on_searchBtn_clicked()
{
    QString key =
        ui->searchEdit->text().trimmed();

    if(key.isEmpty())
    {
        loadTeachers();
        return;
    }

    QSqlQuery query;

    query.prepare(R"(
        SELECT
            t.teacher_id,
            t.user_id,
            t.tea_no,
            t.name,
            t.gender,
            c.college_name,
            t.phone,
            t.email
        FROM teachers t
        LEFT JOIN colleges c
        ON t.college_id = c.college_id
        WHERE
            t.name LIKE :key
            OR t.tea_no LIKE :key
    )");

    query.bindValue(
        ":key",
        "%" + key + "%");

    query.exec();

    model->setQuery(std::move(query));

    ui->tableView->setModel(model);
}
