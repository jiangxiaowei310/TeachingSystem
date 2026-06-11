#include "studentschedulepage.h"
#include "ui_studentschedulepage.h"

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

StudentSchedulePage::StudentSchedulePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentSchedulePage)
{
    ui->setupUi(this);
    setWindowTitle("我的课表");
    m_termStart = QDate(2026, 3, 2);

    // 初始化周次下拉框
    ui->weekCombo->clear();
    for (int w = 1; w <= 20; ++w) {
        QDate monday = m_termStart.addDays((w - 1) * 7);
        QDate sunday = monday.addDays(6);
        QString text = QString("第%1周 | %2 - %3")
                           .arg(w)
                           .arg(monday.toString("yyyy.MM.dd"))
                           .arg(sunday.toString("yyyy.MM.dd"));
        ui->weekCombo->addItem(text, w);
    }

    // 动态创建课表格子控件
    QStringList prefixes = {"", "mon", "tue", "wed", "thu", "fri"};
    for (int slot = 1; slot <= 4; ++slot) {      // 行（节次）- 从第1行开始（第0行是表头）
        for (int day = 1; day <= 5; ++day) {      // 列（星期）- 从第1列开始（第0列是时间标签）
            QLabel *label = new QLabel(this);
            QString objectName = QString("%1Sec%2").arg(prefixes[day]).arg(slot);
            label->setObjectName(objectName);
            label->setAlignment(Qt::AlignCenter);
            label->setStyleSheet("padding: 10px; background: #f7fafc; border: 1px solid #e2e8f0;");
            label->setWordWrap(true);
            label->setMinimumHeight(80);

            // 课表格子应该放在第1-4行，第1-5列（避免覆盖第0行表头和第0列时间标签）
            ui->gridLayout->addWidget(label, slot, day);
            qDebug() << "创建控件:" << objectName << "在行" << slot << "列" << day;
        }
    }

    // 显式连接信号槽
    connect(ui->weekCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &StudentSchedulePage::on_weekCombo_currentIndexChanged);

    qDebug() << "StudentSchedulePage 初始化完成";
}

StudentSchedulePage::~StudentSchedulePage()
{
    delete ui;
}

void StudentSchedulePage::setUsername(const QString &username)
{
    m_username = username;
    qDebug() << "=== 设置用户名:" << m_username << "===";

    // 自动计算当前周
    int curWeek = getCurrentWeek();
    qDebug() << "计算出的当前周次:" << curWeek;
    qDebug() << "学期开始日期:" << m_termStart;
    qDebug() << "当前系统日期:" << QDate::currentDate();

    // 选中当前周
    for(int i = 0; i < ui->weekCombo->count(); i++){
        if(ui->weekCombo->itemData(i).toInt() == curWeek){
            ui->weekCombo->setCurrentIndex(i);
            qDebug() << "选中第" << curWeek << "周，索引:" << i;
            break;
        }
    }

    // 注意：setCurrentIndex 会触发 currentIndexChanged 信号
    // 所以 loadSchedule 会被自动调用，不需要手动调用
}

int StudentSchedulePage::getCurrentWeek()
{
    QDate today = QDate::currentDate();
    int days = m_termStart.daysTo(today);
    int week = days / 7 + 1;
    int result = qBound(1, week, 20);
    qDebug() << "计算周次: days=" << days << ", week=" << week << ", 最终=" << result;
    return result;
}

void StudentSchedulePage::on_weekCombo_currentIndexChanged(int index)
{
    if (index < 0) {
        qDebug() << "on_weekCombo_currentIndexChanged: 索引无效" << index;
        return;
    }

    int week = ui->weekCombo->itemData(index).toInt();
    qDebug() << "========================================";
    qDebug() << "=== 用户切换到第" << week << "周 (索引:" << index << ") ===";
    qDebug() << "========================================";

    loadSchedule(week);
}

void StudentSchedulePage::loadSchedule(int weekNo)
{
    qDebug() << "=== 开始加载第" << weekNo << "周课表 ===";

    QStringList prefixes = {"", "mon", "tue", "wed", "thu", "fri"};

    // 1. 强制清空所有格子
    for (int day = 1; day <= 5; ++day) {
        for (int slot = 1; slot <= 4; ++slot) {
            QString objectName = QString("%1Sec%2").arg(prefixes[day]).arg(slot);
            QLabel *lbl = findChild<QLabel*>(objectName);
            if (lbl) {
                lbl->clear();
                lbl->setText("");
                lbl->setStyleSheet("padding: 10px; background: #f7fafc; border: 1px solid #e2e8f0;");
            }
        }
    }

    if (m_username.isEmpty()) {
        qDebug() << "错误：用户名为空";
        return;
    }

    // 获取数据库连接
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
        return;
    }

    // 查询学生班级ID
    QString classSql = "SELECT s.class_id FROM users u JOIN students s ON u.id = s.user_id WHERE u.username = ?";
    QSqlQuery classQuery;
    classQuery.prepare(classSql);
    classQuery.addBindValue(m_username);

    int classId = -1;
    if (classQuery.exec() && classQuery.next()) {
        classId = classQuery.value(0).toInt();
        qDebug() << "学生班级ID:" << classId;
    } else {
        QMessageBox::warning(this, "错误", "无法获取学生班级信息！");
        return;
    }

    // 查询课程 - 注意这里使用了 weekNo 作为参数
    QString sql = R"(
        SELECT cs.week_day, cs.start_section, cs.end_section,
               c.course_name, t.name as teacher_name, cs.classroom,
               cs.start_week, cs.end_week
        FROM course_schedule cs
        JOIN courses c ON cs.course_id = c.course_id
        LEFT JOIN teachers t ON cs.teacher_id = t.teacher_id
        WHERE cs.class_id = ? AND ? BETWEEN cs.start_week AND cs.end_week
        ORDER BY cs.week_day, cs.start_section
    )";

    QSqlQuery q;
    q.prepare(sql);
    q.addBindValue(classId);
    q.addBindValue(weekNo);  // 关键：使用传入的周次参数

    qDebug() << "执行查询: class_id=" << classId << ", 查询周次=" << weekNo;

    if (!q.exec()) {
        QMessageBox::warning(this, "错误", "查询课程失败！\n" + q.lastError().text());
        qDebug() << "SQL错误:" << q.lastError().text();
        return;
    }

    int count = 0;
    qDebug() << "=== 查询结果 ===";

    while (q.next()) {
        count++;
        int wd = q.value("week_day").toInt();
        int startSec = q.value("start_section").toInt();
        int endSec = q.value("end_section").toInt();
        QString course = q.value("course_name").toString();
        QString teacher = q.value("teacher_name").toString();
        QString room = q.value("classroom").toString();
        int startWeek = q.value("start_week").toInt();
        int endWeek = q.value("end_week").toInt();

        qDebug() << "课程:" << course
                 << "周次范围:" << startWeek << "-" << endWeek
                 << "当前查询周:" << weekNo
                 << "匹配:" << ((weekNo >= startWeek && weekNo <= endWeek) ? "是" : "否");

        for (int sec = startSec; sec <= endSec; ++sec) {
            if (sec < 1 || sec > 4) continue;

            QString objectName = QString("%1Sec%2").arg(prefixes[wd]).arg(sec);
            QLabel *targetLabel = this->findChild<QLabel*>(objectName);

            if (targetLabel) {
                QString text = QString("<b>%1</b><br>%2<br><font color='gray'>%3</font>")
                .arg(course)
                    .arg(teacher)
                    .arg(room);

                targetLabel->setText(text);
                targetLabel->setStyleSheet("padding: 10px; background-color: #e3f2fd; border: 1px solid #90caf9; border-radius: 4px;");
            }
        }
    }

    qDebug() << "=== 第" << weekNo << "周加载完成，共找到" << count << "条课程 ===";

    if (count == 0) {
        qDebug() << "警告：第" << weekNo << "周没有课程";
        // 可选：显示提示
        // ui->statusLabel->setText(QString("第%1周暂无课程安排").arg(weekNo));
    }
}
