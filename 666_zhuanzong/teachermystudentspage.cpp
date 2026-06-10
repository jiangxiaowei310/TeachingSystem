#include "teachermystudentspage.h"
#include "ui_teachermystudentspage.h"
#include "addstudentdialog.h"
#include "batchimportdialog.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QSqlRelation>
#include <QFile>
#include <QTextStream>
#include <QInputDialog>
#include <QDir>

TeacherMyStudentsPage::TeacherMyStudentsPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeacherMyStudentsPage)
{
    ui->setupUi(this);

    // 初始化 TableView 模型
    model = new QSqlRelationalTableModel(this);
    model->setTable("students");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    // 设置关系（显示名称而不是ID）
    model->setRelation(model->fieldIndex("college_id"), QSqlRelation("colleges", "college_id", "college_name"));
    model->setRelation(model->fieldIndex("major_id"), QSqlRelation("majors", "major_id", "major_name"));
    model->setRelation(model->fieldIndex("class_id"), QSqlRelation("classes", "class_id", "class_name"));

    // 加载学生数据
    loadStudents();
}

TeacherMyStudentsPage::~TeacherMyStudentsPage()
{
    delete ui;
}

// 加载学生数据
void TeacherMyStudentsPage::loadStudents()
{
    model->setFilter("");
    model->select();
    ui->tableView->setModel(model);
}

void TeacherMyStudentsPage::on_searchBtn_clicked()
{
    QString key = ui->searchEdit->text().trimmed();
    if (key.isEmpty()) {
        loadStudents();
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT s.*, c.college_name, m.major_name, cl.class_name "
                 "FROM students s "
                 "LEFT JOIN colleges c ON s.college_id = c.college_id "
                 "LEFT JOIN majors m ON s.major_id = m.major_id "
                 "LEFT JOIN classes cl ON s.class_id = cl.class_id "
                 "WHERE s.name LIKE ? OR s.stu_no LIKE ?");
    query.addBindValue("%" + key + "%");
    query.addBindValue("%" + key + "%");

    if (query.exec()) {
        QSqlQueryModel *tempModel = new QSqlQueryModel(this);
        tempModel->setQuery(query);

        tempModel->setHeaderData(0, Qt::Horizontal, "学生ID");
        tempModel->setHeaderData(1, Qt::Horizontal, "用户ID");
        tempModel->setHeaderData(2, Qt::Horizontal, "学号");
        tempModel->setHeaderData(3, Qt::Horizontal, "姓名");
        tempModel->setHeaderData(4, Qt::Horizontal, "性别");
        tempModel->setHeaderData(5, Qt::Horizontal, "学院ID");
        tempModel->setHeaderData(6, Qt::Horizontal, "专业ID");
        tempModel->setHeaderData(7, Qt::Horizontal, "班级ID");
        tempModel->setHeaderData(8, Qt::Horizontal, "年级");
        tempModel->setHeaderData(9, Qt::Horizontal, "地址");
        tempModel->setHeaderData(10, Qt::Horizontal, "电话");
        tempModel->setHeaderData(11, Qt::Horizontal, "邮箱");
        tempModel->setHeaderData(12, Qt::Horizontal, "学院名称");
        tempModel->setHeaderData(13, Qt::Horizontal, "专业名称");
        tempModel->setHeaderData(14, Qt::Horizontal, "班级名称");

        ui->tableView->setModel(tempModel);
    } else {
        QMessageBox::critical(this, "错误", "搜索失败：" + query.lastError().text());
    }
}

void TeacherMyStudentsPage::on_addBtn_clicked()
{
    AddStudentDialog dialog(this);
    if (dialog.exec() != QDialog::Accepted)
        return;

    QString stuNo = dialog.getStuNo();
    QString name = dialog.getName();
    QString gender = dialog.getGender();
    int collegeId = dialog.getCollegeId();
    int majorId = dialog.getMajorId();
    int classId = dialog.getClassId();
    QString grade = dialog.getGrade();
    QString phone = dialog.getPhone();
    QString email = dialog.getEmail();

    if (stuNo.isEmpty() || name.isEmpty()) {
        QMessageBox::warning(this, "警告", "学号和姓名不能为空！");
        return;
    }

    QSqlDatabase db = QSqlDatabase::database();
    db.transaction();

    QSqlQuery query;
    // 创建用户
    query.prepare("INSERT INTO users (username, password, role, create_time) VALUES (?, ?, 'student', NOW())");
    query.addBindValue(stuNo);
    query.addBindValue("123456");

    if (!query.exec()) {
        db.rollback();
        QMessageBox::critical(this, "错误", "创建用户失败：" + query.lastError().text());
        return;
    }

    int userId = query.lastInsertId().toInt();

    // 创建学生
    query.prepare(R"(
        INSERT INTO students (user_id, stu_no, name, gender, college_id, major_id, class_id, grade, phone, email)
        VALUES (:uid, :sno, :name, :gender, :cid, :mid, :clid, :grade, :phone, :email)
    )");
    query.bindValue(":uid", userId);
    query.bindValue(":sno", stuNo);
    query.bindValue(":name", name);
    query.bindValue(":gender", gender);
    query.bindValue(":cid", collegeId == -1 ? QVariant(QVariant::Int) : collegeId);
    query.bindValue(":mid", majorId == -1 ? QVariant(QVariant::Int) : majorId);
    query.bindValue(":clid", classId == -1 ? QVariant(QVariant::Int) : classId);
    query.bindValue(":grade", grade);
    query.bindValue(":phone", phone);
    query.bindValue(":email", email);

    if (!query.exec()) {
        db.rollback();
        QMessageBox::critical(this, "错误", "添加学生失败：" + query.lastError().text());
        return;
    }

    db.commit();
    QMessageBox::information(this, "成功", "学生添加成功！");
    loadStudents();
}

void TeacherMyStudentsPage::on_editBtn_clicked()
{
    QModelIndex index = ui->tableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请先选择要编辑的学生！");
        return;
    }

    int row = index.row();
    int studentId = model->data(model->index(row, 0)).toInt();

    // 获取当前学生信息
    QSqlQuery query;
    query.prepare("SELECT * FROM students WHERE student_id = ?");
    query.addBindValue(studentId);
    if (!query.exec() || !query.next()) {
        QMessageBox::critical(this, "错误", "无法获取学生信息！");
        return;
    }

    // 弹出编辑对话框
    AddStudentDialog dialog(this);
    dialog.setStudentData(query.value("user_id").toInt(),
                          query.value("stu_no").toString(),
                          query.value("name").toString(),
                          query.value("gender").toString(),
                          query.value("college_id").toInt(),
                          query.value("major_id").toInt(),
                          query.value("class_id").toInt(),
                          query.value("grade").toString(),
                          query.value("phone").toString(),
                          query.value("email").toString());

    if (dialog.exec() != QDialog::Accepted)
        return;

    QString name = dialog.getName();
    QString gender = dialog.getGender();
    int collegeId = dialog.getCollegeId();
    int majorId = dialog.getMajorId();
    int classId = dialog.getClassId();
    QString grade = dialog.getGrade();
    QString phone = dialog.getPhone();
    QString email = dialog.getEmail();

    if (name.isEmpty()) {
        QMessageBox::warning(this, "警告", "姓名不能为空！");
        return;
    }

    query.prepare(R"(
        UPDATE students SET name = :name, gender = :gender, college_id = :cid, 
                           major_id = :mid, class_id = :clid, grade = :grade,
                           phone = :phone, email = :email
        WHERE student_id = :sid
    )");
    query.bindValue(":name", name);
    query.bindValue(":gender", gender);
    query.bindValue(":cid", collegeId == -1 ? QVariant(QVariant::Int) : collegeId);
    query.bindValue(":mid", majorId == -1 ? QVariant(QVariant::Int) : majorId);
    query.bindValue(":clid", classId == -1 ? QVariant(QVariant::Int) : classId);
    query.bindValue(":grade", grade);
    query.bindValue(":phone", phone);
    query.bindValue(":email", email);
    query.bindValue(":sid", studentId);

    if (query.exec()) {
        QMessageBox::information(this, "成功", "学生信息修改成功！");
        loadStudents();
    } else {
        QMessageBox::critical(this, "错误", "修改失败：" + query.lastError().text());
    }
}

void TeacherMyStudentsPage::on_deleteBtn_clicked()
{
    QModelIndex index = ui->tableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请先选择要删除的学生！");
        return;
    }

    int row = index.row();
    int studentId = model->data(model->index(row, 0)).toInt();
    QString name = model->data(model->index(row, 3)).toString();

    if (QMessageBox::question(this, "确认删除", QString("确定要删除学生「%1」吗？").arg(name),
                              QMessageBox::Yes | QMessageBox::No) != QMessageBox::Yes) {
        return;
    }

    QSqlDatabase db = QSqlDatabase::database();
    db.transaction();

    QSqlQuery query;
    // 获取用户ID
    query.prepare("SELECT user_id FROM students WHERE student_id = ?");
    query.addBindValue(studentId);
    if (!query.exec() || !query.next()) {
        QMessageBox::critical(this, "错误", "无法获取学生信息！");
        return;
    }
    int userId = query.value(0).toInt();

    // 删除学生
    query.prepare("DELETE FROM students WHERE student_id = ?");
    query.addBindValue(studentId);
    if (!query.exec()) {
        db.rollback();
        QMessageBox::critical(this, "错误", "删除学生失败：" + query.lastError().text());
        return;
    }

    // 删除用户
    query.prepare("DELETE FROM users WHERE id = ?");
    query.addBindValue(userId);
    if (!query.exec()) {
        db.rollback();
        QMessageBox::critical(this, "错误", "删除用户失败：" + query.lastError().text());
        return;
    }

    db.commit();
    QMessageBox::information(this, "成功", "学生删除成功！");
    loadStudents();
}

void TeacherMyStudentsPage::on_exportBtn_clicked()
{
    QString fileName = QInputDialog::getText(this, "导出名单", "请输入文件名：", QLineEdit::Normal, "学生名单");
    if (fileName.isEmpty()) return;

    QString filePath = fileName + ".csv";
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "错误", "无法创建文件！");
        return;
    }

    QTextStream out(&file);
    out << "学号,姓名,性别,学院,专业,班级,年级,电话,邮箱\n";

    QSqlQuery query("SELECT s.stu_no, s.name, s.gender, c.college_name, m.major_name, cl.class_name, s.grade, s.phone, s.email "
                   "FROM students s "
                   "LEFT JOIN colleges c ON s.college_id = c.college_id "
                   "LEFT JOIN majors m ON s.major_id = m.major_id "
                   "LEFT JOIN classes cl ON s.class_id = cl.class_id");

    while (query.next()) {
        QStringList row;
        row << query.value(0).toString()
            << query.value(1).toString()
            << query.value(2).toString()
            << query.value(3).toString()
            << query.value(4).toString()
            << query.value(5).toString()
            << query.value(6).toString()
            << query.value(7).toString()
            << query.value(8).toString();
        out << row.join(",") << "\n";
    }

    file.close();
    QMessageBox::information(this, "成功", QString("名单已导出到：%1").arg(QDir::currentPath() + "/" + filePath));
}

// 获取学院ID
int TeacherMyStudentsPage::getCollegeId(const QString &collegeName)
{
    QSqlQuery query;
    query.prepare("SELECT college_id FROM colleges WHERE college_name = ?");
    query.addBindValue(collegeName);
    if (query.exec() && query.next()) {
        return query.value(0).toInt();
    }
    return -1;
}

// 获取专业ID
int TeacherMyStudentsPage::getMajorId(const QString &majorName)
{
    QSqlQuery query;
    query.prepare("SELECT major_id FROM majors WHERE major_name = ?");
    query.addBindValue(majorName);
    if (query.exec() && query.next()) {
        return query.value(0).toInt();
    }
    return -1;
}

// 获取班级ID
int TeacherMyStudentsPage::getClassId(const QString &className)
{
    QSqlQuery query;
    query.prepare("SELECT class_id FROM classes WHERE class_name = ?");
    query.addBindValue(className);
    if (query.exec() && query.next()) {
        return query.value(0).toInt();
    }
    return -1;
}

// 解析CSV文件
QList<QMap<QString, QString>> TeacherMyStudentsPage::parseCSV(const QString &filePath)
{
    QList<QMap<QString, QString>> dataList;
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return dataList;
    }

    QTextStream in(&file);
    QString headerLine = in.readLine();
    QStringList headers = headerLine.split(",");

    for (int i = 0; i < headers.size(); i++) {
        headers[i] = headers[i].trimmed();
    }

    while (!in.atEnd()) {
        QString line = in.readLine();
        if (line.trimmed().isEmpty()) continue;

        QStringList values = parseCSVLine(line);
        QMap<QString, QString> rowData;

        for (int i = 0; i < headers.size() && i < values.size(); i++) {
            rowData[headers[i]] = values[i].trimmed();
        }
        dataList.append(rowData);
    }

    file.close();
    return dataList;
}

// 解析CSV行
QStringList TeacherMyStudentsPage::parseCSVLine(const QString &line)
{
    QStringList fields;
    QString currentField;
    bool inQuotes = false;

    for (int i = 0; i < line.size(); i++) {
        QChar c = line[i];

        if (c == '"') {
            if (inQuotes && i + 1 < line.size() && line[i + 1] == '"') {
                currentField += '"';
                i++;
            } else {
                inQuotes = !inQuotes;
            }
        } else if (c == ',' && !inQuotes) {
            fields.append(currentField);
            currentField.clear();
        } else {
            currentField += c;
        }
    }
    fields.append(currentField);

    return fields;
}

void TeacherMyStudentsPage::on_batchImportBtn_clicked()
{
    BatchImportDialog dialog(this);
    if (dialog.exec() != QDialog::Accepted) {
        return;
    }

    QString filePath = dialog.getFilePath();

    QList<QMap<QString, QString>> studentData = parseCSV(filePath);

    if (studentData.isEmpty()) {
        QMessageBox::warning(this, "警告", "未能解析文件或文件为空\n\n提示：请确保文件为CSV格式，或使用Excel另存为CSV格式");
        return;
    }

    int successCount = 0;
    int failCount = 0;
    QStringList failMessages;

    QSqlDatabase db = QSqlDatabase::database();

    for (const auto &row : studentData) {
        QString stuNo = row.value("学号", row.value("student_no", row.value("stu_no")));
        QString name = row.value("姓名", row.value("name"));
        QString gender = row.value("性别", row.value("gender"));
        QString collegeName = row.value("学院", row.value("college", row.value("college_name")));
        QString majorName = row.value("专业", row.value("major", row.value("major_name")));
        QString className = row.value("班级", row.value("class", row.value("class_name")));
        QString grade = row.value("年级", row.value("grade"));
        QString phone = row.value("电话", row.value("phone", row.value("tel")));
        QString email = row.value("邮箱", row.value("email"));

        if (stuNo.isEmpty() || name.isEmpty()) {
            failCount++;
            failMessages.append("跳过空行或不完整数据");
            continue;
        }

        int collegeId = getCollegeId(collegeName);
        int majorId = getMajorId(majorName);
        int classId = getClassId(className);

        if (collegeId == -1 && !collegeName.isEmpty()) {
            bool ok;
            int id = collegeName.toInt(&ok);
            if (ok) collegeId = id;
        }
        if (majorId == -1 && !majorName.isEmpty()) {
            bool ok;
            int id = majorName.toInt(&ok);
            if (ok) majorId = id;
        }
        if (classId == -1 && !className.isEmpty()) {
            bool ok;
            int id = className.toInt(&ok);
            if (ok) classId = id;
        }

        db.transaction();

        QSqlQuery query;
        query.prepare(R"(
            INSERT INTO users (username, password, role, create_time)
            VALUES (:username, :password, 'student', NOW())
        )");
        query.bindValue(":username", stuNo);
        query.bindValue(":password", "123456");

        if (!query.exec()) {
            db.rollback();
            failCount++;
            failMessages.append(QString("学号 %1: 创建账号失败 - %2").arg(stuNo, query.lastError().text()));
            continue;
        }

        int userId = query.lastInsertId().toInt();

        query.prepare(R"(
            INSERT INTO students (user_id, stu_no, name, gender, college_id, major_id, class_id, grade, phone, email)
            VALUES (:uid, :sno, :name, :gender, :cid, :mid, :clid, :grade, :phone, :email)
        )");
        query.bindValue(":uid", userId);
        query.bindValue(":sno", stuNo);
        query.bindValue(":name", name);
        query.bindValue(":gender", gender);
        query.bindValue(":cid", collegeId == -1 ? QVariant(QVariant::Int) : collegeId);
        query.bindValue(":mid", majorId == -1 ? QVariant(QVariant::Int) : majorId);
        query.bindValue(":clid", classId == -1 ? QVariant(QVariant::Int) : classId);
        query.bindValue(":grade", grade);
        query.bindValue(":phone", phone);
        query.bindValue(":email", email);

        if (!query.exec()) {
            db.rollback();
            failCount++;
            failMessages.append(QString("学号 %1: 添加学生失败 - %2").arg(stuNo, query.lastError().text()));
            continue;
        }

        db.commit();
        successCount++;
    }

    QString message = QString("批量导入完成！\n成功：%1 条\n失败：%2 条").arg(successCount).arg(failCount);
    if (!failMessages.isEmpty()) {
        message += "\n\n失败详情：\n" + failMessages.join("\n");
    }

    QMessageBox::information(this, "导入结果", message);
    loadStudents();
}
