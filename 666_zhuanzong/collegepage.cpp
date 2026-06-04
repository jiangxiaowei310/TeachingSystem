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
    AddCollegeDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString collegeName = dialog.getCollegeName();
        QString collegeCode = dialog.getCollegeCode();
        QString dean = dialog.getDean();
        QString phone = dialog.getPhone();

        if (collegeName.isEmpty()) {
            QMessageBox::warning(this, "警告", "学院名称不能为空！");
            return;
        }

        QSqlQuery query;
        query.prepare(R"(
            INSERT INTO colleges (college_name, college_code, dean, phone)
            VALUES (:name, :code, :dean, :phone)
        )");
        query.bindValue(":name", collegeName);
        query.bindValue(":code", collegeCode);
        query.bindValue(":dean", dean);
        query.bindValue(":phone", phone);

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
    QString collegeName = model->data(model->index(row, model->fieldIndex("college_name"))).toString();
    QString collegeCode = model->data(model->index(row, model->fieldIndex("college_code"))).toString();
    QString dean = model->data(model->index(row, model->fieldIndex("dean"))).toString();
    QString phone = model->data(model->index(row, model->fieldIndex("phone"))).toString();

    AddCollegeDialog dialog(this);
    dialog.setCollegeData(collegeId, collegeName, collegeCode, dean, phone);

    if (dialog.exec() == QDialog::Accepted) {
        QString newName = dialog.getCollegeName();
        QString newCode = dialog.getCollegeCode();
        QString newDean = dialog.getDean();
        QString newPhone = dialog.getPhone();

        if (newName.isEmpty()) {
            QMessageBox::warning(this, "警告", "学院名称不能为空！");
            return;
        }

        QSqlQuery query;
        query.prepare(R"(
            UPDATE colleges SET college_name = :name, college_code = :code, dean = :dean, phone = :phone
            WHERE college_id = :id
        )");
        query.bindValue(":name", newName);
        query.bindValue(":code", newCode);
        query.bindValue(":dean", newDean);
        query.bindValue(":phone", newPhone);
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
    QString key = ui->searchEdit->text().trimmed();
    if (key.isEmpty()) {
        loadColleges();
        return;
    }
    
    QSqlQuery query;
    query.prepare("SELECT * FROM colleges WHERE college_name LIKE ?");
    query.addBindValue("%" + key + "%");
    
    if (query.exec()) {
        QSqlQueryModel *tempModel = new QSqlQueryModel(this);
        tempModel->setQuery(query);
        
        tempModel->setHeaderData(0, Qt::Horizontal, "学院ID");
        tempModel->setHeaderData(1, Qt::Horizontal, "学院名称");
        tempModel->setHeaderData(2, Qt::Horizontal, "学院代码");
        tempModel->setHeaderData(3, Qt::Horizontal, "院长");
        tempModel->setHeaderData(4, Qt::Horizontal, "联系电话");
        
        ui->tableView->setModel(tempModel);
    } else {
        QMessageBox::critical(this, "错误", "搜索失败：" + query.lastError().text());
    }
}
