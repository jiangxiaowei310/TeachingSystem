#include "studentgradepage.h"
#include "ui_studentgradepage.h"

StudentGradePage::StudentGradePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentGradePage)
{
    ui->setupUi(this);
}

StudentGradePage::~StudentGradePage()
{
    delete ui;
}

void StudentGradePage::on_exportBtn_clicked()
{
}
