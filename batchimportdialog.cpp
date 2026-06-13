#include "batchimportdialog.h"
#include "ui_batchimportdialog.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QList>

BatchImportDialog::BatchImportDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BatchImportDialog)
{
    ui->setupUi(this);
    setWindowTitle("批量导入学生（CSV）");
}

BatchImportDialog::~BatchImportDialog()
{
    delete ui;
}
// 获取文件路径
QString BatchImportDialog::getFilePath() const { return m_filePath; }

// 只选择 CSV 文件
void BatchImportDialog::on_browseBtn_clicked()
{
    QString filter = "CSV文件 (*.csv)";
    QString filePath = QFileDialog::getOpenFileName(this, "选择CSV文件", "", filter);
    if (!filePath.isEmpty()) {
        m_filePath = filePath;
        ui->fileEdit->setText(filePath);// 把路径显示到界面
    }
}

// 只读取 CSV
QList<QStringList> BatchImportDialog::readCsv(const QString &path)
{
    QList<QStringList> list;
    QFile file(path);
    // 打开失败直接返回空列表
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return list;

    QTextStream s(&file);
    s.setEncoding(QStringConverter::Utf8);// UTF-8 编码，支持中文
    bool first = true;
    while (!s.atEnd()) {
        QString line = s.readLine().trimmed();
        if (line.isEmpty()) continue;
        if (first) { first = false; continue; } // 跳过表头
        list.append(line.split(","));// 按逗号分割，存入列表
    }
    file.close();
    return list;
}

// ==================== 导入主逻辑 ====================
void BatchImportDialog::on_okBtn_clicked()
{
    // 1. 校验是否选择文件
    if (m_filePath.isEmpty()) {
        QMessageBox::warning(this, "提示", "请选择文件");
        return;
    }

    // 2. 读取文件数据
    auto data = readCsv(m_filePath);
    if (data.isEmpty()) {
        QMessageBox::warning(this, "错误", "文件无数据");
        return;
    }

    // 3. 获取数据库连接
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::warning(this, "数据库", "未连接");
        return;
    }

    // 4. 开启事务：要么全部成功，要么全部失败
    db.transaction();
    QSqlQuery q(db);
    // 5. 遍历每一行数据导入
    for (int i = 0; i < data.size(); ++i) {
        QStringList r = data[i];
        if (r.size() < 9) continue;
    // 按列取值并去空格
        QString stuNo    = r[0].trimmed();
        QString name     = r[1].trimmed();
        QString gender   = r[2].trimmed();
        QString college  = r[3].trimmed();
        QString major    = r[4].trimmed();
        QString clsName  = r[5].trimmed();
        QString grade    = r[6].trimmed();
        QString phone    = r[7].trimmed();
        QString email    = r[8].trimmed();

        if (stuNo.isEmpty() || name.isEmpty()) continue;

        // 1. 学院
        int cid = 0;
        q.prepare("SELECT college_id FROM colleges WHERE college_name=?");
        q.addBindValue(college); q.exec();
        if (q.next()) cid = q.value(0).toInt();
        else {
            q.prepare("INSERT INTO colleges(college_name) VALUES(?)");
            q.addBindValue(college); q.exec();
            cid = q.lastInsertId().toInt();
        }

        // 2. 专业
        int mid = 0;
        q.prepare("SELECT major_id FROM majors WHERE major_name=? AND college_id=?");
        q.addBindValue(major); q.addBindValue(cid); q.exec();
        if (q.next()) mid = q.value(0).toInt();
        else {
            q.prepare("INSERT INTO majors(major_name,college_id) VALUES(?,?)");
            q.addBindValue(major); q.addBindValue(cid); q.exec();
            mid = q.lastInsertId().toInt();
        }

        // 3. 班级
        int clsid = 0;
        q.prepare("SELECT class_id FROM classes WHERE class_name=? AND grade=? AND major_id=?");
        q.addBindValue(clsName); q.addBindValue(grade); q.addBindValue(mid); q.exec();
        if (q.next()) clsid = q.value(0).toInt();
        else {
            q.prepare("INSERT INTO classes(class_name,grade,major_id,college_id) VALUES(?,?,?,?)");
            q.addBindValue(clsName); q.addBindValue(grade); q.addBindValue(mid); q.addBindValue(cid);
            q.exec();
            clsid = q.lastInsertId().toInt();
        }

        // 4. 学号重复判断
        q.prepare("SELECT 1 FROM students WHERE stu_no=?");
        q.addBindValue(stuNo); q.exec();
        if (q.next()) {
            db.rollback();
            QMessageBox::warning(this, "导入失败",
                                 QString("第 %1 行：学号 %2 已存在！").arg(i + 1).arg(stuNo));
            return;
        }

        // 5. 插入学生
        q.prepare("INSERT INTO students(stu_no,name,gender,college_id,major_id,class_id,grade,phone,email) "
                  "VALUES(?,?,?,?,?,?,?,?,?)");
        q.addBindValue(stuNo);
        q.addBindValue(name);
        q.addBindValue(gender);
        q.addBindValue(cid);
        q.addBindValue(mid);
        q.addBindValue(clsid);
        q.addBindValue(grade);
        q.addBindValue(phone);
        q.addBindValue(email);

        if (!q.exec()) {
            db.rollback();
            QMessageBox::warning(this, "错误", q.lastError().text());
            return;
        }
    }

     // 所有数据导入成功，提交事务
    db.commit();
    QMessageBox::information(this, "成功", "导入完成！");
    accept();
}
//关闭窗口
void BatchImportDialog::on_cancelBtn_clicked()
{
    reject();
}
//通用文件读取
QList<QStringList> BatchImportDialog::readFile(const QString &path)
{
    return QList<QStringList>();
}
