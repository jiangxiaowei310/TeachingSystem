#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>

namespace Ui {
class LoginWindow;
}

enum class UserRole {
    Admin,
    Teacher,
    Student
};

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

    QString getUsername() const;
    QString getPassword() const;
    UserRole getUserRole() const;

private slots:
    void on_loginBtn_clicked();
    void on_exitBtn_clicked();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H