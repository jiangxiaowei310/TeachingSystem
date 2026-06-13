#ifndef STUDENTMAINWINDOW_H
#define STUDENTMAINWINDOW_H

#include <QButtonGroup>
#include <QMainWindow>
#include "studenthomepage.h"
#include "studentcoursepage.h"
#include "studentgradepage.h"
#include "studentschedulepage.h"
#include "studentinfopage.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class StudentMainWindow;
}
QT_END_NAMESPACE

class StudentMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentMainWindow(const QString &studentName, QWidget *parent = nullptr);
    ~StudentMainWindow();

private slots:
    void on_homeBtn_clicked();
    void on_courseBtn_clicked();
    void on_gradeBtn_clicked();
    void on_scheduleBtn_clicked();
    void on_infoBtn_clicked();
    void on_logoutBtn_clicked();

private:
    Ui::StudentMainWindow *ui;
    StudentHomePage *m_homePage;
    StudentCoursePage *m_coursePage;
    StudentGradePage *m_gradePage;
    StudentSchedulePage *m_schedulePage;
    StudentInfoPage *m_infoPage;
    QButtonGroup *m_sidebarGroup;
    QString m_studentName;
};

#endif // STUDENTMAINWINDOW_H
