#include "studentpage.h"
#include "ui_studentpage.h"
#include "addstudentdialog.h"
#include "batchimportdialog.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QSqlQueryModel>
#include <QFile>
#include <QTextStream>
#include <QSqlRecord>

StudentPage::StudentPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentPage)
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

    loadStudents();

}

StudentPage::~StudentPage()
{
    delete ui;
}

// 刷新表格
void StudentPage::loadStudents()
{
    model->setFilter("");
    model->select();

    ui->tableView->setModel(model);

    // 查询学生总数
    QSqlQuery query;

    query.exec(
        "SELECT COUNT(*) FROM students"
        );

    if(query.next())
    {
        int total =
            query.value(0).toInt();

        ui->totalLabel->setText(
            QString("共 %1 条")
                .arg(total)
            );
    }

    // 暂时显示第一页
    ui->pageLabel->setText("1 / 1");
}

// 添加学生
void StudentPage::on_addBtn_clicked()
{
    AddStudentDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString stuNo = dialog.getStuNo();
        QString name = dialog.getName();
        QString gender = dialog.getGender();
        int collegeId = dialog.getCollegeId();
        int majorId = dialog.getMajorId();
        int classId = dialog.getClassId();
        QString grade = dialog.getGrade();
        QString phone = dialog.getPhone();
        QString email = dialog.getEmail();

        // 使用学号作为用户名，默认密码123456
        QString username = stuNo;
        QString password = "123456";

        if (stuNo.isEmpty() || name.isEmpty()) {
            QMessageBox::warning(this, "警告", "学号和姓名不能为空！");
            return;
        }

        QSqlDatabase db = QSqlDatabase::database();
        db.transaction();

        // 插入 users
        QSqlQuery query;
        query.prepare(R"(
            INSERT INTO users (username, password, role, create_time)
            VALUES (:username, :password, 'student', NOW())
        )");
        query.bindValue(":username", username);
        query.bindValue(":password", password);

        if (!query.exec()) {
            db.rollback();
            QMessageBox::critical(this, "错误", "创建账号失败：" + query.lastError().text());
            return;
        }

        int userId = query.lastInsertId().toInt();

        // 插入 students
        query.prepare(R"(
            INSERT INTO students (user_id, stu_no, name, gender, college_id, major_id, class_id, grade, phone, email)
            VALUES (:uid, :sno, :name, :gender, :cid, :mid, :clid, :grade, :phone, :email)
        )");
        query.bindValue(":uid", userId);
        query.bindValue(":sno", stuNo);
        query.bindValue(":name", name);
        query.bindValue(":gender", gender);
        query.bindValue(":cid", collegeId);
        query.bindValue(":mid", majorId);
        query.bindValue(":clid", classId);
        query.bindValue(":grade", grade);
        query.bindValue(":phone", phone);
        query.bindValue(":email", email);

        if (!query.exec()) {
            db.rollback();
            QMessageBox::critical(this, "错误", "添加学生失败：" + query.lastError().text());
            return;
        }

        db.commit();
        QMessageBox::information(this, "成功", "学生添加成功！\n用户名：" + username + "\n密码：123456");
        loadStudents();
    }
}

// 编辑
void StudentPage::on_editBtn_clicked()
{
    int row = ui->tableView->currentIndex().row();
    if (row < 0) {
        QMessageBox::warning(this, "提示", "请选择一行");
        return;
    }

    // 获取用户ID和学生信息
    int userId = model->data(model->index(row, 1)).toInt(); // user_id 在第2列(index=1)
    QString stuNo = model->data(model->index(row, 2)).toString();
    QString name = model->data(model->index(row, 3)).toString();
    QString gender = model->data(model->index(row, 4)).toString();
    QString collegeName = model->data(model->index(row, 5)).toString();
    QString majorName = model->data(model->index(row, 6)).toString();
    QString className = model->data(model->index(row, 7)).toString();
    QString grade = model->data(model->index(row, 8)).toString();

    // 获取原始ID值
    int collegeId = -1, majorId = -1, classId = -1;
    QString phone, email;

    QSqlQuery query;
    query.prepare("SELECT college_id, major_id, class_id, phone, email FROM students WHERE user_id = ?");
    query.addBindValue(userId);
    if (query.exec() && query.next()) {
        collegeId = query.value(0).toInt();
        majorId = query.value(1).toInt();
        classId = query.value(2).toInt();
        phone = query.value(3).toString();
        email = query.value(4).toString();
    }

    AddStudentDialog dialog(this);
    dialog.setStudentData(userId, stuNo, name, gender, collegeId, majorId, classId, grade, phone, email);

    if (dialog.exec() == QDialog::Accepted) {
        // 更新学生信息
        QString newName = dialog.getName();
        QString newGender = dialog.getGender();
        int newCollegeId = dialog.getCollegeId();
        int newMajorId = dialog.getMajorId();
        int newClassId = dialog.getClassId();
        QString newGrade = dialog.getGrade();
        QString newPhone = dialog.getPhone();
        QString newEmail = dialog.getEmail();

        QSqlDatabase db = QSqlDatabase::database();
        db.transaction();

        query.prepare(R"(
            UPDATE students SET name = :name, gender = :gender, college_id = :cid,
                               major_id = :mid, class_id = :clid, grade = :grade,
                               phone = :phone, email = :email
            WHERE user_id = :uid
        )");
        query.bindValue(":name", newName);
        query.bindValue(":gender", newGender);
        query.bindValue(":cid", newCollegeId);
        query.bindValue(":mid", newMajorId);
        query.bindValue(":clid", newClassId);
        query.bindValue(":grade", newGrade);
        query.bindValue(":phone", newPhone);
        query.bindValue(":email", newEmail);
        query.bindValue(":uid", userId);

        if (!query.exec()) {
            db.rollback();
            QMessageBox::critical(this, "错误", "更新学生信息失败：" + query.lastError().text());
            return;
        }

        db.commit();
        QMessageBox::information(this, "成功", "学生信息更新成功！");
        loadStudents();
    }
}

// 删除
void StudentPage::on_deleteBtn_clicked()
{
    int row = ui->tableView->currentIndex().row();

    if(row < 0)
    {
        QMessageBox::warning(this,"提示","请选择一名学生");
        return;
    }

    int userId = model->record(row)
                     .value("user_id")
                     .toInt();

    QString name = model->record(row)
                       .value("name")
                       .toString();

    if(QMessageBox::question(
            this,
            "确认删除",
            QString("确定删除学生【%1】吗？").arg(name))
        != QMessageBox::Yes)
    {
        return;
    }

    QSqlDatabase db = QSqlDatabase::database();

    db.transaction();

    QSqlQuery q;

    q.prepare("DELETE FROM students WHERE user_id=?");
    q.addBindValue(userId);

    if(!q.exec())
    {
        db.rollback();

        QMessageBox::critical(
            this,
            "删除失败",
            q.lastError().text());

        return;
    }

    q.prepare("DELETE FROM users WHERE id=?");
    q.addBindValue(userId);

    if(!q.exec())
    {
        db.rollback();

        QMessageBox::critical(
            this,
            "删除失败",
            q.lastError().text());

        return;
    }

    db.commit();

    QMessageBox::information(
        this,
        "成功",
        "学生删除成功");

    loadStudents();
}

// 搜索
void StudentPage::on_searchBtn_clicked()
{
    QString key =
        ui->searchEdit->text();

    if(key.isEmpty())
    {
        loadStudents();
        return;
    }

    model->setFilter(
        QString(
            "name like '%%1%' OR stu_no like '%%1%'"
            ).arg(key)
        );

    model->select();

    ui->totalLabel->setText(
        QString("共 %1 条")
            .arg(model->rowCount())
        );

    ui->pageLabel->setText("1 / 1");
}

// 获取学院ID
int StudentPage::getCollegeId(const QString &collegeName)
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
int StudentPage::getMajorId(const QString &majorName)
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
int StudentPage::getClassId(const QString &className)
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
QList<QMap<QString, QString>> StudentPage::parseCSV(const QString &filePath)
{
    QList<QMap<QString, QString>> dataList;
    QFile file(filePath);
    
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return dataList;
    }

    QTextStream in(&file);
    QString headerLine = in.readLine();
    QStringList headers = headerLine.split(",");
    
    // 清理头部空格
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

// 解析CSV行（处理带引号的字段）
QStringList StudentPage::parseCSVLine(const QString &line)
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

// 批量导入
void StudentPage::on_batchImportBtn_clicked()
{
    BatchImportDialog dialog(this);
    if (dialog.exec() != QDialog::Accepted) {
        return;
    }

    QString filePath = dialog.getFilePath();

    // 统一使用CSV解析（支持Excel保存的CSV格式）
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

        // 如果学院、专业、班级不存在，尝试使用ID直接匹配
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
