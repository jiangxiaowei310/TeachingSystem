#ifndef USERPAGE_H
#define USERPAGE_H

#include <QWidget>
#include <QSqlRelationalTableModel>

namespace Ui {
class UserPage;
}

class UserPage : public QWidget
{
    Q_OBJECT

public:
    explicit UserPage(QWidget *parent = nullptr);
    ~UserPage();

private slots:
    void on_addBtn_clicked();
    void on_editBtn_clicked();
    void on_deleteBtn_clicked();
    void on_searchBtn_clicked();
    void on_resetPwdBtn_clicked();

private:
    Ui::UserPage *ui;
    QSqlRelationalTableModel *model;

    void loadUsers();
};

#endif // USERPAGE_H
