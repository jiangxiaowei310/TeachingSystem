#ifndef TEACHERPAGE_H
#define TEACHERPAGE_H

#include <QSqlQueryModel>
#include <QWidget>

class QSqlRelationalTableModel;

namespace Ui {
class TeacherPage;
}

class TeacherPage : public QWidget
{
    Q_OBJECT

public:
    explicit TeacherPage(QWidget *parent = nullptr);
    ~TeacherPage();

private slots:
    void on_addBtn_clicked();
    void on_editBtn_clicked();
    void on_deleteBtn_clicked();
    void on_searchBtn_clicked();

    void on_prevBtn_clicked();
    void on_nextBtn_clicked();
    void on_pageSizeCombo_currentIndexChanged(const QString &text);

private:
    Ui::TeacherPage *ui;
    QSqlQueryModel *model;

    int currentPage;
    int pageSize;
    int totalRecords;
    int totalPages;


    void loadTeachers();
};

#endif // TEACHERPAGE_H
