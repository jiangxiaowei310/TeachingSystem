#include "addmajordialog.h"
#include "ui_addmajordialog.h"
#include <QSqlQuery>

AddMajorDialog::AddMajorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMajorDialog),
    m_majorId(-1)
{
    ui->setupUi(this);
    this->setWindowTitle("添加专业");
    loadColleges();
}

AddMajorDialog::~AddMajorDialog()
{
    delete ui;
}

void AddMajorDialog::loadColleges()
{
    ui->collegeCombo->clear();

    QSqlQuery query("SELECT college_id, college_name FROM colleges ORDER BY college_id");
    while (query.next()) {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        ui->collegeCombo->addItem(name, id);
    }
}

void AddMajorDialog::setMajorData(int majorId, const QString &majorName, const QString &majorCode, int collegeId)
{
    m_majorId = majorId;
    this->setWindowTitle("编辑专业");

    ui->majorNameEdit->setText(majorName);
    ui->majorCodeEdit->setText(majorCode);

    int collegeIndex = ui->collegeCombo->findData(collegeId);
    if (collegeIndex >= 0) {
        ui->collegeCombo->setCurrentIndex(collegeIndex);
    }
}

int AddMajorDialog::getMajorId() const
{
    return m_majorId;
}

QString AddMajorDialog::getMajorName() const
{
    return ui->majorNameEdit->text();
}

QString AddMajorDialog::getMajorCode() const
{
    return ui->majorCodeEdit->text();
}

int AddMajorDialog::getCollegeId() const
{
    return ui->collegeCombo->currentData().toInt();
}
