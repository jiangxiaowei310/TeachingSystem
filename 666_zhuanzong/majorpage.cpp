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
    AddMajorDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString majorName = dialog.getMajorName();
        QString majorCode = dialog.getMajorCode();
        int collegeId = dialog.getCollegeId();

        if (majorName.isEmpty()) {
            QMessageBox::warning(this, "警告", "专业名称不能为空！");
            return;
        }

        QSqlQuery query;
        query.prepare(R"(
            INSERT INTO majors (major_name, major_code, college_id)
            VALUES (:name, :code, :cid)
        )");
        query.bindValue(":name", majorName);
        query.bindValue(":code", majorCode);
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
    QString majorName = model->data(model->index(row, model->fieldIndex("major_name"))).toString();
    QString majorCode = model->data(model->index(row, model->fieldIndex("major_code"))).toString();

    // 获取原始college_id
    int collegeId = -1;
    QSqlQuery query;
    query.prepare("SELECT college_id FROM majors WHERE major_id = ?");
    query.addBindValue(majorId);
    if (query.exec() && query.next()) {
        collegeId = query.value(0).toInt();
    }

    AddMajorDialog dialog(this);
    dialog.setMajorData(majorId, majorName, majorCode, collegeId);

    if (dialog.exec() == QDialog::Accepted) {
        QString newName = dialog.getMajorName();
        QString newCode = dialog.getMajorCode();
        int newCollegeId = dialog.getCollegeId();

        if (newName.isEmpty()) {
            QMessageBox::warning(this, "警告", "专业名称不能为空！");
            return;
        }

        query.prepare(R"(
            UPDATE majors SET major_name = :name, major_code = :code, college_id = :cid
            WHERE major_id = :id
        )");
        query.bindValue(":name", newName);
        query.bindValue(":code", newCode);
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
    QString key = ui->searchEdit->text().trimmed();
    if (key.isEmpty()) {
        loadMajors();
        return;
    }
    
    QSqlQuery query;
    query.prepare("SELECT * FROM majors WHERE major_name LIKE ?");
    query.addBindValue("%" + key + "%");
    
    if (query.exec()) {
        QSqlQueryModel *tempModel = new QSqlQueryModel(this);
        tempModel->setQuery(query);
        
        tempModel->setHeaderData(0, Qt::Horizontal, "专业ID");
        tempModel->setHeaderData(1, Qt::Horizontal, "专业名称");
        tempModel->setHeaderData(2, Qt::Horizontal, "专业代码");
        tempModel->setHeaderData(3, Qt::Horizontal, "所属学院");
        
        ui->tableView->setModel(tempModel);
    } else {
        QMessageBox::critical(this, "错误", "搜索失败：" + query.lastError().text());
    }
}
