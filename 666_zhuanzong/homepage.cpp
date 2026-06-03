#include "homepage.h"
#include "ui_homepage.h"
#include "addstudentdialog.h"
#include "addteacherdialog.h"

HomePage::HomePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomePage)
{
    ui->setupUi(this);
}

HomePage::~HomePage()
{
    delete ui;
}
void HomePage::on_AddStudentsquickBtn_clicked()
{
    AddStudentDialog d;
    d.exec();
}


void HomePage::on_AddTeachersquickBtn_clicked()
{
    AddTeacherDialog t;
    t.exec();
}

