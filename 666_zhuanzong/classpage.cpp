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
    AddClassDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString className = dialog.getClassName();
        QString classCode = dialog.getClassCode();
        QString grade = dialog.getGrade();
        int majorId = dialog.getMajorId();
        int collegeId = dialog.getCollegeId();

        if (className.isEmpty()) {
            QMessageBox::warning(this, "警告", "班级名称不能为空！");
            return;
        }

        QSqlQuery query;
        query.prepare(R"(
            INSERT INTO classes (class_name, class_code, grade, college_id, major_id)
            VALUES (:name, :code, :grade, :cid, :mid)
        )");
        query.bindValue(":name", className);
        query.bindValue(":code", classCode);
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
    QString className = model->data(model->index(row, model->fieldIndex("class_name"))).toString();
    QString classCode = model->data(model->index(row, model->fieldIndex("class_code"))).toString();
    QString grade = model->data(model->index(row, model->fieldIndex("grade"))).toString();

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
    dialog.setClassData(classId, className, classCode, grade, majorId, collegeId);

    if (dialog.exec() == QDialog::Accepted) {
        QString newName = dialog.getClassName();
        QString newCode = dialog.getClassCode();
        QString newGrade = dialog.getGrade();
        int newMajorId = dialog.getMajorId();
        int newCollegeId = dialog.getCollegeId();

        if (newName.isEmpty()) {
            QMessageBox::warning(this, "警告", "班级名称不能为空！");
            return;
        }

        query.prepare(R"(
            UPDATE classes SET class_name = :name, class_code = :code, grade = :grade,
                            college_id = :cid, major_id = :mid
            WHERE class_id = :id
        )");
        query.bindValue(":name", newName);
        query.bindValue(":code", newCode);
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
    QString key = ui->searchEdit->text().trimmed();
    if (key.isEmpty()) {
        loadClasses();
        return;
    }
    
    QSqlQuery query;
    query.prepare("SELECT * FROM classes WHERE class_name LIKE ?");
    query.addBindValue("%" + key + "%");
    
    if (query.exec()) {
        QSqlQueryModel *tempModel = new QSqlQueryModel(this);
        tempModel->setQuery(query);
        
        tempModel->setHeaderData(0, Qt::Horizontal, "班级ID");
        tempModel->setHeaderData(1, Qt::Horizontal, "班级名称");
        tempModel->setHeaderData(2, Qt::Horizontal, "班级代码");
        tempModel->setHeaderData(3, Qt::Horizontal, "年级");
        tempModel->setHeaderData(4, Qt::Horizontal, "所属学院");
        tempModel->setHeaderData(5, Qt::Horizontal, "所属专业");
        
        ui->tableView->setModel(tempModel);
    } else {
        QMessageBox::critical(this, "错误", "搜索失败：" + query.lastError().text());
    }
}
