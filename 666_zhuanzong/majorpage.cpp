#include "majorpage.h"
#include "ui_majorpage.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>

MajorPage::MajorPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MajorPage)
{
    ui->setupUi(this);

    // 初始化 TableView 模型
    model = new QSqlRelationalTableModel(this);
    model->setTable("majors");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    // 设置关系（显示学院名称而不是ID）
    model->setRelation(model->fieldIndex("college_id"), QSqlRelation("colleges", "college_id", "college_name"));

    // 设置列标题
    model->setHeaderData(model->fieldIndex("major_id"), Qt::Horizontal, "专业ID");
    model->setHeaderData(model->fieldIndex("major_name"), Qt::Horizontal, "专业名称");
    model->setHeaderData(model->fieldIndex("major_code"), Qt::Horizontal, "专业代码");
    model->setHeaderData(model->fieldIndex("college_id"), Qt::Horizontal, "所属学院");

    // 默认加载所有专业
    loadMajors();

    ui->tableView->setModel(model);
}

MajorPage::~MajorPage()
{
    delete ui;
}

void MajorPage::loadMajors()
{
    model->setFilter("");
    model->select();
}

void MajorPage::on_addBtn_clicked()
{
    QMessageBox::information(this, "提示", "添加专业功能可后续扩展");
}

void MajorPage::on_editBtn_clicked()
{
    QMessageBox::information(this, "提示", "编辑功能可后续扩展");
}

void MajorPage::on_deleteBtn_clicked()
{
    int row = ui->tableView->currentIndex().row();
    if (row < 0) {
        QMessageBox::warning(this, "提示", "请选择一行");
        return;
    }

    int majorId = model->data(model->index(row, 0)).toInt();
    QString majorName = model->data(model->index(row, model->fieldIndex("major_name"))).toString();

    if (QMessageBox::question(this, "确认删除", QString("确定要删除专业 %1 吗？").arg(majorName)) != QMessageBox::Yes) {
        return;
    }

    QSqlQuery query;
    query.prepare("DELETE FROM majors WHERE major_id = ?");
    query.addBindValue(majorId);

    if (query.exec()) {
        QMessageBox::information(this, "成功", "删除成功！");
        loadMajors();
    } else {
        QMessageBox::critical(this, "错误", "删除失败：" + query.lastError().text());
    }
}

void MajorPage::on_searchBtn_clicked()
{
    QString key = ui->searchEdit->text();
    if (key.isEmpty()) {
        loadMajors();
        return;
    }
    model->setFilter(QString("major_name like '%%1%' or major_code like '%%1%'").arg(key));
    model->select();
}
