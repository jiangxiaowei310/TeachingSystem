#ifndef TEACHERCOURSEPAGE_H
#define TEACHERCOURSEPAGE_H

#include <QWidget>
#include <QListWidget>
#include <QTableView>
#include <QStandardItemModel>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QTabWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class TeacherCoursePage; }
QT_END_NAMESPACE

QT_BEGIN_NAMESPACE
class QChartView;
class QPieSeries;
QT_END_NAMESPACE

struct CourseInfo {
    QString code;
    QString name;
    QString className;
    int studentCount;
    int credits;
    int totalHours;
    double avgScore;
    QString semester;
    QString status;
};

struct StudentInfo {
    QString id;
    QString name;
    QString gender;
    QString className;
    QString phone;
    QString email;
    double usualScore;
    double finalScore;
    double totalScore;
};

class TeacherCoursePage : public QWidget
{
    Q_OBJECT

public:
    explicit TeacherCoursePage(QWidget *parent = nullptr);
    ~TeacherCoursePage();

private slots:
    void on_addBtn_clicked();
    void on_editBtn_clicked();
    void on_refreshBtn_clicked();
    void on_searchBtn_clicked();
    void on_courseList_currentRowChanged(int currentRow);
    void on_tabBar_currentChanged(int index);
    void on_enterGradeClicked();
    void on_prevPageBtn_clicked();
    void on_nextPageBtn_clicked();

private:
    void setupUI();
    void setupStatsCards();
    void setupCourseList();
    void setupCourseDetail();
    void setupPieChart();
    void setupStudentTable();
    void setupPagination();
    void loadCourseData();
    void loadStudentData();
    void updateCourseDetail(int index);
    void updatePieChart();
    void updateStudentTable();

    Ui::TeacherCoursePage *ui;

    // Header
    QPushButton *m_addBtn = nullptr;
    QPushButton *m_editBtn = nullptr;

    // Stats cards
    QList<QLabel*> m_statValueLabels;
    QList<QLabel*> m_statDescLabels;

    // Course list
    QListWidget *m_courseList = nullptr;
    QPushButton *m_refreshBtn = nullptr;
    QList<CourseInfo> m_courses;
    int m_currentCourseIndex = 0;

    // Course detail
    QLabel *m_detailCode = nullptr;
    QLabel *m_detailClass = nullptr;
    QLabel *m_detailName = nullptr;
    QLabel *m_detailCount = nullptr;
    QLabel *m_detailCredits = nullptr;
    QLabel *m_detailAvg = nullptr;
    QLabel *m_detailHours = nullptr;
    QLabel *m_detailStatus = nullptr;
    QLabel *m_detailSemester = nullptr;

    // Pie chart
    QChartView *m_chartView = nullptr;
    QPieSeries *m_pieSeries = nullptr;

    // Tabs and student table
    QTabWidget *m_tabWidget = nullptr;
    QLineEdit *m_searchEdit = nullptr;
    QPushButton *m_searchBtn = nullptr;
    QTableView *m_studentTable = nullptr;
    QStandardItemModel *m_studentModel = nullptr;
    QList<StudentInfo> m_students;
    QList<StudentInfo> m_filteredStudents;

    // Pagination
    QLabel *m_totalLabel = nullptr;
    QPushButton *m_prevPageBtn = nullptr;
    QPushButton *m_nextPageBtn = nullptr;
    QLabel *m_pageLabel = nullptr;
    QComboBox *m_pageSizeCombo = nullptr;
    int m_currentPage = 1;
    int m_pageSize = 10;
    int m_totalPages = 1;
};

#endif // TEACHERCOURSEPAGE_H
