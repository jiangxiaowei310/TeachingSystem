#include "studentcoursepage.h"
#include "ui_studentcoursepage.h"

StudentCoursePage::StudentCoursePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentCoursePage)
{
    ui->setupUi(this);
}

StudentCoursePage::~StudentCoursePage()
{
    delete ui;
}

void StudentCoursePage::on_selectBtn_clicked()
{
}

void StudentCoursePage::on_dropBtn_clicked()
{
}
