#include "teachermystudentspage.h"
#include "ui_teachermystudentspage.h"
#include "batchimportdialog.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QTextStream>

TeacherMyStudentsPage::TeacherMyStudentsPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeacherMyStudentsPage)
{
    ui->setupUi(this);
}

TeacherMyStudentsPage::~TeacherMyStudentsPage()
{
    delete ui;
}

void TeacherMyStudentsPage::on_searchBtn_clicked()
{
}

void TeacherMyStudentsPage::on_exportBtn_clicked()
{
    QMessageBox::information(this, "提示", "导出功能可后续扩展");
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

    // 统一使用CSV解析
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
}
