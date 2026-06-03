#include "studentschedulepage.h"
#include "ui_studentschedulepage.h"

StudentSchedulePage::StudentSchedulePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentSchedulePage)
{
    ui->setupUi(this);
}

StudentSchedulePage::~StudentSchedulePage()
{
    delete ui;
}
