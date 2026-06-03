#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlDatabase>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("管理系统");
    db.setUserName("root");
    db.setPassword("123456");
    db.setPort(3306);

    if (db.open()) {
        qDebug() << "✅ 数据库连接成功";
    } else {
        qDebug() << "❌ 数据库连接失败：" << db.lastError().text();
    }

    // -------- 1. 按钮互斥组（只管按钮亮不亮）--------
    m_sidebarGroup = new QButtonGroup(this);
    m_sidebarGroup->setExclusive(true);
    m_sidebarGroup->addButton(ui->homeBtn);
    m_sidebarGroup->addButton(ui->studentBtn);
    m_sidebarGroup->addButton(ui->teacherBtn);
    m_sidebarGroup->addButton(ui->classBtn);
    m_sidebarGroup->addButton(ui->majorBtn);
    m_sidebarGroup->addButton(ui->collegeBtn);
    m_sidebarGroup->addButton(ui->userBtn);
    for (auto btn : m_sidebarGroup->buttons())
        btn->setCheckable(true);

    ui->homeBtn->setChecked(true);
    // 创建所有页面
    m_homePage = new HomePage();
    m_studentPage = new StudentPage();
    m_teacherPage = new TeacherPage();
    m_classPage = new ClassPage();
    m_majorPage = new MajorPage();
    m_collegePage = new CollegePage();
    m_userPage = new UserPage();
    // 添加到堆叠控件
    ui->contentStack->addWidget(m_homePage);
    ui->contentStack->addWidget(m_studentPage);
    ui->contentStack->addWidget(m_teacherPage);
    ui->contentStack->addWidget(m_classPage);
    ui->contentStack->addWidget(m_majorPage);
    ui->contentStack->addWidget(m_collegePage);
    ui->contentStack->addWidget(m_userPage);
    
    //ui->homeBtn->setChecked(true);
    // 默认显示首页
    ui->contentStack->setCurrentWidget(m_homePage);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_homePage;
    delete m_studentPage;
    delete m_teacherPage;
    delete m_classPage;
    delete m_majorPage;
    delete m_collegePage;
    delete m_userPage;
}
// 按钮点击 → 切换页面
void MainWindow::on_homeBtn_clicked()
{
    ui->contentStack->setCurrentWidget(m_homePage);
    ui->homeBtn->setChecked(true);
}

void MainWindow::on_studentBtn_clicked()
{
    ui->contentStack->setCurrentWidget(m_studentPage);
    ui->studentBtn->setChecked(true);
}

void MainWindow::on_teacherBtn_clicked()
{
    ui->contentStack->setCurrentWidget(m_teacherPage);
    ui->teacherBtn->setChecked(true);
}

void MainWindow::on_classBtn_clicked()
{
    ui->contentStack->setCurrentWidget(m_classPage);
    ui->classBtn->setChecked(true);
}

void MainWindow::on_majorBtn_clicked()
{
    ui->contentStack->setCurrentWidget(m_majorPage);
    ui->majorBtn->setChecked(true);
}

void MainWindow::on_collegeBtn_clicked()
{
    ui->contentStack->setCurrentWidget(m_collegePage);
    ui->collegeBtn->setChecked(true);
}

void MainWindow::on_userBtn_clicked()
{
    ui->contentStack->setCurrentWidget(m_userPage);
    ui->userBtn->setChecked(true);
}
