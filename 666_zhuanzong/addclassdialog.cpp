#include "addclassdialog.h"
#include "ui_addclassdialog.h"
#include <QSqlQuery>

AddClassDialog::AddClassDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddClassDialog),
    m_classId(-1)
{
    ui->setupUi(this);
    this->setWindowTitle("添加班级");
    loadColleges();

    connect(ui->collegeCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &AddClassDialog::onCollegeChanged);
}

AddClassDialog::~AddClassDialog()
{
    delete ui;
}

void AddClassDialog::loadColleges()
{
    ui->collegeCombo->clear();

    QSqlQuery query("SELECT college_id, college_name FROM colleges ORDER BY college_id");
    while (query.next()) {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        ui->collegeCombo->addItem(name, id);
    }

    if (ui->collegeCombo->count() > 0) {
        onCollegeChanged(0);
    }
}

void AddClassDialog::loadMajors(int collegeId)
{
    ui->majorCombo->clear();

    QSqlQuery query;
    query.prepare("SELECT major_id, major_name FROM majors WHERE college_id = ? ORDER BY major_id");
    query.addBindValue(collegeId);
    query.exec();

    while (query.next()) {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        ui->majorCombo->addItem(name, id);
    }
}

void AddClassDialog::onCollegeChanged(int index)
{
    if (index < 0) return;
    int collegeId = ui->collegeCombo->itemData(index).toInt();
    loadMajors(collegeId);
}

void AddClassDialog::setClassData(int classId, const QString &className, const QString &classCode,
                                  const QString &grade, int majorId, int collegeId)
{
    m_classId = classId;
    this->setWindowTitle("编辑班级");

    ui->classNameEdit->setText(className);
    ui->classCodeEdit->setText(classCode);
    ui->gradeEdit->setText(grade);

    int collegeIndex = ui->collegeCombo->findData(collegeId);
    if (collegeIndex >= 0) {
        ui->collegeCombo->setCurrentIndex(collegeIndex);
    }

    int majorIndex = ui->majorCombo->findData(majorId);
    if (majorIndex >= 0) {
        ui->majorCombo->setCurrentIndex(majorIndex);
    }
}

int AddClassDialog::getClassId() const
{
    return m_classId;
}

QString AddClassDialog::getClassName() const
{
    return ui->classNameEdit->text();
}

QString AddClassDialog::getClassCode() const
{
    return ui->classCodeEdit->text();
}

QString AddClassDialog::getGrade() const
{
    return ui->gradeEdit->text();
}

int AddClassDialog::getMajorId() const
{
    return ui->majorCombo->currentData().toInt();
}

int AddClassDialog::getCollegeId() const
{
    return ui->collegeCombo->currentData().toInt();
}
