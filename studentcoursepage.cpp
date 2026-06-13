#include "studentcoursepage.h"
#include "ui_studentcoursepage.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

StudentCoursePage::StudentCoursePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentCoursePage),
    m_selectedModel(new QStandardItemModel(this)),
    m_availableModel(new QStandardItemModel(this))
{
    ui->setupUi(this);
    
    // 设置可选课程表的列标题
    m_availableModel->setColumnCount(7);
    m_availableModel->setHeaderData(0, Qt::Horizontal, "课程ID");
    m_availableModel->setHeaderData(1, Qt::Horizontal, "课程名称");
    m_availableModel->setHeaderData(2, Qt::Horizontal, "授课教师");
    m_availableModel->setHeaderData(3, Qt::Horizontal, "上课时间");
    m_availableModel->setHeaderData(4, Qt::Horizontal, "教室");
    m_availableModel->setHeaderData(5, Qt::Horizontal, "最大人数");
    m_availableModel->setHeaderData(6, Qt::Horizontal, "已选人数");
    
    // 设置已选课程表的列标题
    m_selectedModel->setColumnCount(6);
    m_selectedModel->setHeaderData(0, Qt::Horizontal, "课程ID");
    m_selectedModel->setHeaderData(1, Qt::Horizontal, "课程名称");
    m_selectedModel->setHeaderData(2, Qt::Horizontal, "授课教师");
    m_selectedModel->setHeaderData(3, Qt::Horizontal, "上课时间");
    m_selectedModel->setHeaderData(4, Qt::Horizontal, "教室");
    m_selectedModel->setHeaderData(5, Qt::Horizontal, "最大人数");
    
    // 设置表格模型
    ui->availableTableView->setModel(m_availableModel);
    ui->selectedTableView->setModel(m_selectedModel);
}

StudentCoursePage::~StudentCoursePage()
{
    delete ui;
}

void StudentCoursePage::setUsername(const QString &username)
{
    m_username = username;
    loadAvailableCourses();  // 加载可选课程
    loadSelectedCourses();   // 加载已选课程
}

QSqlDatabase StudentCoursePage::getDatabase()
{
    QSqlDatabase db;
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        db = QSqlDatabase::database("qt_sql_default_connection");
    } else {
        db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("localhost");
        db.setDatabaseName("管理系统");
        db.setUserName("root");
        db.setPassword("123456");
        db.setPort(3306);
    }
    
    if (!db.isOpen() && !db.open()) {
        QMessageBox::warning(this, "错误", "数据库连接失败！\n" + db.lastError().text());
    }
    
    return db;
}

void StudentCoursePage::loadSelectedCourses()
{
    if (m_username.isEmpty()) {
        QMessageBox::warning(this, "错误", "请先登录！");
        return;
    }
    
    QSqlDatabase db = getDatabase();
    if (!db.isOpen()) return;
    
    // 清空模型
    m_selectedModel->clear();
    m_selectedModel->setColumnCount(6);
    m_selectedModel->setHeaderData(0, Qt::Horizontal, "课程ID");
    m_selectedModel->setHeaderData(1, Qt::Horizontal, "课程名称");
    m_selectedModel->setHeaderData(2, Qt::Horizontal, "授课教师");
    m_selectedModel->setHeaderData(3, Qt::Horizontal, "上课时间");
    m_selectedModel->setHeaderData(4, Qt::Horizontal, "教室");
    m_selectedModel->setHeaderData(5, Qt::Horizontal, "最大人数");
    
    // 查询学生已选的选修课
    QString sql = R"(
        SELECT ec.elective_id, ec.course_name, t.name, ec.week_day, ec.section, ec.classroom, ec.max_student
        FROM student_elective se
        JOIN elective_courses ec ON se.elective_id = ec.elective_id
        LEFT JOIN teachers t ON ec.teacher_id = t.teacher_id
        WHERE se.stu_no = ?
    )";
    
    QSqlQuery q(db);
    q.prepare(sql);
    q.addBindValue(m_username);
    
    if (!q.exec()) {
        qDebug() << "查询已选课程失败:" << q.lastError().text();
        QMessageBox::warning(this, "错误", "查询已选课程失败！\n" + q.lastError().text());
        return;
    }
    
    QStringList weekDays = {"", "周一", "周二", "周三", "周四", "周五"};
    
    while (q.next()) {
        QString day = weekDays[q.value("week_day").toInt()];
        QString time = day + " " + q.value("section").toString();
        
        m_selectedModel->appendRow({
            new QStandardItem(q.value("elective_id").toString()),
            new QStandardItem(q.value("course_name").toString()),
            new QStandardItem(q.value("name").toString()),
            new QStandardItem(time),
            new QStandardItem(q.value("classroom").toString()),
            new QStandardItem(q.value("max_student").toString())
        });
    }
    
    ui->selectedTableView->resizeColumnsToContents();
}

void StudentCoursePage::loadAvailableCourses()
{
    if (m_username.isEmpty()) {
        QMessageBox::warning(this, "错误", "请先登录！");
        return;
    }
    
    QSqlDatabase db = getDatabase();
    if (!db.isOpen()) return;
    
    // 清空模型
    m_availableModel->clear();
    m_availableModel->setColumnCount(7);
    m_availableModel->setHeaderData(0, Qt::Horizontal, "课程ID");
    m_availableModel->setHeaderData(1, Qt::Horizontal, "课程名称");
    m_availableModel->setHeaderData(2, Qt::Horizontal, "授课教师");
    m_availableModel->setHeaderData(3, Qt::Horizontal, "上课时间");
    m_availableModel->setHeaderData(4, Qt::Horizontal, "教室");
    m_availableModel->setHeaderData(5, Qt::Horizontal, "最大人数");
    m_availableModel->setHeaderData(6, Qt::Horizontal, "已选人数");
    
    // 查询所有可选课程及已选人数，排除已选的课程
    QString sql = R"(
        SELECT ec.elective_id, ec.course_name, t.name, ec.week_day, ec.section, 
               ec.classroom, ec.max_student, 
               COALESCE(se_count.selected_count, 0) AS selected_count
        FROM elective_courses ec
        LEFT JOIN teachers t ON ec.teacher_id = t.teacher_id
        LEFT JOIN (
            SELECT elective_id, COUNT(*) AS selected_count
            FROM student_elective
            GROUP BY elective_id
        ) se_count ON ec.elective_id = se_count.elective_id
        WHERE ec.elective_id NOT IN (
            SELECT elective_id FROM student_elective WHERE stu_no = ?
        )
    )";
    
    QSqlQuery q(db);
    q.prepare(sql);
    q.addBindValue(m_username);
    
    if (!q.exec()) {
        qDebug() << "查询可选课程失败:" << q.lastError().text();
        QMessageBox::warning(this, "错误", "查询可选课程失败！\n" + q.lastError().text());
        return;
    }
    
    QStringList weekDays = {"", "周一", "周二", "周三", "周四", "周五"};
    
    while (q.next()) {
        QString day = weekDays[q.value("week_day").toInt()];
        QString time = day + " " + q.value("section").toString();
        
        m_availableModel->appendRow({
            new QStandardItem(q.value("elective_id").toString()),
            new QStandardItem(q.value("course_name").toString()),
            new QStandardItem(q.value("name").toString()),
            new QStandardItem(time),
            new QStandardItem(q.value("classroom").toString()),
            new QStandardItem(q.value("max_student").toString()),
            new QStandardItem(q.value("selected_count").toString())
        });
    }
    
    ui->availableTableView->resizeColumnsToContents();
}

void StudentCoursePage::on_selectBtn_clicked()
{
    // 获取可选课程表中的选中项
    QModelIndexList selected = ui->availableTableView->selectionModel()->selectedRows();
    if (selected.isEmpty()) {
        QMessageBox::warning(this, "提示", "请先从可选课程列表中选择要选的课程！");
        return;
    }
    
    // 获取课程信息
    QString electiveId = m_availableModel->data(m_availableModel->index(selected.first().row(), 0)).toString();
    QString courseName = m_availableModel->data(m_availableModel->index(selected.first().row(), 1)).toString();
    int maxStudent = m_availableModel->data(m_availableModel->index(selected.first().row(), 5)).toInt();
    int selectedCount = m_availableModel->data(m_availableModel->index(selected.first().row(), 6)).toInt();
    
    // 检查是否已满
    if (selectedCount >= maxStudent) {
        QMessageBox::warning(this, "提示", "该课程已选满！");
        return;
    }
    
    // 确认选课
    QMessageBox::StandardButton reply = QMessageBox::question(this, "确认选课",
        QString("确定要选择课程「%1」吗？").arg(courseName),
        QMessageBox::Yes | QMessageBox::No);
    
    if (reply != QMessageBox::Yes) return;
    
    // 插入选课记录
    QSqlDatabase db = getDatabase();
    if (!db.isOpen()) return;
    
    QSqlQuery q(db);
    QString sql = "INSERT INTO student_elective (stu_no, elective_id) VALUES (?, ?)";
    q.prepare(sql);
    q.addBindValue(m_username);
    q.addBindValue(electiveId);
    
    if (q.exec()) {
        QMessageBox::information(this, "成功", "选课成功！");
        loadAvailableCourses();  // 刷新可选课程列表
        loadSelectedCourses();   // 刷新已选课程列表
    } else {
        QMessageBox::warning(this, "失败", "选课失败！\n" + q.lastError().text());
    }
}

void StudentCoursePage::on_dropBtn_clicked()
{
    // 获取已选课程表中的选中项
    QModelIndexList selected = ui->selectedTableView->selectionModel()->selectedRows();
    if (selected.isEmpty()) {
        QMessageBox::warning(this, "提示", "请先从已选课程列表中选择要退的课程！");
        return;
    }
    
    // 获取课程信息
    QString electiveId = m_selectedModel->data(m_selectedModel->index(selected.first().row(), 0)).toString();
    QString courseName = m_selectedModel->data(m_selectedModel->index(selected.first().row(), 1)).toString();
    
    // 确认退课
    QMessageBox::StandardButton reply = QMessageBox::question(this, "确认退课",
        QString("确定要退掉课程「%1」吗？").arg(courseName),
        QMessageBox::Yes | QMessageBox::No);
    
    if (reply != QMessageBox::Yes) return;
    
    // 删除选课记录
    QSqlDatabase db = getDatabase();
    if (!db.isOpen()) return;
    
    QSqlQuery q(db);
    QString sql = "DELETE FROM student_elective WHERE stu_no = ? AND elective_id = ?";
    q.prepare(sql);
    q.addBindValue(m_username);
    q.addBindValue(electiveId);
    
    if (q.exec()) {
        QMessageBox::information(this, "成功", "退课成功！");
        loadAvailableCourses();  // 刷新可选课程列表
        loadSelectedCourses();   // 刷新已选课程列表
    } else {
        QMessageBox::warning(this, "失败", "退课失败！\n" + q.lastError().text());
    }
}
