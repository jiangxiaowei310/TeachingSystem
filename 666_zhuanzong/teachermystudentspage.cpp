#include "teachermystudentspage.h"
#include "ui_teachermystudentspage.h"

TeacherMyStudentsPage::TeacherMyStudentsPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeacherMyStudentsPage)
{
    ui->setupUi(this);
}

TeacherMyStudentsPage::~TeacherMyStudentsPage()
{
    delete ui;
}

void TeacherMyStudentsPage::on_searchBtn_clicked()
{
}

void TeacherMyStudentsPage::on_exportBtn_clicked()
{
}
