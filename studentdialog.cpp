#include "studentdialog.h"
#include "ui_studentdialog.h"
#include <QMessageBox>

StudentDialog::StudentDialog(QWidget *parent, bool isEdit) :
    QDialog(parent),
    ui(new Ui::StudentDialog),
    m_isEdit(isEdit)
{
    ui->setupUi(this);
    if (m_isEdit) {
        this->setWindowTitle("编辑学生信息");
        ui->idEdit->setReadOnly(true);
    } else {
        this->setWindowTitle("添加学生信息");
    }
}

StudentDialog::~StudentDialog()
{
    delete ui;
}

void StudentDialog::setStudentData(const Student &student)
{
    ui->idEdit->setText(student.id);
    ui->nameEdit->setText(student.name);
    ui->genderCombo->setCurrentText(student.gender);
    ui->majorEdit->setText(student.major);
    ui->gradeEdit->setText(student.grade);
    ui->phoneEdit->setText(student.phone);
    ui->emailEdit->setText(student.email);
}

Student StudentDialog::getStudentData() const
{
    Student s;
    s.id = ui->idEdit->text();
    s.name = ui->nameEdit->text();
    s.gender = ui->genderCombo->currentText();
    s.major = ui->majorEdit->text();
    s.grade = ui->gradeEdit->text();
    s.phone = ui->phoneEdit->text();
    s.email = ui->emailEdit->text();
    return s;
}

void StudentDialog::on_okBtn_clicked()
{
    QString id = ui->idEdit->text();
    QString name = ui->nameEdit->text();
    
    if (id.isEmpty()) {
        QMessageBox::warning(this, "警告", "请输入学号！");
        ui->idEdit->setFocus();
        return;
    }
    
    if (name.isEmpty()) {
        QMessageBox::warning(this, "警告", "请输入姓名！");
        ui->nameEdit->setFocus();
        return;
    }
    
    accept();
}

void StudentDialog::on_cancelBtn_clicked()
{
    reject();
}