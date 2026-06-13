#include "teachermainwindow.h"
#include "ui_teachermainwindow.h"
#include <QMessageBox>

TeacherMainWindow::TeacherMainWindow(const QString &teacherName, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TeacherMainWindow)
    , m_teacherName(teacherName)
{
    ui->setupUi(this);
    this->setWindowTitle("学生管理系统 - 教师端");

    m_sidebarGroup = new QButtonGroup(this);
    m_sidebarGroup->setExclusive(true);
    m_sidebarGroup->addButton(ui->homeBtn);
    m_sidebarGroup->addButton(ui->myStudentsBtn);
    m_sidebarGroup->addButton(ui->courseBtn);
    m_sidebarGroup->addButton(ui->gradeBtn);
    m_sidebarGroup->addButton(ui->infoBtn);

    for (auto btn : m_sidebarGroup->buttons())
        btn->setCheckable(true);

    ui->homeBtn->setChecked(true);

    m_homePage = new TeacherHomePage(m_teacherName);
    m_myStudentsPage = new TeacherMyStudentsPage();
    m_coursePage = new TeacherCoursePage();
    m_gradePage = new TeacherGradePage();
    m_infoPage = new TeacherInfoPage();

    ui->contentStack->addWidget(m_homePage);
    ui->contentStack->addWidget(m_myStudentsPage);
    ui->contentStack->addWidget(m_coursePage);
    ui->contentStack->addWidget(m_gradePage);
    ui->contentStack->addWidget(m_infoPage);

    ui->contentStack->setCurrentWidget(m_homePage);
    ui->welcomeLabel->setText("欢迎，" + m_teacherName + " 老师");
}

TeacherMainWindow::~TeacherMainWindow()
{
    delete ui;
    delete m_homePage;
    delete m_myStudentsPage;
    delete m_coursePage;
    delete m_gradePage;
    delete m_infoPage;
}

void TeacherMainWindow::on_homeBtn_clicked()
{
    ui->contentStack->setCurrentWidget(m_homePage);
    ui->homeBtn->setChecked(true);
}

void TeacherMainWindow::on_myStudentsBtn_clicked()
{
    ui->contentStack->setCurrentWidget(m_myStudentsPage);
    ui->myStudentsBtn->setChecked(true);
}

void TeacherMainWindow::on_courseBtn_clicked()
{
    ui->contentStack->setCurrentWidget(m_coursePage);
    ui->courseBtn->setChecked(true);
}

void TeacherMainWindow::on_gradeBtn_clicked()
{
    ui->contentStack->setCurrentWidget(m_gradePage);
    ui->gradeBtn->setChecked(true);
}

void TeacherMainWindow::on_infoBtn_clicked()
{
    ui->contentStack->setCurrentWidget(m_infoPage);
    ui->infoBtn->setChecked(true);
}

void TeacherMainWindow::on_logoutBtn_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "确认退出",
        "确定要退出登录吗？", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        close();
    }
}
