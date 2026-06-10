#include "collegepage.h"
#include "ui_collegepage.h"
#include "addcollegedialog.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QSqlQueryModel>

CollegePage::CollegePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CollegePage)
{
    ui->setupUi(this);

    model = new QSqlQueryModel(this);

    currentPage = 1;
    pageSize = 20;

    totalRecords = 0;
    totalPages = 0;

    loadColleges();
}

CollegePage::~CollegePage()
{
    delete ui;
}

void CollegePage::loadColleges()
{
    QSqlQuery countQuery;

    countQuery.exec(
        "SELECT COUNT(*) FROM colleges");

    if(countQuery.next())
    {
        totalRecords =
            countQuery.value(0).toInt();
    }

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
            college_id,
            college_name
        FROM colleges
        LIMIT :offset,:size
    )");

    query.bindValue(":offset",offset);
    query.bindValue(":size",pageSize);

    query.exec();

    model->setQuery(std::move(query));

    model->setHeaderData(
        0,
        Qt::Horizontal,
        "学院ID");

    model->setHeaderData(
        1,
        Qt::Horizontal,
        "学院名称");

    ui->tableView->setModel(model);

    ui->totalLabel->setText(
        QString("共 %1 条")
            .arg(totalRecords));

    ui->pageLabel->setText(
        QString("%1 / %2")
            .arg(currentPage)
            .arg(totalPages));
}


void CollegePage::on_addBtn_clicked()
{
    AddCollegeDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString collegeName = dialog.getCollegeName();

        if (collegeName.isEmpty()) {
            QMessageBox::warning(this, "警告", "学院名称不能为空！");
            return;
        }

        QSqlQuery query;
        query.prepare(R"(
            INSERT INTO colleges (college_name)
            VALUES (:name)
        )");
        query.bindValue(":name", collegeName);

        if (query.exec()) {
            QMessageBox::information(this, "成功", "学院添加成功！");
            loadColleges();
        } else {
            QMessageBox::critical(this, "错误", "添加失败：" + query.lastError().text());
        }
    }
}

void CollegePage::on_editBtn_clicked()
{
    int row = ui->tableView->currentIndex().row();
    if (row < 0) {
        QMessageBox::warning(this, "提示", "请选择一行");
        return;
    }

    int collegeId = model->data(model->index(row, 0)).toInt();
    QString collegeName =model->data(model->index(row,1)).toString();

    AddCollegeDialog dialog(this);
    dialog.setCollegeData(collegeId, collegeName, "", "", "");

    if (dialog.exec() == QDialog::Accepted) {
        QString newName = dialog.getCollegeName();

        if (newName.isEmpty()) {
            QMessageBox::warning(this, "警告", "学院名称不能为空！");
            return;
        }

        QSqlQuery query;
        query.prepare(R"(
            UPDATE colleges SET college_name = :name
            WHERE college_id = :id
        )");
        query.bindValue(":name", newName);
        query.bindValue(":id", collegeId);

        if (query.exec()) {
            QMessageBox::information(this, "成功", "学院信息更新成功！");
            loadColleges();
        } else {
            QMessageBox::critical(this, "错误", "更新失败：" + query.lastError().text());
        }
    }
}

void CollegePage::on_deleteBtn_clicked()
{
    int row = ui->tableView->currentIndex().row();
    if (row < 0) {
        QMessageBox::warning(this, "提示", "请选择一行");
        return;
    }

    int collegeId = model->data(model->index(row, 0)).toInt();
    QString collegeName =model->data(model->index(row,1)).toString();

    if (QMessageBox::question(this, "确认删除", QString("确定要删除学院 %1 吗？").arg(collegeName)) != QMessageBox::Yes) {
        return;
    }

    QSqlQuery query;
    query.prepare("DELETE FROM colleges WHERE college_id = ?");
    query.addBindValue(collegeId);

    if (query.exec()) {
        QMessageBox::information(this, "成功", "删除成功！");
        loadColleges();
    } else {
        QMessageBox::critical(this, "错误", "删除失败：" + query.lastError().text());
    }
}

void CollegePage::on_searchBtn_clicked()
{
    QString key =
        ui->searchEdit->text().trimmed();

    if(key.isEmpty())
    {
        loadColleges();
        return;
    }

    QSqlQuery query;

    query.prepare(R"(
        SELECT
            college_id,
            college_name
        FROM colleges
        WHERE college_name LIKE :key
    )");

    query.bindValue(
        ":key",
        "%" + key + "%");

    query.exec();

    model->setQuery(std::move(query));

    model->setHeaderData(
        0,
        Qt::Horizontal,
        "学院ID");

    model->setHeaderData(
        1,
        Qt::Horizontal,
        "学院名称");

    ui->tableView->setModel(model);
}

