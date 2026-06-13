#ifndef TEACHERMYSTUDENTSPAGE_H
#define TEACHERMYSTUDENTSPAGE_H

#include <QWidget>
#include <QMap>
#include <QList>
#include <QSqlQueryModel>

namespace Ui {
class TeacherMyStudentsPage;
}

class TeacherMyStudentsPage : public QWidget
{
    Q_OBJECT

public:
    explicit TeacherMyStudentsPage(QWidget *parent = nullptr);
    ~TeacherMyStudentsPage();

private slots:
    void on_searchBtn_clicked();
    void on_exportBtn_clicked();
    void on_batchImportBtn_clicked();

private:
    Ui::TeacherMyStudentsPage *ui;

    // 表格模型
    QSqlQueryModel *model;

    // 加载学生数据
    void loadStudents();

    // 辅助方法
    int getCollegeId(const QString &collegeName);
    int getMajorId(const QString &majorName);
    int getClassId(const QString &className);

    // CSV文件解析
    QList<QMap<QString, QString>> parseCSV(const QString &filePath);
    QStringList parseCSVLine(const QString &line);
};

#endif // TEACHERMYSTUDENTSPAGE_H
