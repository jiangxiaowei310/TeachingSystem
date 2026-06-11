#include "studentinfopage.h"
#include "ui_studentinfopage.h"

#include <QMessageBox>
#include <QSqlQuery>
#include <qsqlerror.h>

StudentInfoPage::StudentInfoPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentInfoPage)
{
    ui->setupUi(this);

    // 手动连接信号槽，确保按钮点击事件能正确触发
    connect(ui->editBtn, &QPushButton::clicked, this, &StudentInfoPage::on_editBtn_clicked);
    connect(ui->saveBtn, &QPushButton::clicked, this, &StudentInfoPage::on_saveBtn_clicked);

    // 初始状态：所有输入框设为只读
    setEditMode(false);
}

StudentInfoPage::~StudentInfoPage()
{
    delete ui;
}
// 外部调用：传入用户名，加载信息
void StudentInfoPage::setUsername(const QString &username)
{
    m_username = username;
    loadStudentInfo();
}
// 从数据库加载学生信息
void StudentInfoPage::loadStudentInfo()
{
    if (m_username.isEmpty()) {
        qDebug() << "登录账号为空，无法加载信息";
        return;
    }

    // 【关键】简化SQL，直接关联，去掉可能出错的JOIN
    QSqlQuery q;
    QString sql = R"(
        SELECT s.stu_no, s.name, s.gender, s.phone, s.email, s.grade
        FROM students s
        JOIN users u ON s.user_id = u.id
        WHERE u.username = ?
    )";

    q.prepare(sql);
    q.addBindValue(m_username);

    if (!q.exec()) {
        qDebug() << "SQL执行失败：" << q.lastError().text();
        return;
    }

    if (q.next()) {
        qDebug() << "成功读取到学生信息：" << q.value("stu_no").toString();

        // 给控件赋值，先确保控件名和UI里的一致
        ui->idEdit->setText(q.value("stu_no").toString());
        ui->nameEdit->setText(q.value("name").toString());
        ui->genderEdit->setText(q.value("gender").toString());
        ui->phoneEdit->setText(q.value("phone").toString());
        ui->emailEdit->setText(q.value("email").toString());

        // 如果你还想显示班级/专业/学院，后续再加，先保证基础信息出来
    } else {
        qDebug() << "查询成功，但未找到匹配的学生记录！";
    }
}
// 切换编辑/只读模式
void StudentInfoPage::setEditMode(bool editable)
{
    qDebug() << "切换编辑模式：" << editable;

    ui->idEdit->setReadOnly(true); // 学号一般不允许修改
    ui->nameEdit->setReadOnly(!editable);
    ui->genderEdit->setReadOnly(!editable);
    ui->phoneEdit->setReadOnly(!editable);
    ui->emailEdit->setReadOnly(!editable);

    ui->editBtn->setEnabled(!editable);
    ui->saveBtn->setEnabled(editable);

    qDebug() << "编辑按钮状态：" << ui->editBtn->isEnabled();
    qDebug() << "保存按钮状态：" << ui->saveBtn->isEnabled();
}
// 编辑按钮：开启编辑模式
void StudentInfoPage::on_editBtn_clicked()
{
    qDebug() << "编辑按钮被点击！";
    setEditMode(true);
}
// 保存按钮：保存修改到数据库
void StudentInfoPage::on_saveBtn_clicked()
{
    QString phone = ui->phoneEdit->text().trimmed();
    QString email = ui->emailEdit->text().trimmed();
    if (phone.isEmpty() || email.isEmpty()) {
        QMessageBox::warning(this, "提示", "电话和邮箱不能为空");
        return;
    }

    QSqlQuery q;
    QString sql = R"(
        UPDATE students
        SET name = ?, gender = ?, phone = ?, email = ?
        WHERE user_id = (SELECT id FROM users WHERE username = ?)
    )";
    q.prepare(sql);
    q.addBindValue(ui->nameEdit->text());
    q.addBindValue(ui->genderEdit->text());
    q.addBindValue(phone);
    q.addBindValue(email);
    q.addBindValue(m_username);

    if (q.exec()) {
        QMessageBox::information(this, "成功", "信息已保存");
        setEditMode(false);
    } else {
        QMessageBox::warning(this, "保存失败", q.lastError().text());
    }
}
