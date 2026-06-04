#include "addcollegedialog.h"
#include "ui_addcollegedialog.h"

AddCollegeDialog::AddCollegeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCollegeDialog),
    m_collegeId(-1)
{
    ui->setupUi(this);
    this->setWindowTitle("添加学院");
}

AddCollegeDialog::~AddCollegeDialog()
{
    delete ui;
}

void AddCollegeDialog::setCollegeData(int collegeId, const QString &collegeName, const QString &collegeCode,
                                      const QString &dean, const QString &phone)
{
    m_collegeId = collegeId;
    this->setWindowTitle("编辑学院");

    ui->collegeNameEdit->setText(collegeName);
    ui->collegeCodeEdit->setText(collegeCode);
    ui->deanEdit->setText(dean);
    ui->phoneEdit->setText(phone);
}

int AddCollegeDialog::getCollegeId() const
{
    return m_collegeId;
}

QString AddCollegeDialog::getCollegeName() const
{
    return ui->collegeNameEdit->text();
}

QString AddCollegeDialog::getCollegeCode() const
{
    return ui->collegeCodeEdit->text();
}

QString AddCollegeDialog::getDean() const
{
    return ui->deanEdit->text();
}

QString AddCollegeDialog::getPhone() const
{
    return ui->phoneEdit->text();
}
