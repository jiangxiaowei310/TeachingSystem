#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <qsqlerror.h>

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("学生管理系统 - 登录");
    ui->passwordEdit->setEchoMode(QLineEdit::Password);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

QString LoginWindow::getUsername() const
{
    return ui->usernameEdit->text();
}

QString LoginWindow::getPassword() const
{
    return ui->passwordEdit->text();
}

UserRole LoginWindow::getUserRole() const
{
    int index = ui->roleComboBox->currentIndex();
    switch (index) {
    case 0: return UserRole::Admin;
    case 1: return UserRole::Teacher;
    case 2: return UserRole::Student;
    default: return UserRole::Admin;
    }
}
void LoginWindow::on_loginBtn_clicked()
{
    QString username = ui->usernameEdit->text().trimmed();
    QString password = ui->passwordEdit->text().trimmed();
    UserRole role = getUserRole();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "警告", "请输入用户名和密码！");
        return;
    }

    // 连接数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("管理系统");   // 你的数据库名
    db.setUserName("root");          // MySQL账号
    db.setPassword("123456");        // MySQL密码
    db.setPort(3306);

    if (!db.open()) {
        QMessageBox::critical(this, "数据库错误", "无法连接数据库：\n" + db.lastError().text());
        return;
    }

    // 关键：统一查询 users 表，按账号、密码、角色同时验证
    bool loginSuccess = false;
    QSqlQuery query;

    // 把 Qt 的 UserRole 转换成数据库里的 role 字符串
    QString roleStr;
    switch (role) {
    case UserRole::Admin:
        roleStr = "admin";
        break;
    case UserRole::Teacher:
        roleStr = "teacher";
        break;
    case UserRole::Student:
        roleStr = "student";
        break;
    }

    // ✅ 正确写法：从 users 表查询
    query.prepare("SELECT id FROM users WHERE username = :user AND password = :pwd AND role = :role");
    query.bindValue(":user", username);
    query.bindValue(":pwd", password);
    query.bindValue(":role", roleStr);

    if (query.exec() && query.next()) {
        loginSuccess = true;
    }

    if (loginSuccess) {
        accept();
    } else {
        QMessageBox::critical(this, "错误", "用户名或密码错误！");
        ui->passwordEdit->clear();
        ui->passwordEdit->setFocus();
    }
}


void LoginWindow::on_exitBtn_clicked()
{
    reject();
}
