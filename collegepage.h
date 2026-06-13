#ifndef COLLEGEPAGE_H
#define COLLEGEPAGE_H

#include <QSqlQueryModel>
#include <QWidget>

namespace Ui {
class CollegePage;
}

class CollegePage : public QWidget
{
    Q_OBJECT

public:
    explicit CollegePage(QWidget *parent = nullptr);
    ~CollegePage();

private slots:
    void on_addBtn_clicked();
    void on_editBtn_clicked();
    void on_deleteBtn_clicked();
    void on_searchBtn_clicked();
    void on_prevBtn_clicked();
    void on_nextBtn_clicked();
    void on_pageSizeCombo_currentIndexChanged(const QString &text);

private:
    Ui::CollegePage *ui;
    QSqlQueryModel *model;

    int currentPage;
    int pageSize;
    int totalRecords;
    int totalPages;

    void loadColleges();
};

#endif // COLLEGEPAGE_H
