#include "collegepage.h"
#include "ui_collegepage.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>

CollegePage::CollegePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CollegePage)
{
    ui->setupUi(this);

    // 初始化 TableView 模型
    model = new QSqlRelationalTableModel(this);
    model->setTable("colleges");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    // 设置列标题
    model->setHeaderData(model->fieldIndex("college_id"), Qt::Horizontal, "学院ID");
    model->setHeaderData(model->fieldIndex("college_name"), Qt::Horizontal, "学院名称");
    model->setHeaderData(model->fieldIndex("college_code"), Qt::Horizontal, "学院代码");
    model->setHeaderData(model->fieldIndex("dean"), Qt::Horizontal, "院长");
    model->setHeaderData(model->fieldIndex("phone"), Qt::Horizontal, "联系电话");

    // 默认加载所有学院
    loadColleges();

    ui->tableView->setModel(model);
}

CollegePage::~CollegePage()
{
    delete ui;
}

void CollegePage::loadColleges()
{
    model->setFilter("");
    model->select();
}

void CollegePage::on_addBtn_clicked()
{
    QMessageBox::information(this, "提示", "添加学院功能可后续扩展");
}

void CollegePage::on_editBtn_clicked()
{
    QMessageBox::information(this, "提示", "编辑功能可后续扩展");
}

void CollegePage::on_deleteBtn_clicked()
{
    int row = ui->tableView->currentIndex().row();
    if (row < 0) {
        QMessageBox::warning(this, "提示", "请选择一行");
        return;
    }

    int collegeId = model->data(model->index(row, 0)).toInt();
    QString collegeName = model->data(model->index(row, model->fieldIndex("college_name"))).toString();

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
    QString key = ui->searchEdit->text();
    if (key.isEmpty()) {
        loadColleges();
        return;
    }
    model->setFilter(QString("college_name like '%%1%' or college_code like '%%1%'").arg(key));
    model->select();
}
