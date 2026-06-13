#include "classpage.h"
#include "ui_classpage.h"
#include "addclassdialog.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QSqlQueryModel>

ClassPage::ClassPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClassPage)
{
    ui->setupUi(this);

    // 初始化 TableView 模型
    model = new QSqlQueryModel(this);

    currentPage = 1;
    pageSize = 20;
    totalRecords = 0;
    totalPages = 0;

    loadClasses();
}

ClassPage::~ClassPage()
{
    delete ui;
}

void ClassPage::loadClasses()
{
    // 总记录数
    QSqlQuery countQuery;
    countQuery.exec("SELECT COUNT(*) FROM classes");

    if(countQuery.next())
    {
        totalRecords = countQuery.value(0).toInt();
    }

    // 总页数
    totalPages =
        (totalRecords + pageSize - 1)
        / pageSize;

    if(totalPages == 0)
        totalPages = 1;

    if(currentPage > totalPages)
        currentPage = totalPages;

    if(currentPage < 1)
        currentPage = 1;

    int offset =
        (currentPage - 1) * pageSize;

    QSqlQuery query;

    query.prepare(R"(
        SELECT
            c.class_id,
            c.class_name,
            col.college_name,
            m.major_name,
            c.grade
        FROM classes c
        LEFT JOIN colleges col
            ON c.college_id = col.college_id
        LEFT JOIN majors m
            ON c.major_id = m.major_id
        LIMIT :offset,:size
    )");

    query.bindValue(":offset", offset);
    query.bindValue(":size", pageSize);

    query.exec();

    model->setQuery(std::move(query));

    model->setHeaderData(0,Qt::Horizontal,"班级ID");
    model->setHeaderData(1,Qt::Horizontal,"班级名称");
    model->setHeaderData(2,Qt::Horizontal,"所属学院");
    model->setHeaderData(3,Qt::Horizontal,"所属专业");
    model->setHeaderData(4,Qt::Horizontal,"年级");

    ui->tableView->setModel(model);

    ui->totalLabel->setText(
        QString("共 %1 条")
            .arg(totalRecords));

    ui->pageLabel->setText(
        QString("%1 / %2")
            .arg(currentPage)
            .arg(totalPages));
}

void ClassPage::on_addBtn_clicked()
{
    AddClassDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString className = dialog.getClassName();
        QString grade = dialog.getGrade();
        int majorId = dialog.getMajorId();
        int collegeId = dialog.getCollegeId();

        if (className.isEmpty()) {
            QMessageBox::warning(this, "警告", "班级名称不能为空！");
            return;
        }

        QSqlQuery query;
        query.prepare(R"(
            INSERT INTO classes (class_name, grade, college_id, major_id)
            VALUES (:name, :grade, :cid, :mid)
        )");
        query.bindValue(":name", className);
        query.bindValue(":grade", grade);
        query.bindValue(":cid", collegeId);
        query.bindValue(":mid", majorId);

        if (query.exec()) {
            QMessageBox::information(this, "成功", "班级添加成功！");
            loadClasses();
        } else {
            QMessageBox::critical(this, "错误", "添加失败：" + query.lastError().text());
        }
    }
}


void ClassPage::on_editBtn_clicked()
{
    int row = ui->tableView->currentIndex().row();
    if (row < 0) {
        QMessageBox::warning(this, "提示", "请选择一行");
        return;
    }

    int classId = model->data(model->index(row, 0)).toInt();
    QString className =
        model->data(model->index(row,1)).toString();
    QString grade =
        model->data(model->index(row,4)).toString();

    // 获取原始college_id和major_id
    int collegeId = -1, majorId = -1;
    QSqlQuery query;
    query.prepare("SELECT college_id, major_id FROM classes WHERE class_id = ?");
    query.addBindValue(classId);
    if (query.exec() && query.next()) {
        collegeId = query.value(0).toInt();
        majorId = query.value(1).toInt();
    }

    AddClassDialog dialog(this);
    dialog.setClassData(classId, className, "", grade, majorId, collegeId);

    if (dialog.exec() == QDialog::Accepted) {
        QString newName = dialog.getClassName();
        QString newGrade = dialog.getGrade();
        int newMajorId = dialog.getMajorId();
        int newCollegeId = dialog.getCollegeId();

        if (newName.isEmpty()) {
            QMessageBox::warning(this, "警告", "班级名称不能为空！");
            return;
        }

        query.prepare(R"(
            UPDATE classes SET class_name = :name, grade = :grade,
                            college_id = :cid, major_id = :mid
            WHERE class_id = :id
        )");
        query.bindValue(":name", newName);
        query.bindValue(":grade", newGrade);
        query.bindValue(":cid", newCollegeId);
        query.bindValue(":mid", newMajorId);
        query.bindValue(":id", classId);

        if (query.exec()) {
            QMessageBox::information(this, "成功", "班级信息更新成功！");
            loadClasses();
        } else {
            QMessageBox::critical(this, "错误", "更新失败：" + query.lastError().text());
        }
    }
}

void ClassPage::on_deleteBtn_clicked()
{
    int row = ui->tableView->currentIndex().row();
    if (row < 0) {
        QMessageBox::warning(this, "提示", "请选择一行");
        return;
    }

    int classId = model->data(model->index(row, 0)).toInt();
    QString className =
        model->data(model->index(row,1)).toString();

    if (QMessageBox::question(this, "确认删除", QString("确定要删除班级 %1 吗？").arg(className)) != QMessageBox::Yes) {
        return;
    }

    QSqlQuery query;
    query.prepare("DELETE FROM classes WHERE class_id = ?");
    query.addBindValue(classId);

    if (query.exec()) {
        QMessageBox::information(this, "成功", "删除成功！");
        loadClasses();
    } else {
        QMessageBox::critical(this, "错误", "删除失败：" + query.lastError().text());
    }
}

void ClassPage::on_searchBtn_clicked()
{
    QString key =
        ui->searchEdit->text().trimmed();

    if(key.isEmpty())
    {
        loadClasses();
        return;
    }

    QSqlQuery query;

    query.prepare(R"(
        SELECT
            c.class_id,
            c.class_name,
            col.college_name,
            m.major_name,
            c.grade
        FROM classes c
        LEFT JOIN colleges col
            ON c.college_id = col.college_id
        LEFT JOIN majors m
            ON c.major_id = m.major_id
        WHERE c.class_name LIKE :key
    )");

    query.bindValue(":key",
                    "%" + key + "%");

    query.exec();

    model->setQuery(std::move(query));

    model->setHeaderData(0,Qt::Horizontal,"班级ID");
    model->setHeaderData(1,Qt::Horizontal,"班级名称");
    model->setHeaderData(2,Qt::Horizontal,"所属学院");
    model->setHeaderData(3,Qt::Horizontal,"所属专业");
    model->setHeaderData(4,Qt::Horizontal,"年级");

    ui->tableView->setModel(model);
}

void ClassPage::on_prevBtn_clicked()
{
    if (currentPage > 1) {
        currentPage--;
        loadClasses();
    }
}

void ClassPage::on_nextBtn_clicked()
{
    if (currentPage < totalPages) {
        currentPage++;
        loadClasses();
    }
}

void ClassPage::on_pageSizeCombo_currentIndexChanged(const QString &text)
{
    pageSize = text.toInt();
    currentPage = 1;
    loadClasses();
}
