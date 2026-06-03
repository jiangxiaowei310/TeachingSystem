#include "addteacherdialog.h"
#include "ui_addteacherdialog.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

AddTeacherDialog::AddTeacherDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddTeacherDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("添加教师");

    // 加载学院数据
    loadColleges();
}

AddTeacherDialog::~AddTeacherDialog()
{
    delete ui;
}

void AddTeacherDialog::loadColleges()
{
    ui->collegeCombo->clear();

    QSqlQuery query("SELECT college_id, college_name FROM colleges ORDER BY college_id");
    while (query.next()) {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        ui->collegeCombo->addItem(name, id);
    }
}

QString AddTeacherDialog::getTeacherNo() const
{
    return ui->teacherNoEdit->text();
}

QString AddTeacherDialog::getName() const
{
    return ui->nameEdit->text();
}

QString AddTeacherDialog::getGender() const
{
    return ui->genderCombo->currentText();
}

QString AddTeacherDialog::getTitle() const
{
    return ui->titleCombo->currentText();
}

int AddTeacherDialog::getCollegeId() const
{
    return ui->collegeCombo->currentData().toInt();
}

QString AddTeacherDialog::getPhone() const
{
    return ui->phoneEdit->text();
}

QString AddTeacherDialog::getEmail() const
{
    return ui->emailEdit->text();
}


