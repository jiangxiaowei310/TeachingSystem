#ifndef USERPAGE_H
#define USERPAGE_H

#include <QSqlQueryModel>
#include <QWidget>

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
    void on_prevBtn_clicked();
    void on_nextBtn_clicked();
    void on_pageSizeCombo_currentIndexChanged(const QString &text);

private:
    Ui::UserPage *ui;
    QSqlQueryModel *model;

    int currentPage;
    int pageSize;
    int totalRecords;
    int totalPages;

    void loadUsers();
};

#endif // USERPAGE_H
