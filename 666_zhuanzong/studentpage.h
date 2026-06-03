#ifndef STUDENTPAGE_H
#define STUDENTPAGE_H

#include <QSqlRelationalTableModel>
#include <QWidget>

namespace Ui {
class StudentPage;
}

class StudentPage : public QWidget
{
    Q_OBJECT

public:
    explicit StudentPage(QWidget *parent = nullptr);
    ~StudentPage();

private slots:
    void on_addBtn_clicked();
    void on_editBtn_clicked();
    void on_deleteBtn_clicked();
    void on_searchBtn_clicked();
    void loadStudents();

private:
    Ui::StudentPage *ui;
    QSqlRelationalTableModel *model;

};

#endif // STUDENTPAGE_H
