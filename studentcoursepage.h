#ifndef STUDENTCOURSEPAGE_H
#define STUDENTCOURSEPAGE_H

#include <QWidget>
#include <QStandardItemModel>
#include <QSqlDatabase>

namespace Ui {
class StudentCoursePage;
}

class StudentCoursePage : public QWidget
{
    Q_OBJECT

public:
    explicit StudentCoursePage(QWidget *parent = nullptr);
    ~StudentCoursePage();
    void setUsername(const QString &username);  // 设置学号
    void switchToSelected();
    void switchToAvailable();

private slots:
    void on_selectBtn_clicked();   // 选课按钮
    void on_dropBtn_clicked();     // 退课按钮
    void loadSelectedCourses();    // 加载已选课程
    void loadAvailableCourses();   // 加载可选课程

private:
    Ui::StudentCoursePage *ui;
    QString m_username;           // 当前学生学号
    QStandardItemModel *m_selectedModel;   // 已选课程模型
    QStandardItemModel *m_availableModel;  // 可选课程模型
    QSqlDatabase getDatabase();            // 获取数据库连接
};

#endif // STUDENTCOURSEPAGE_H
