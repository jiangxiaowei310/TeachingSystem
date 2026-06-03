#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QButtonGroup>
#include <QMainWindow>
#include "homepage.h"
#include "studentpage.h"
#include "teacherpage.h"
#include "classpage.h"
#include "majorpage.h"
#include "collegepage.h"
#include "userpage.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class HomePage;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_homeBtn_clicked();
    void on_studentBtn_clicked();
    void on_teacherBtn_clicked();
    void on_classBtn_clicked();
    void on_majorBtn_clicked();
    void on_collegeBtn_clicked();
    void on_userBtn_clicked();

private:
    Ui::MainWindow *ui;
    HomePage *m_homePage;
    StudentPage *m_studentPage;
    TeacherPage *m_teacherPage;
    ClassPage *m_classPage;
    MajorPage *m_majorPage;
    CollegePage *m_collegePage;
    UserPage *m_userPage;
    QButtonGroup *m_sidebarGroup; // 侧边栏按钮组
};
#endif // MAINWINDOW_H
