#include "homepage.h"
#include "ui_homepage.h"
#include <QSqlQuery>
#include <QSqlError>

HomePage::HomePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomePage)
{
    ui->setupUi(this);
    loadStatistics();
}

HomePage::~HomePage()
{
    delete ui;
}
//一次性调用所有数据加载方法
void HomePage::loadStatistics()
{
    loadStudentCount();
    loadTeacherCount();
    loadClassCount();
    loadCollegeCount();
    loadGenderRatio();
    loadCollegeStudentCount();
    loadRecentActivities();
}

void HomePage::loadStudentCount()
{
    QSqlQuery query("SELECT COUNT(*) FROM students");
    if (query.exec() && query.next()) {
        ui->studentCount->setText(query.value(0).toString());
    } else {
        ui->studentCount->setText("0");
    }
}

void HomePage::loadTeacherCount()
{
    QSqlQuery query("SELECT COUNT(*) FROM teachers");
    if (query.exec() && query.next()) {
        ui->teacherCount->setText(query.value(0).toString());
    } else {
        ui->teacherCount->setText("0");
    }
}

void HomePage::loadClassCount()
{
    QSqlQuery query("SELECT COUNT(*) FROM classes");
    if (query.exec() && query.next()) {
        ui->classCount->setText(query.value(0).toString());
    } else {
        ui->classCount->setText("0");
    }
}

void HomePage::loadCollegeCount()
{
    QSqlQuery query("SELECT COUNT(*) FROM colleges");
    if (query.exec() && query.next()) {
        ui->collegeCount->setText(query.value(0).toString());
    } else {
        ui->collegeCount->setText("0");
    }
}

void HomePage::loadGenderRatio()
{
    QSqlQuery query("SELECT gender, COUNT(*) FROM students GROUP BY gender");
    int maleCount = 0;
    int femaleCount = 0;

    while (query.next()) {
        QString gender = query.value(0).toString();
        int count = query.value(1).toInt();
        if (gender == "男" || gender == "male") {
            maleCount = count;
        } else if (gender == "女" || gender == "female") {
            femaleCount = count;
        }
    }

    int total = maleCount + femaleCount;
    int malePercent = total > 0 ? (maleCount * 100) / total : 0;
    int femalePercent = total > 0 ? (femaleCount * 100) / total : 0;

    QString chartText = QString(R"(
性别比例
┌─────────────────────────┐
│    男: %1%  %2│
│    女: %3%  %4│
└─────────────────────────┘
)").arg(malePercent).arg(QString("█").repeated(malePercent / 5 + 1).leftJustified(16)).arg(femalePercent).arg(QString("█").repeated(femalePercent / 5 + 1).leftJustified(16));

    ui->pieChart->setText(chartText);
}

void HomePage::loadCollegeStudentCount()
{
    QSqlQuery query(R"(
        SELECT c.college_name, COUNT(s.student_id) as count
        FROM colleges c
        LEFT JOIN students s ON c.college_id = s.college_id
        GROUP BY c.college_id, c.college_name
        ORDER BY count DESC
    )");

    QString chartText = "学院人数\n─────────────────────────────────────\n";
    int maxCount = 0;

    while (query.next()) {
        int count = query.value(1).toInt();
        if (count > maxCount) maxCount = count;
    }

    query.exec();
    while (query.next()) {
        QString collegeName = query.value(0).toString();
        int count = query.value(1).toInt();
        int barLength = maxCount > 0 ? (count * 20) / maxCount : 0;
        chartText += QString("%1 %2 %3\n").arg(collegeName.leftJustified(12)).arg(QString("█").repeated(barLength)).arg(count);
    }
    chartText += "─────────────────────────────────────";

    ui->barChart->setText(chartText);
}

void HomePage::loadRecentActivities()
{
    QString activities = R"(
• 系统已启动，数据已加载
• 欢迎使用学生管理系统
• 今日数据已更新
)";
    ui->recentList->setText(activities.trimmed());
}

void HomePage::on_AddStudentsquickBtn_clicked()
{
    emit addStudentClicked();
}

void HomePage::on_AddTeachersquickBtn_clicked()
{
    emit addTeacherClicked();
}
