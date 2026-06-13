#ifndef STUDENTSCHEDULEPAGE_H
#define STUDENTSCHEDULEPAGE_H

#include <QDate>
#include <QWidget>

namespace Ui {
class StudentSchedulePage;
}

class StudentSchedulePage : public QWidget
{
    Q_OBJECT
private:
    QString m_stuNo;          // 当前登录学生学号
    QString m_username;
    QDate m_termStart;        // 开学日期（第1周周一）
    // 计算今天是本学期第几周
    int getCurrentWeek();
    // 加载指定周的课表
    void loadSchedule(int weekNo);
    void debugPrintAllCourses();  // 调试用
    void on_weekCombo_currentIndexChanged(int index);
public:
    explicit StudentSchedulePage(QWidget *parent = nullptr);
    ~StudentSchedulePage();
    void setUsername(const QString &username); // 设置学号接口

private:
    Ui::StudentSchedulePage *ui;
};

#endif // STUDENTSCHEDULEPAGE_H
