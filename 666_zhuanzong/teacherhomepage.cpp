#include "teacherhomepage.h"
#include "ui_teacherhomepage.h"

TeacherHomePage::TeacherHomePage(const QString &teacherName, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeacherHomePage),
    m_teacherName(teacherName)
{
    ui->setupUi(this);
    ui->teacherNameLabel->setText(m_teacherName);
}

TeacherHomePage::~TeacherHomePage()
{
    delete ui;
}
