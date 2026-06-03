#include "studentinfopage.h"
#include "ui_studentinfopage.h"

StudentInfoPage::StudentInfoPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentInfoPage)
{
    ui->setupUi(this);
}

StudentInfoPage::~StudentInfoPage()
{
    delete ui;
}

void StudentInfoPage::on_editBtn_clicked()
{
}

void StudentInfoPage::on_saveBtn_clicked()
{
}
