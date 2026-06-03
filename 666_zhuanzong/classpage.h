#ifndef CLASSPAGE_H
#define CLASSPAGE_H

#include <QWidget>
#include <QSqlRelationalTableModel>

namespace Ui {
class ClassPage;
}

class ClassPage : public QWidget
{
    Q_OBJECT

public:
    explicit ClassPage(QWidget *parent = nullptr);
    ~ClassPage();

private slots:
    void on_addBtn_clicked();
    void on_editBtn_clicked();
    void on_deleteBtn_clicked();
    void on_searchBtn_clicked();

private:
    Ui::ClassPage *ui;
    QSqlRelationalTableModel *model;

    void loadClasses();
};

#endif // CLASSPAGE_H
