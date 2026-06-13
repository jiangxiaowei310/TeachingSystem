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

signals:
    void addStudentClicked();
    void addTeacherClicked();

private slots:
    void on_AddStudentsquickBtn_clicked();
    void on_AddTeachersquickBtn_clicked();

private:
    Ui::HomePage *ui;
    void loadStudentCount();
    void loadTeacherCount();
    void loadClassCount();
    void loadCollegeCount();
    void loadGenderRatio();
    void loadCollegeStudentCount();
    void loadRecentActivities();

};

#endif // HOMEPAGE_H
