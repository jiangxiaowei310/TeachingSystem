#include "studenthomepage.h"
#include "ui_studenthomepage.h"

StudentHomePage::StudentHomePage(const QString &studentName, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentHomePage),
    m_studentName(studentName)
{
    ui->setupUi(this);
    ui->studentNameLabel->setText(m_studentName);
}

StudentHomePage::~StudentHomePage()
{
    delete ui;
}
