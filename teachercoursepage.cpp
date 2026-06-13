#include "teachercoursepage.h"
#include "ui_teachercoursepage.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>
#include <QTableView>
#include <QLineEdit>
#include <QComboBox>
#include <QTabWidget>
#include <QHeaderView>
#include <QSpacerItem>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QGraphicsLayout>
#include <QGraphicsDropShadowEffect>
#include <QScrollArea>
#include <QPainter>

TeacherCoursePage::TeacherCoursePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeacherCoursePage)
{
    ui->setupUi(this);
    loadCourseData();
    loadStudentData();
    setupUI();
    updateCourseDetail(0);
    updatePieChart();
    updateStudentTable();
}

TeacherCoursePage::~TeacherCoursePage()
{
    delete ui;
}

void TeacherCoursePage::setupUI()
{
    this->setStyleSheet(
        "QWidget { background: #f7fafc; font-family: 'Microsoft YaHei', sans-serif; }"
        "QFrame { background: white; border-radius: 8px; }"
        "QPushButton { border: none; border-radius: 6px; padding: 8px 16px; font-size: 13px; cursor: pointer; }"
        "QLineEdit { border: 1px solid #e2e8f0; border-radius: 6px; padding: 8px 12px; background: white; font-size: 13px; }"
        "QLineEdit:focus { border: 1px solid #48bb78; }"
        "QComboBox { border: 1px solid #e2e8f0; border-radius: 6px; padding: 6px 10px; background: white; font-size: 13px; }"
        "QTableView { border: 1px solid #e2e8f0; border-radius: 8px; background: white; gridline-color: #edf2f7; }"
        "QTableView::item { padding: 6px; border-bottom: 1px solid #edf2f7; }"
        "QTableView::item:selected { background: #e6fffa; color: #2d3748; }"
        "QHeaderView::section { background: #48bb78; color: white; padding: 8px; font-weight: bold; border: none; }"
        "QListWidget { border: 1px solid #e2e8f0; border-radius: 8px; background: white; outline: none; }"
        "QListWidget::item { padding: 12px 16px; border-bottom: 1px solid #edf2f7; }"
        "QListWidget::item:selected { background: #48bb78; color: white; border-radius: 6px; margin: 4px; }"
        "QListWidget::item:hover { background: #f0fff4; }"
        "QListWidget::item:selected:hover { background: #48bb78; }"
        "QTabWidget::pane { border: none; background: transparent; }"
        "QTabBar::tab { background: transparent; border: none; padding: 10px 20px; font-size: 14px; color: #718096; }"
        "QTabBar::tab:selected { color: #48bb78; border-bottom: 3px solid #48bb78; font-weight: bold; }"
        "QTabBar::tab:hover { color: #48bb78; }"
    );

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(20, 20, 20, 20);
    mainLayout->setSpacing(16);

    // ===== Header =====
    QFrame *headerFrame = new QFrame(this);
    QHBoxLayout *headerLayout = new QHBoxLayout(headerFrame);
    headerLayout->setContentsMargins(0, 0, 0, 0);

    QLabel *titleLabel = new QLabel("课程管理", headerFrame);
    titleLabel->setStyleSheet("font-size: 20px; font-weight: bold; color: #2d3748; background: transparent;");
    headerLayout->addWidget(titleLabel);
    headerLayout->addStretch();

    m_addBtn = new QPushButton("+ 添加课程资料", headerFrame);
    m_addBtn->setStyleSheet("background: #4299e1; color: white; font-weight: bold; padding: 8px 18px;");
    m_addBtn->setCursor(Qt::PointingHandCursor);
    connect(m_addBtn, &QPushButton::clicked, this, &TeacherCoursePage::on_addBtn_clicked);
    headerLayout->addWidget(m_addBtn);

    m_editBtn = new QPushButton("✏ 编辑大纲", headerFrame);
    m_editBtn->setStyleSheet("background: #ed8936; color: white; font-weight: bold; padding: 8px 18px;");
    m_editBtn->setCursor(Qt::PointingHandCursor);
    connect(m_editBtn, &QPushButton::clicked, this, &TeacherCoursePage::on_editBtn_clicked);
    headerLayout->addWidget(m_editBtn);

    mainLayout->addWidget(headerFrame);

    // ===== Stats Cards =====
    setupStatsCards();
    QHBoxLayout *statsLayout = new QHBoxLayout();
    statsLayout->setSpacing(16);

    QStringList icons = {"📚", "👥", "📁", "📊"};
    QStringList values = {"6", "152", "8", "84.6"};
    QStringList descs = {"我教授的课程\n（门）", "学生总人数\n（人）", "课程资料\n（份）", "平均成绩\n（分）"};
    QList<QString> iconColors = {"#48bb78", "#4299e1", "#9f7aea", "#ecc94b"};

    for (int i = 0; i < 4; ++i) {
        QFrame *card = new QFrame(this);
        card->setStyleSheet("background: white; border-radius: 10px; border: 1px solid #e2e8f0;");
        card->setMinimumHeight(90);
        card->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

        QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(card);
        shadow->setBlurRadius(10);
        shadow->setColor(QColor(0, 0, 0, 30));
        shadow->setOffset(0, 2);
        card->setGraphicsEffect(shadow);

        QHBoxLayout *cardLayout = new QHBoxLayout(card);
        cardLayout->setContentsMargins(16, 12, 16, 12);

        QLabel *iconLabel = new QLabel(icons[i], card);
        iconLabel->setStyleSheet(QString("font-size: 28px; background: transparent; color: %1;").arg(iconColors[i]));
        cardLayout->addWidget(iconLabel);

        QVBoxLayout *textLayout = new QVBoxLayout();
        textLayout->setSpacing(4);

        QLabel *valueLabel = new QLabel(values[i], card);
        valueLabel->setStyleSheet("font-size: 24px; font-weight: bold; color: #2d3748; background: transparent;");
        textLayout->addWidget(valueLabel);
        m_statValueLabels.append(valueLabel);

        QLabel *descLabel = new QLabel(descs[i], card);
        descLabel->setStyleSheet("font-size: 12px; color: #718096; background: transparent;");
        textLayout->addWidget(descLabel);
        m_statDescLabels.append(descLabel);

        cardLayout->addLayout(textLayout);
        cardLayout->addStretch();

        statsLayout->addWidget(card);
    }
    mainLayout->addLayout(statsLayout);

    // ===== Middle Section =====
    QHBoxLayout *middleLayout = new QHBoxLayout();
    middleLayout->setSpacing(16);

    // Left: Course List
    setupCourseList();
    QFrame *courseListFrame = new QFrame(this);
    courseListFrame->setStyleSheet("background: white; border-radius: 10px; border: 1px solid #e2e8f0;");
    courseListFrame->setFixedWidth(220);
    QVBoxLayout *courseListLayout = new QVBoxLayout(courseListFrame);
    courseListLayout->setContentsMargins(12, 12, 12, 12);
    courseListLayout->setSpacing(8);

    QLabel *courseListTitle = new QLabel("我的课程列表", courseListFrame);
    courseListTitle->setStyleSheet("font-size: 14px; font-weight: bold; color: #2d3748; background: transparent;");
    courseListLayout->addWidget(courseListTitle);

    m_courseList = new QListWidget(courseListFrame);
    m_courseList->setFocusPolicy(Qt::NoFocus);
    for (int i = 0; i < m_courses.size(); ++i) {
        const CourseInfo &c = m_courses[i];
        QListWidgetItem *item = new QListWidgetItem();
        item->setText(QString("%1  %2\n%3  %4人").arg(c.code).arg(c.name).arg(c.className).arg(c.studentCount));
        m_courseList->addItem(item);
    }
    m_courseList->setCurrentRow(0);
    connect(m_courseList, &QListWidget::currentRowChanged, this, &TeacherCoursePage::on_courseList_currentRowChanged);
    courseListLayout->addWidget(m_courseList);

    m_refreshBtn = new QPushButton("⟳ 刷新列表", courseListFrame);
    m_refreshBtn->setStyleSheet("background: transparent; color: #4299e1; border: 1px solid #e2e8f0; font-size: 13px;");
    m_refreshBtn->setCursor(Qt::PointingHandCursor);
    connect(m_refreshBtn, &QPushButton::clicked, this, &TeacherCoursePage::on_refreshBtn_clicked);
    courseListLayout->addWidget(m_refreshBtn);

    middleLayout->addWidget(courseListFrame);

    // Right: Course Detail + Tabs
    QVBoxLayout *rightLayout = new QVBoxLayout();
    rightLayout->setSpacing(16);

    // Course Detail + Pie Chart
    QHBoxLayout *detailChartLayout = new QHBoxLayout();
    detailChartLayout->setSpacing(16);

    // Course Detail Card
    QFrame *detailFrame = new QFrame(this);
    detailFrame->setStyleSheet("background: white; border-radius: 10px; border: 1px solid #e2e8f0;");
    QVBoxLayout *detailFrameLayout = new QVBoxLayout(detailFrame);
    detailFrameLayout->setContentsMargins(16, 16, 16, 16);

    QLabel *detailTitle = new QLabel("课程详情", detailFrame);
    detailTitle->setStyleSheet("font-size: 14px; font-weight: bold; color: #2d3748; background: transparent; margin-bottom: 8px;");
    detailFrameLayout->addWidget(detailTitle);

    QGridLayout *detailGrid = new QGridLayout();
    detailGrid->setSpacing(12);
    detailGrid->setColumnStretch(1, 1);
    detailGrid->setColumnStretch(3, 1);

    auto addDetailRow = [&](int row, int col, const QString &label, QLabel *&valueLabel) {
        QLabel *lbl = new QLabel(label, detailFrame);
        lbl->setStyleSheet("font-size: 13px; color: #718096; background: transparent;");
        valueLabel = new QLabel("", detailFrame);
        valueLabel->setStyleSheet("font-size: 13px; color: #2d3748; background: transparent;");
        detailGrid->addWidget(lbl, row, col);
        detailGrid->addWidget(valueLabel, row, col + 1);
    };

    addDetailRow(0, 0, "课程编号：", m_detailCode);
    addDetailRow(0, 2, "授课班级：", m_detailClass);
    addDetailRow(1, 0, "课程名称：", m_detailName);
    addDetailRow(1, 2, "学生人数：", m_detailCount);
    addDetailRow(2, 0, "学    分：", m_detailCredits);
    addDetailRow(2, 2, "平均成绩：", m_detailAvg);
    addDetailRow(3, 0, "总 学 时：", m_detailHours);
    addDetailRow(3, 2, "课程状态：", m_detailStatus);
    addDetailRow(4, 0, "开课学期：", m_detailSemester);

    detailFrameLayout->addLayout(detailGrid);
    detailFrameLayout->addStretch();
    detailChartLayout->addWidget(detailFrame, 1);

    // Pie Chart
    QFrame *chartFrame = new QFrame(this);
    chartFrame->setStyleSheet("background: white; border-radius: 10px; border: 1px solid #e2e8f0;");
    QVBoxLayout *chartFrameLayout = new QVBoxLayout(chartFrame);
    chartFrameLayout->setContentsMargins(16, 16, 16, 16);

    QLabel *chartTitle = new QLabel("成绩分布", chartFrame);
    chartTitle->setStyleSheet("font-size: 14px; font-weight: bold; color: #2d3748; background: transparent;");
    chartFrameLayout->addWidget(chartTitle);

    m_chartView = new QChartView(chartFrame);
    m_chartView->setRenderHint(QPainter::Antialiasing);
    m_chartView->setMinimumHeight(200);
    m_chartView->setStyleSheet("background: transparent; border: none;");
    chartFrameLayout->addWidget(m_chartView, 1);
    detailChartLayout->addWidget(chartFrame, 1);

    rightLayout->addLayout(detailChartLayout, 1);

    // Bottom Tabs
    m_tabWidget = new QTabWidget(this);
    m_tabWidget->setDocumentMode(true);
    m_tabWidget->tabBar()->setExpanding(false);

    QWidget *studentTab = new QWidget();
    QVBoxLayout *studentTabLayout = new QVBoxLayout(studentTab);
    studentTabLayout->setContentsMargins(0, 12, 0, 0);
    studentTabLayout->setSpacing(12);

    // Search bar
    QHBoxLayout *searchLayout = new QHBoxLayout();
    m_searchEdit = new QLineEdit(studentTab);
    m_searchEdit->setPlaceholderText("请输入学生姓名或学号");
    m_searchEdit->setMinimumWidth(300);
    searchLayout->addWidget(m_searchEdit);

    m_searchBtn = new QPushButton("搜索", studentTab);
    m_searchBtn->setStyleSheet("background: #48bb78; color: white; font-weight: bold; padding: 8px 24px;");
    m_searchBtn->setCursor(Qt::PointingHandCursor);
    connect(m_searchBtn, &QPushButton::clicked, this, &TeacherCoursePage::on_searchBtn_clicked);
    searchLayout->addWidget(m_searchBtn);
    searchLayout->addStretch();
    studentTabLayout->addLayout(searchLayout);

    // Student Table
    m_studentTable = new QTableView(studentTab);
    m_studentTable->setSelectionMode(QAbstractItemView::SingleSelection);
    m_studentTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_studentTable->setAlternatingRowColors(true);
    m_studentTable->horizontalHeader()->setStretchLastSection(true);
    m_studentTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    m_studentTable->verticalHeader()->setVisible(false);
    m_studentTable->setShowGrid(false);
    m_studentTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    m_studentModel = new QStandardItemModel(this);
    m_studentModel->setHorizontalHeaderLabels(
        QStringList() << "学号" << "姓名" << "性别" << "班级" << "电话" << "邮箱"
                      << "平时成绩" << "期末成绩" << "总评成绩" << "操作"
    );
    m_studentTable->setModel(m_studentModel);
    studentTabLayout->addWidget(m_studentTable, 1);

    // Pagination
    setupPagination();
    QHBoxLayout *pageLayout = new QHBoxLayout();
    m_totalLabel = new QLabel("共56条", studentTab);
    m_totalLabel->setStyleSheet("color: #718096; font-size: 13px;");
    pageLayout->addWidget(m_totalLabel);
    pageLayout->addStretch();

    m_prevPageBtn = new QPushButton("上一页", studentTab);
    m_prevPageBtn->setStyleSheet("background: transparent; color: #718096; border: 1px solid #e2e8f0; padding: 6px 14px;");
    m_prevPageBtn->setCursor(Qt::PointingHandCursor);
    connect(m_prevPageBtn, &QPushButton::clicked, this, &TeacherCoursePage::on_prevPageBtn_clicked);
    pageLayout->addWidget(m_prevPageBtn);

    m_pageLabel = new QLabel("1 / 6", studentTab);
    m_pageLabel->setStyleSheet("color: #2d3748; font-size: 13px; padding: 0 12px;");
    pageLayout->addWidget(m_pageLabel);

    m_nextPageBtn = new QPushButton("下一页", studentTab);
    m_nextPageBtn->setStyleSheet("background: transparent; color: #718096; border: 1px solid #e2e8f0; padding: 6px 14px;");
    m_nextPageBtn->setCursor(Qt::PointingHandCursor);
    connect(m_nextPageBtn, &QPushButton::clicked, this, &TeacherCoursePage::on_nextPageBtn_clicked);
    pageLayout->addWidget(m_nextPageBtn);

    pageLayout->addSpacing(20);

    m_pageSizeCombo = new QComboBox(studentTab);
    m_pageSizeCombo->addItems(QStringList() << "10条/页" << "20条/页" << "50条/页");
    m_pageSizeCombo->setCurrentIndex(0);
    pageLayout->addWidget(m_pageSizeCombo);

    studentTabLayout->addLayout(pageLayout);

    m_tabWidget->addTab(studentTab, "学生列表");
    m_tabWidget->addTab(new QWidget(), "课程资料");
    m_tabWidget->addTab(new QWidget(), "作业列表");
    m_tabWidget->addTab(new QWidget(), "成绩统计");

    rightLayout->addWidget(m_tabWidget, 2);
    middleLayout->addLayout(rightLayout, 1);

    mainLayout->addLayout(middleLayout, 1);
}

void TeacherCoursePage::setupStatsCards() {}
void TeacherCoursePage::setupCourseList() {}
void TeacherCoursePage::setupCourseDetail() {}
void TeacherCoursePage::setupPieChart() {}
void TeacherCoursePage::setupStudentTable() {}
void TeacherCoursePage::setupPagination() {}

void TeacherCoursePage::loadCourseData()
{
    m_courses = {
        {"C001", "C++程序设计", "软件工程2201班", 56, 4, 64, 84.6, "2025-2026学年 第2学期", "正常"},
        {"C002", "数据结构", "软件工程2202班", 48, 3, 48, 82.3, "2025-2026学年 第2学期", "正常"},
        {"C003", "数据库原理", "软件工程2201班", 56, 3, 48, 81.5, "2025-2026学年 第2学期", "正常"},
        {"C004", "Java程序设计", "软件工程2203班", 52, 4, 64, 83.1, "2025-2026学年 第2学期", "正常"},
        {"C005", "操作系统", "软件工程2204班", 40, 4, 64, 85.2, "2025-2026学年 第2学期", "正常"},
        {"C006", "计算机网络", "软件工程2202班", 46, 3, 48, 80.8, "2025-2026学年 第2学期", "正常"},
    };
}

void TeacherCoursePage::loadStudentData()
{
    m_students = {
        {"20221001", "张三", "男", "软件工程2201班", "13800138000", "zhangsan@qq.com", 85, 90, 87.5},
        {"20221002", "李四", "女", "软件工程2201班", "13800138001", "lisi@qq.com", 78, 88, 83.0},
        {"20221003", "王五", "男", "软件工程2201班", "13800138002", "wangwu@qq.com", 92, 93, 92.5},
        {"20221004", "赵六", "女", "软件工程2201班", "13800138003", "zhaoliu@qq.com", 88, 87, 87.5},
        {"20221005", "孙七", "男", "软件工程2201班", "13800138004", "sunqi@qq.com", 76, 82, 79.0},
    };
    for (int i = 6; i <= 56; ++i) {
        m_students.append({
            QString("202210%1").arg(i, 2, 10, QChar('0')),
            QString("学生%1").arg(i),
            i % 2 == 0 ? "女" : "男",
            "软件工程2201班",
            QString("13800138%1").arg(i, 2, 10, QChar('0')),
            QString("student%1@qq.com").arg(i),
            70.0 + (i % 20),
            75.0 + (i % 15),
            73.0 + (i % 18)
        });
    }
    m_filteredStudents = m_students;
}

void TeacherCoursePage::updateCourseDetail(int index)
{
    if (index < 0 || index >= m_courses.size()) return;
    const CourseInfo &c = m_courses[index];
    m_detailCode->setText(c.code);
    m_detailClass->setText(c.className);
    m_detailName->setText(c.name);
    m_detailCount->setText(QString::number(c.studentCount) + " 人");
    m_detailCredits->setText(QString::number(c.credits));
    m_detailAvg->setText(QString::number(c.avgScore, 'f', 1) + " 分");
    m_detailHours->setText(QString::number(c.totalHours));
    m_detailStatus->setText(c.status);
    m_detailStatus->setStyleSheet(
        "font-size: 12px; color: #48bb78; background: #f0fff4; padding: 2px 10px; border-radius: 4px; border: 1px solid #9ae6b4;"
    );
    m_detailSemester->setText(c.semester);
}

void TeacherCoursePage::updatePieChart()
{
    if (!m_pieSeries) {
        m_pieSeries = new QPieSeries(this);
    }
    m_pieSeries->clear();

    // Hardcoded distribution for C001
    m_pieSeries->append("优秀(90-100)   18人(32.14%)", 18);
    m_pieSeries->append("良好(80-89)   22人(39.29%)", 22);
    m_pieSeries->append("中等(70-79)   10人(17.86%)", 10);
    m_pieSeries->append("及格(60-69)   4人(7.14%)", 4);
    m_pieSeries->append("不及格(<60)   2人(3.57%)", 2);

    QList<QColor> colors = {
        QColor("#48bb78"), QColor("#4299e1"), QColor("#ecc94b"),
        QColor("#9f7aea"), QColor("#f56565")
    };
    for (int i = 0; i < m_pieSeries->slices().size(); ++i) {
        QPieSlice *slice = m_pieSeries->slices().at(i);
        slice->setColor(colors[i]);
        slice->setLabelVisible(false);
        slice->setBorderColor(Qt::white);
        slice->setBorderWidth(2);
    }
    m_pieSeries->setHoleSize(0.45);

    QChart *chart = new QChart();
    chart->addSeries(m_pieSeries);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->legend()->setFont(QFont("Microsoft YaHei", 11));
    chart->setBackgroundVisible(false);
    chart->setPlotAreaBackgroundVisible(false);
    chart->layout()->setContentsMargins(0, 0, 0, 0);

    m_chartView->setChart(chart);
}

void TeacherCoursePage::updateStudentTable()
{
    m_studentModel->removeRows(0, m_studentModel->rowCount());

    int start = (m_currentPage - 1) * m_pageSize;
    int end = qMin(start + m_pageSize, m_filteredStudents.size());

    for (int i = start; i < end; ++i) {
        const StudentInfo &s = m_filteredStudents[i];
        int row = i - start;
        m_studentModel->setItem(row, 0, new QStandardItem(s.id));
        m_studentModel->setItem(row, 1, new QStandardItem(s.name));
        m_studentModel->setItem(row, 2, new QStandardItem(s.gender));
        m_studentModel->setItem(row, 3, new QStandardItem(s.className));
        m_studentModel->setItem(row, 4, new QStandardItem(s.phone));
        m_studentModel->setItem(row, 5, new QStandardItem(s.email));
        m_studentModel->setItem(row, 6, new QStandardItem(QString::number(s.usualScore, 'f', 0)));
        m_studentModel->setItem(row, 7, new QStandardItem(QString::number(s.finalScore, 'f', 0)));
        m_studentModel->setItem(row, 8, new QStandardItem(QString::number(s.totalScore, 'f', 1)));

        QStandardItem *opItem = new QStandardItem("录入成绩");
        opItem->setForeground(QColor("#4299e1"));
        opItem->setFont(QFont("Microsoft YaHei", 11, QFont::Bold));
        m_studentModel->setItem(row, 9, opItem);
    }

    m_totalPages = qMax(1, (m_filteredStudents.size() + m_pageSize - 1) / m_pageSize);
    m_totalLabel->setText(QString("共 %1 条").arg(m_filteredStudents.size()));
    m_pageLabel->setText(QString("%1 / %2").arg(m_currentPage).arg(m_totalPages));
    m_prevPageBtn->setEnabled(m_currentPage > 1);
    m_nextPageBtn->setEnabled(m_currentPage < m_totalPages);
}

void TeacherCoursePage::on_addBtn_clicked() {}
void TeacherCoursePage::on_editBtn_clicked() {}

void TeacherCoursePage::on_refreshBtn_clicked()
{
    m_courseList->setCurrentRow(0);
}

void TeacherCoursePage::on_searchBtn_clicked()
{
    QString keyword = m_searchEdit->text().trimmed();
    m_filteredStudents.clear();
    if (keyword.isEmpty()) {
        m_filteredStudents = m_students;
    } else {
        for (const StudentInfo &s : m_students) {
            if (s.name.contains(keyword) || s.id.contains(keyword)) {
                m_filteredStudents.append(s);
            }
        }
    }
    m_currentPage = 1;
    updateStudentTable();
}

void TeacherCoursePage::on_courseList_currentRowChanged(int currentRow)
{
    m_currentCourseIndex = currentRow;
    updateCourseDetail(currentRow);
    updatePieChart();
}

void TeacherCoursePage::on_tabBar_currentChanged(int index)
{
    Q_UNUSED(index)
}

void TeacherCoursePage::on_enterGradeClicked() {}

void TeacherCoursePage::on_prevPageBtn_clicked()
{
    if (m_currentPage > 1) {
        --m_currentPage;
        updateStudentTable();
    }
}

void TeacherCoursePage::on_nextPageBtn_clicked()
{
    if (m_currentPage < m_totalPages) {
        ++m_currentPage;
        updateStudentTable();
    }
}
