#include "addteacherdialog.h"
#include "ui_addteacherdialog.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

AddTeacherDialog::AddTeacherDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddTeacherDialog)
    , m_userId(-1)
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

void AddTeacherDialog::setTeacherData(int userId, const QString &teacherNo, const QString &name, const QString &gender,
                                      const QString &title, int collegeId, const QString &phone, const QString &email)
{
    m_userId = userId;
    this->setWindowTitle("编辑教师");

    ui->teacherNoEdit->setText(teacherNo);
    ui->nameEdit->setText(name);
    ui->genderCombo->setCurrentText(gender);
    ui->titleCombo->setCurrentText(title);
    ui->phoneEdit->setText(phone);
    ui->emailEdit->setText(email);

    // 设置学院
    int collegeIndex = ui->collegeCombo->findData(collegeId);
    if (collegeIndex >= 0) {
        ui->collegeCombo->setCurrentIndex(collegeIndex);
    }
}

int AddTeacherDialog::getUserId() const
{
    return m_userId;
}


