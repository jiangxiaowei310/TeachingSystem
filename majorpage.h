#ifndef MAJORPAGE_H
#define MAJORPAGE_H

#include <QWidget>
#include <QSqlQueryModel>

namespace Ui {
class MajorPage;
}

class MajorPage : public QWidget
{
    Q_OBJECT

public:
    explicit MajorPage(QWidget *parent = nullptr);
    ~MajorPage();

private slots:
    void on_addBtn_clicked();
    void on_editBtn_clicked();
    void on_deleteBtn_clicked();
    void on_searchBtn_clicked();
    void on_prevBtn_clicked();
    void on_nextBtn_clicked();
    void on_pageSizeCombo_currentIndexChanged(const QString &text);

private:
    Ui::MajorPage *ui;
    QSqlQueryModel *model;

    int currentPage;
    int pageSize;
    int totalRecords;
    int totalPages;

    void loadMajors();
};

#endif // MAJORPAGE_H
