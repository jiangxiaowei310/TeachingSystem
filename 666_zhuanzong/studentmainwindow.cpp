#include "studentmainwindow.h"
#include "ui_studentmainwindow.h"
#include <QMessageBox>

StudentMainWindow::StudentMainWindow(const QString &studentName, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StudentMainWindow)
    , m_studentName(studentName)
{
    ui->setupUi(this);
    this->setWindowTitle("学生管理系统 - 学生端");

    m_sidebarGroup = new QButtonGroup(this);
    m_sidebarGroup->setExclusive(true);
    m_sidebarGroup->addButton(ui->homeBtn);
    m_sidebarGroup->addButton(ui->courseBtn);
    m_sidebarGroup->addButton(ui->gradeBtn);
    m_sidebarGroup->addButton(ui->scheduleBtn);
    m_sidebarGroup->addButton(ui->infoBtn);

    for (auto btn : m_sidebarGroup->buttons())
        btn->setCheckable(true);

    ui->homeBtn->setChecked(true);

    m_homePage = new StudentHomePage(m_studentName);
    m_coursePage = new StudentCoursePage();
    m_gradePage = new StudentGradePage();
    m_schedulePage = new StudentSchedulePage();
    m_infoPage = new StudentInfoPage();

    ui->contentStack->addWidget(m_homePage);
    ui->contentStack->addWidget(m_coursePage);
    ui->contentStack->addWidget(m_gradePage);
    ui->contentStack->addWidget(m_schedulePage);
    ui->contentStack->addWidget(m_infoPage);

    ui->contentStack->setCurrentWidget(m_homePage);
    ui->welcomeLabel->setText("欢迎，" + m_studentName);
}

StudentMainWindow::~StudentMainWindow()
{
    delete ui;
    delete m_homePage;
    delete m_coursePage;
    delete m_gradePage;
    delete m_schedulePage;
    delete m_infoPage;
}

void StudentMainWindow::on_homeBtn_clicked()
{
    ui->contentStack->setCurrentWidget(m_homePage);
    ui->homeBtn->setChecked(true);
}

void StudentMainWindow::on_courseBtn_clicked()
{
    ui->contentStack->setCurrentWidget(m_coursePage);
    ui->courseBtn->setChecked(true);
}

void StudentMainWindow::on_gradeBtn_clicked()
{
    ui->contentStack->setCurrentWidget(m_gradePage);
    ui->gradeBtn->setChecked(true);
}

void StudentMainWindow::on_scheduleBtn_clicked()
{
    ui->contentStack->setCurrentWidget(m_schedulePage);
    ui->scheduleBtn->setChecked(true);
}

void StudentMainWindow::on_infoBtn_clicked()
{
    ui->contentStack->setCurrentWidget(m_infoPage);
    ui->infoBtn->setChecked(true);
}

void StudentMainWindow::on_logoutBtn_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "确认退出",
        "确定要退出登录吗？", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        close();
    }
}
