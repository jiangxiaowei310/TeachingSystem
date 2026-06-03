#include "teachercoursepage.h"
#include "ui_teachercoursepage.h"

TeacherCoursePage::TeacherCoursePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeacherCoursePage)
{
    ui->setupUi(this);
}

TeacherCoursePage::~TeacherCoursePage()
{
    delete ui;
}

void TeacherCoursePage::on_addBtn_clicked()
{
}

void TeacherCoursePage::on_editBtn_clicked()
{
}
