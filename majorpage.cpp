#include "majorpage.h"
#include "ui_majorpage.h"
#include "addmajordialog.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QSqlQueryModel>

MajorPage::MajorPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MajorPage)
{
    ui->setupUi(this);

    // 初始化 TableView 模型
    model = new QSqlQueryModel(this);

    currentPage = 1;
    pageSize = 20;
    totalRecords = 0;
    totalPages = 0;

    loadMajors();
}

MajorPage::~MajorPage()
{
    delete ui;
}

void MajorPage::loadMajors()
{
    QSqlQuery countQuery;
    countQuery.exec("SELECT COUNT(*) FROM majors");

    if(countQuery.next())
    {
        totalRecords = countQuery.value(0).toInt();
    }

    totalPages = (totalRecords + pageSize - 1) / pageSize;

    if(totalPages == 0)
        totalPages = 1;

    if(currentPage > totalPages)
        currentPage = totalPages;

    if(currentPage < 1)
        currentPage = 1;

    int offset = (currentPage - 1) * pageSize;

    QSqlQuery query;
    query.prepare(R"(
        SELECT
            m.major_id,
            m.major_name,
            c.college_name
        FROM majors m
        LEFT JOIN colleges c ON m.college_id = c.college_id
        LIMIT :offset,:size
    )");
    query.bindValue(":offset", offset);
    query.bindValue(":size", pageSize);
    query.exec();

    model->setQuery(std::move(query));

    model->setHeaderData(0, Qt::Horizontal, "专业ID");
    model->setHeaderData(1, Qt::Horizontal, "专业名称");
    model->setHeaderData(2, Qt::Horizontal, "所属学院");

    ui->tableView->setModel(model);

    ui->totalLabel->setText(QString("共 %1 条").arg(totalRecords));
    ui->pageLabel->setText(QString("%1 / %2").arg(currentPage).arg(totalPages));
}

void MajorPage::on_addBtn_clicked()
{
    AddMajorDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString majorName = dialog.getMajorName();
        int collegeId = dialog.getCollegeId();

        if (majorName.isEmpty()) {
            QMessageBox::warning(this, "警告", "专业名称不能为空！");
            return;
        }

        QSqlQuery query;
        query.prepare(R"(
            INSERT INTO majors (major_name, college_id)
            VALUES (:name, :cid)
        )");
        query.bindValue(":name", majorName);
        query.bindValue(":cid", collegeId);

        if (query.exec()) {
            QMessageBox::information(this, "成功", "专业添加成功！");
            loadMajors();
        } else {
            QMessageBox::critical(this, "错误", "添加失败：" + query.lastError().text());
        }
    }
}

void MajorPage::on_editBtn_clicked()
{
    int row = ui->tableView->currentIndex().row();
    if (row < 0) {
        QMessageBox::warning(this, "提示", "请选择一行");
        return;
    }

    int majorId = model->data(model->index(row, 0)).toInt();
    QString majorName = model->data(model->index(row, 1)).toString();

    // 获取原始college_id
    int collegeId = -1;
    QSqlQuery query;
    query.prepare("SELECT college_id FROM majors WHERE major_id = ?");
    query.addBindValue(majorId);
    if (query.exec() && query.next()) {
        collegeId = query.value(0).toInt();
    }

    AddMajorDialog dialog(this);
    dialog.setMajorData(majorId, majorName, "", collegeId);

    if (dialog.exec() == QDialog::Accepted) {
        QString newName = dialog.getMajorName();
        int newCollegeId = dialog.getCollegeId();

        if (newName.isEmpty()) {
            QMessageBox::warning(this, "警告", "专业名称不能为空！");
            return;
        }

        query.prepare(R"(
            UPDATE majors SET major_name = :name, college_id = :cid
            WHERE major_id = :id
        )");
        query.bindValue(":name", newName);
        query.bindValue(":cid", newCollegeId);
        query.bindValue(":id", majorId);

        if (query.exec()) {
            QMessageBox::information(this, "成功", "专业信息更新成功！");
            loadMajors();
        } else {
            QMessageBox::critical(this, "错误", "更新失败：" + query.lastError().text());
        }
    }
}

void MajorPage::on_deleteBtn_clicked()
{
    int row =
        ui->tableView->currentIndex().row();

    if(row < 0)
    {
        QMessageBox::warning(
            this,
            "提示",
            "请选择一行");
        return;
    }

    int majorId =
        model->data(
                 model->index(row,0))
            .toInt();

    QString majorName =
        model->data(
                 model->index(row,1))
            .toString();

    int ret =
        QMessageBox::question(
            this,
            "确认删除",
            QString("确定删除专业【%1】吗？")
                .arg(majorName),
            QMessageBox::Yes |
                QMessageBox::No);

    if(ret != QMessageBox::Yes)
        return;

    QSqlQuery query;

    query.prepare(
        "DELETE FROM majors "
        "WHERE major_id = ?");

    query.addBindValue(majorId);

    if(query.exec())
    {
        QMessageBox::information(
            this,
            "成功",
            "专业删除成功！");

        loadMajors();
    }
    else
    {
        QMessageBox::critical(
            this,
            "错误",
            "删除失败：\n"
                + query.lastError().text());
    }
}

void MajorPage::on_searchBtn_clicked()
{
    QString key = ui->searchEdit->text().trimmed();
    if (key.isEmpty()) {
        loadMajors();
        return;
    }

    QSqlQuery query;
    query.prepare(R"(
        SELECT
            m.major_id,
            m.major_name,
            c.college_name
        FROM majors m
        LEFT JOIN colleges c ON m.college_id = c.college_id
        WHERE m.major_name LIKE :key
    )");
    query.bindValue(":key", "%" + key + "%");
    query.exec();

    model->setQuery(std::move(query));

    model->setHeaderData(0, Qt::Horizontal, "专业ID");
    model->setHeaderData(1, Qt::Horizontal, "专业名称");
    model->setHeaderData(2, Qt::Horizontal, "所属学院");

    ui->tableView->setModel(model);
}

void MajorPage::on_prevBtn_clicked()
{
    if (currentPage > 1) {
        currentPage--;
        loadMajors();
    }
}

void MajorPage::on_nextBtn_clicked()
{
    if (currentPage < totalPages) {
        currentPage++;
        loadMajors();
    }
}

void MajorPage::on_pageSizeCombo_currentIndexChanged(const QString &text)
{
    pageSize = text.toInt();
    currentPage = 1;
    loadMajors();
}
