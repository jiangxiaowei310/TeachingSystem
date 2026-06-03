#ifndef MAJORPAGE_H
#define MAJORPAGE_H

#include <QWidget>
#include <QSqlRelationalTableModel>

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

private:
    Ui::MajorPage *ui;
    QSqlRelationalTableModel *model;

    void loadMajors();
};

#endif // MAJORPAGE_H
