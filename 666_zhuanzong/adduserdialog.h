#ifndef ADDUSERDIALOG_H
#define ADDUSERDIALOG_H

#include <QDialog>

namespace Ui {
class AddUserDialog;
}

class AddUserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddUserDialog(QWidget *parent = nullptr);
    ~AddUserDialog();

    void setUserData(int userId, const QString &username, const QString &password, const QString &role);
    int getUserId() const;

    QString getUsername() const;
    QString getPassword() const;
    QString getRole() const;

private:
    Ui::AddUserDialog *ui;
    int m_userId;
};

#endif // ADDUSERDIALOG_H
