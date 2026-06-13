#include "addstudentdialog.h"
#include "ui_addstudentdialog.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

AddStudentDialog::AddStudentDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddStudentDialog)
    , m_userId(-1)
{
    ui->setupUi(this);
    this->setWindowTitle("添加学生");

    // 加载学院数据
    loadColleges();

    // 学院变化时更新专业列表
    connect(ui->collegeCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &AddStudentDialog::onCollegeChanged);

    // 专业变化时更新班级列表
    connect(ui->majorCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &AddStudentDialog::onMajorChanged);
}

AddStudentDialog::~AddStudentDialog()
{
    delete ui;
}

void AddStudentDialog::loadColleges()
{
    ui->collegeCombo->clear();

    QSqlQuery query("SELECT college_id, college_name FROM colleges ORDER BY college_id");
    while (query.next()) {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        ui->collegeCombo->addItem(name, id);
    }

    // 默认选中第一个学院并加载专业
    if (ui->collegeCombo->count() > 0) {
        onCollegeChanged(0);
    }
}

void AddStudentDialog::onCollegeChanged(int index)
{
    ui->majorCombo->clear();

    if (index < 0) return;

    int collegeId = ui->collegeCombo->itemData(index).toInt();

    QSqlQuery query;
    query.prepare("SELECT major_id, major_name FROM majors WHERE college_id = ? ORDER BY major_id");
    query.addBindValue(collegeId);
    query.exec();

    while (query.next()) {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        ui->majorCombo->addItem(name, id);
    }

    // 默认选中第一个专业并加载班级
    if (ui->majorCombo->count() > 0) {
        onMajorChanged(0);
    } else {
        ui->classCombo->clear();
    }
}

void AddStudentDialog::onMajorChanged(int index)
{
    ui->classCombo->clear();

    if (index < 0) return;

    int majorId = ui->majorCombo->itemData(index).toInt();

    QSqlQuery query;
    query.prepare("SELECT class_id, class_name FROM classes WHERE major_id = ? ORDER BY class_id");
    query.addBindValue(majorId);
    query.exec();

    while (query.next()) {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        ui->classCombo->addItem(name, id);
    }
}

QString AddStudentDialog::getStuNo() const
{
    return ui->stuNoEdit->text();
}

QString AddStudentDialog::getName() const
{
    return ui->nameEdit->text();
}

QString AddStudentDialog::getGender() const
{
    return ui->genderCombo->currentText();
}

int AddStudentDialog::getCollegeId() const
{
    return ui->collegeCombo->currentData().toInt();
}

int AddStudentDialog::getMajorId() const
{
    return ui->majorCombo->currentData().toInt();
}

int AddStudentDialog::getClassId() const
{
    return ui->classCombo->currentData().toInt();
}

QString AddStudentDialog::getGrade() const
{
    return ui->gradeEdit->text();
}

QString AddStudentDialog::getPhone() const
{
    return ui->phoneEdit->text();
}

QString AddStudentDialog::getEmail() const
{
    return ui->emailEdit->text();
}

void AddStudentDialog::setStudentData(int userId, const QString &stuNo, const QString &name, const QString &gender,
                                      int collegeId, int majorId, int classId, const QString &grade,
                                      const QString &phone, const QString &email)
{
    m_userId = userId;
    this->setWindowTitle("编辑学生");

    ui->stuNoEdit->setText(stuNo);
    ui->nameEdit->setText(name);
    ui->genderCombo->setCurrentText(gender);
    ui->gradeEdit->setText(grade);
    ui->phoneEdit->setText(phone);
    ui->emailEdit->setText(email);

    // 设置学院
    int collegeIndex = ui->collegeCombo->findData(collegeId);
    if (collegeIndex >= 0) {
        ui->collegeCombo->setCurrentIndex(collegeIndex);
    }

    // 设置专业
    int majorIndex = ui->majorCombo->findData(majorId);
    if (majorIndex >= 0) {
        ui->majorCombo->setCurrentIndex(majorIndex);
    }

    // 设置班级
    int classIndex = ui->classCombo->findData(classId);
    if (classIndex >= 0) {
        ui->classCombo->setCurrentIndex(classIndex);
    }
}

int AddStudentDialog::getUserId() const
{
    return m_userId;
}
