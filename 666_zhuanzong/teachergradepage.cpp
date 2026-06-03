#include "teachergradepage.h"
#include "ui_teachergradepage.h"

TeacherGradePage::TeacherGradePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeacherGradePage)
{
    ui->setupUi(this);
}

TeacherGradePage::~TeacherGradePage()
{
    delete ui;
}

void TeacherGradePage::on_inputBtn_clicked()
{
}

void TeacherGradePage::on_saveBtn_clicked()
{
}

void TeacherGradePage::on_importBtn_clicked()
{
}
