#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>

class MainWindow;

namespace Ui {
class HomePage;
}

class HomePage : public QWidget
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = nullptr);
    ~HomePage();

    void loadStatistics();

private slots:
    void on_AddStudentsquickBtn_clicked();


    void on_AddTeachersquickBtn_clicked();

private:
    Ui::HomePage *ui;
};

#endif // HOMEPAGE_H
