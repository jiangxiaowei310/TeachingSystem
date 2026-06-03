#include "teacherinfopage.h"
#include "ui_teacherinfopage.h"

TeacherInfoPage::TeacherInfoPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeacherInfoPage)
{
    ui->setupUi(this);
}

TeacherInfoPage::~TeacherInfoPage()
{
    delete ui;
}

void TeacherInfoPage::on_editBtn_clicked()
{
}

void TeacherInfoPage::on_saveBtn_clicked()
{
}
