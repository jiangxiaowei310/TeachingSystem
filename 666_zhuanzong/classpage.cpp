#include "classpage.h"
#include "ui_classpage.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>

ClassPage::ClassPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClassPage)
{
    ui->setupUi(this);

    // 初始化 TableView 模型
    model = new QSqlRelationalTableModel(this);
    model->setTable("classes");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    // 设置关系（显示学院和专业名称而不是ID）
    model->setRelation(model->fieldIndex("college_id"), QSqlRelation("colleges", "college_id", "college_name"));
    model->setRelation(model->fieldIndex("major_id"), QSqlRelation("majors", "major_id", "major_name"));

    // 设置列标题
    model->setHeaderData(model->fieldIndex("class_id"), Qt::Horizontal, "班级ID");
    model->setHeaderData(model->fieldIndex("class_name"), Qt::Horizontal, "班级名称");
    model->setHeaderData(model->fieldIndex("class_code"), Qt::Horizontal, "班级代码");
    model->setHeaderData(model->fieldIndex("college_id"), Qt::Horizontal, "所属学院");
    model->setHeaderData(model->fieldIndex("major_id"), Qt::Horizontal, "所属专业");
    model->setHeaderData(model->fieldIndex("grade"), Qt::Horizontal, "年级");
    model->setHeaderData(model->fieldIndex("student_count"), Qt::Horizontal, "学生人数");

    // 默认加载所有班级
    loadClasses();

    ui->tableView->setModel(model);
}

ClassPage::~ClassPage()
{
    delete ui;
}

void ClassPage::loadClasses()
{
    model->setFilter("");
    model->select();
}

void ClassPage::on_addBtn_clicked()
{
    QMessageBox::information(this, "提示", "添加班级功能可后续扩展");
}

void ClassPage::on_editBtn_clicked()
{
    QMessageBox::information(this, "提示", "编辑功能可后续扩展");
}

void ClassPage::on_deleteBtn_clicked()
{
    int row = ui->tableView->currentIndex().row();
    if (row < 0) {
        QMessageBox::warning(this, "提示", "请选择一行");
        return;
    }

    int classId = model->data(model->index(row, 0)).toInt();
    QString className = model->data(model->index(row, model->fieldIndex("class_name"))).toString();

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
    QString key = ui->searchEdit->text();
    if (key.isEmpty()) {
        loadClasses();
        return;
    }
    model->setFilter(QString("class_name like '%%1%' or class_code like '%%1%'").arg(key));
    model->select();
}
