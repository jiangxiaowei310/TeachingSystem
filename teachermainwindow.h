#ifndef TEACHERMAINWINDOW_H
#define TEACHERMAINWINDOW_H

#include <QButtonGroup>
#include <QMainWindow>
#include "teacherhomepage.h"
#include "teachermystudentspage.h"
#include "teachercoursepage.h"
#include "teachergradepage.h"
#include "teacherinfopage.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class TeacherMainWindow;
}
QT_END_NAMESPACE

class TeacherMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TeacherMainWindow(const QString &teacherName, QWidget *parent = nullptr);
    ~TeacherMainWindow();

private slots:
    void on_homeBtn_clicked();
    void on_myStudentsBtn_clicked();
    void on_courseBtn_clicked();
    void on_gradeBtn_clicked();
    void on_infoBtn_clicked();
    void on_logoutBtn_clicked();

private:
    Ui::TeacherMainWindow *ui;
    TeacherHomePage *m_homePage;
    TeacherMyStudentsPage *m_myStudentsPage;
    TeacherCoursePage *m_coursePage;
    TeacherGradePage *m_gradePage;
    TeacherInfoPage *m_infoPage;
    QButtonGroup *m_sidebarGroup;
    QString m_teacherName;
};

#endif // TEACHERMAINWINDOW_H
