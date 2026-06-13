#include "addcoursedialog.h"
#include "ui_addcoursedialog.h"

AddCourseDialog::AddCourseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCourseDialog),
    m_courseId(-1)
{
    ui->setupUi(this);
}

AddCourseDialog::~AddCourseDialog()
{
    delete ui;
}

void AddCourseDialog::setCourseData(int courseId, const QString &courseName, const QString &courseCode,
                                    const QString &credit, const QString &classHour, const QString &description)
{
    m_courseId = courseId;
    ui->courseNameEdit->setText(courseName);
    ui->courseCodeEdit->setText(courseCode);
    ui->creditEdit->setText(credit);
    ui->classHourEdit->setText(classHour);
    ui->descriptionEdit->setText(description);
}

QString AddCourseDialog::getCourseName() const
{
    return ui->courseNameEdit->text().trimmed();
}

QString AddCourseDialog::getCourseCode() const
{
    return ui->courseCodeEdit->text().trimmed();
}

QString AddCourseDialog::getCredit() const
{
    return ui->creditEdit->text().trimmed();
}

QString AddCourseDialog::getClassHour() const
{
    return ui->classHourEdit->text().trimmed();
}

QString AddCourseDialog::getDescription() const
{
    return ui->descriptionEdit->toPlainText().trimmed();
}

int AddCourseDialog::getCourseId() const
{
    return m_courseId;
}