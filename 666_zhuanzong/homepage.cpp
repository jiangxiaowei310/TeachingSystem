#include "homepage.h"
#include "ui_homepage.h"
#include "addstudentdialog.h"
#include "addteacherdialog.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

HomePage::HomePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomePage)
{
    ui->setupUi(this);

    loadStatistics();
}

HomePage::~HomePage()
{
    delete ui;
}

void HomePage::loadStatistics()
{
    QSqlQuery query;

    // 学生总数
    if(query.exec("SELECT COUNT(*) FROM students"))
    {
        if(query.next())
        {
            ui->studentCount->setText(
                QString::number(query.value(0).toInt())
                );
        }
    }

    // 教师总数
    if(query.exec("SELECT COUNT(*) FROM teachers"))
    {
        if(query.next())
        {
            ui->teacherCount->setText(
                QString::number(query.value(0).toInt())
                );
        }
    }

    // 班级总数
    if(query.exec("SELECT COUNT(*) FROM classes"))
    {
        if(query.next())
        {
            ui->classCount->setText(
                QString::number(query.value(0).toInt())
                );
        }
    }

    // 学院总数
    if(query.exec("SELECT COUNT(*) FROM colleges"))
    {
        if(query.next())
        {
            ui->collegeCount->setText(
                QString::number(query.value(0).toInt())
                );
        }
    }
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

