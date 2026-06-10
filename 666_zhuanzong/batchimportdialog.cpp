#include "batchimportdialog.h"
#include "ui_batchimportdialog.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

BatchImportDialog::BatchImportDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BatchImportDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("批量导入学生");
}

BatchImportDialog::~BatchImportDialog()
{
    delete ui;
}

QString BatchImportDialog::getFilePath() const
{
    return m_filePath;
}

void BatchImportDialog::on_browseBtn_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "选择CSV文件", "", "CSV文件 (*.csv)");
    if (!filePath.isEmpty()) {
        m_filePath = filePath;
        ui->fileEdit->setText(filePath);
    }
}

void BatchImportDialog::on_okBtn_clicked()
{
    if (m_filePath.isEmpty()) {
        QMessageBox::warning(this, "警告", "请先选择CSV文件！");
        return;
    }

    QList<QStringList> data = readCsv(m_filePath);
    if (data.isEmpty()) {
        QMessageBox::warning(this, "警告", "CSV文件内容为空！");
        return;
    }

    // 开始导入
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::critical(this, "错误", "数据库连接失败！");
        return;
    }

    // 开启事务
    db.transaction();

    int successCount = 0;
    int failCount = 0;

    // 跳过表头，从第二行开始
    for (int i = 1; i < data.size(); ++i) {
        QStringList row = data[i];
        if (row.size() < 9) continue; // 至少需要9个字段

        QString stuNo = row[0].trimmed();
        QString name = row[1].trimmed();
        QString gender = row[2].trimmed();
        QString collegeName = row[3].trimmed();
        QString majorName = row[4].trimmed();
        QString className = row[5].trimmed();
        QString grade = row[6].trimmed();
        QString phone = row[7].trimmed();
        QString email = row[8].trimmed();

        if (stuNo.isEmpty() || name.isEmpty()) continue;

        // 获取或创建学院ID
        int collegeId = -1;
        QSqlQuery query;
        query.prepare("SELECT college_id FROM colleges WHERE college_name = ?");
        query.addBindValue(collegeName);
        if (query.exec() && query.next()) {
            collegeId = query.value(0).toInt();
        } else {
            // 创建学院
            query.prepare("INSERT INTO colleges (college_name) VALUES (?)");
            query.addBindValue(collegeName);
            if (query.exec()) {
                collegeId = query.lastInsertId().toInt();
            } else {
                failCount++;
                continue;
            }
        }

        // 获取或创建专业ID
        int majorId = -1;
        query.prepare("SELECT major_id FROM majors WHERE major_name = ? AND college_id = ?");
        query.addBindValue(majorName);
        query.addBindValue(collegeId);
        if (query.exec() && query.next()) {
            majorId = query.value(0).toInt();
        } else {
            // 创建专业
            query.prepare("INSERT INTO majors (major_name, college_id) VALUES (?, ?)");
            query.addBindValue(majorName);
            query.addBindValue(collegeId);
            if (query.exec()) {
                majorId = query.lastInsertId().toInt();
            } else {
                failCount++;
                continue;
            }
        }

        // 获取或创建班级ID
        int classId = -1;
        query.prepare("SELECT class_id FROM classes WHERE class_name = ? AND major_id = ?");
        query.addBindValue(className);
        query.addBindValue(majorId);
        if (query.exec() && query.next()) {
            classId = query.value(0).toInt();
        } else {
            // 创建班级
            query.prepare("INSERT INTO classes (class_name, grade, college_id, major_id) VALUES (?, ?, ?, ?)");
            query.addBindValue(className);
            query.addBindValue(grade);
            query.addBindValue(collegeId);
            query.addBindValue(majorId);
            if (query.exec()) {
                classId = query.lastInsertId().toInt();
            } else {
                failCount++;
                continue;
            }
        }

        // 创建用户
        QString username = stuNo;
        QString password = "123456";
        query.prepare("INSERT INTO users (username, password, role) VALUES (?, ?, 'student')");
        query.addBindValue(username);
        query.addBindValue(password);
        if (!query.exec()) {
            failCount++;
            continue;
        }
        int userId = query.lastInsertId().toInt();

        // 创建学生
        query.prepare("INSERT INTO students (user_id, stu_no, name, gender, college_id, major_id, class_id, grade, phone, email) "
                     "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
        query.addBindValue(userId);
        query.addBindValue(stuNo);
        query.addBindValue(name);
        query.addBindValue(gender);
        query.addBindValue(collegeId);
        query.addBindValue(majorId);
        query.addBindValue(classId);
        query.addBindValue(grade);
        query.addBindValue(phone);
        query.addBindValue(email);

        if (query.exec()) {
            successCount++;
        } else {
            failCount++;
        }
    }

    if (failCount == 0) {
        db.commit();
        QMessageBox::information(this, "成功", QString("导入成功！共导入 %1 条记录").arg(successCount));
        accept();
    } else {
        db.rollback();
        QMessageBox::warning(this, "部分失败", QString("导入完成！成功 %1 条，失败 %2 条").arg(successCount).arg(failCount));
        accept();
    }
}

void BatchImportDialog::on_cancelBtn_clicked()
{
    reject();
}

QList<QStringList> BatchImportDialog::readFile(const QString &path)
{
    Q_UNUSED(path);
    return QList<QStringList>();
}

QList<QStringList> BatchImportDialog::readCsv(const QString &path)
{
    QList<QStringList> result;
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "错误", "无法打开文件！");
        return result;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = parseCsvLine(line);
        result.append(fields);
    }

    file.close();
    return result;
}

QStringList BatchImportDialog::parseCsvLine(const QString &line)
{
    QStringList fields;
    QString currentField;
    bool inQuotes = false;

    for (int i = 0; i < line.size(); ++i) {
        QChar c = line[i];

        if (c == '"') {
            if (inQuotes && i + 1 < line.size() && line[i + 1] == '"') {
                // 处理双引号转义
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
