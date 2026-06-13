#include "adduserdialog.h"
#include "ui_adduserdialog.h"

AddUserDialog::AddUserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddUserDialog),
    m_userId(-1)
{
    ui->setupUi(this);
    this->setWindowTitle("添加用户");

    ui->roleCombo->addItem("admin");
    ui->roleCombo->addItem("teacher");
    ui->roleCombo->addItem("student");
}

AddUserDialog::~AddUserDialog()
{
    delete ui;
}

void AddUserDialog::setUserData(int userId, const QString &username, const QString &password, const QString &role)
{
    m_userId = userId;
    this->setWindowTitle("编辑用户");

    ui->usernameEdit->setText(username);
    ui->passwordEdit->setText(password);
    ui->roleCombo->setCurrentText(role);
}

int AddUserDialog::getUserId() const
{
    return m_userId;
}

QString AddUserDialog::getUsername() const
{
    return ui->usernameEdit->text();
}

QString AddUserDialog::getPassword() const
{
    return ui->passwordEdit->text();
}

QString AddUserDialog::getRole() const
{
    return ui->roleCombo->currentText();
}
