#ifndef TEACHERMYSTUDENTSPAGE_H
#define TEACHERMYSTUDENTSPAGE_H

#include <QWidget>
#include <QMap>
#include <QList>

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

    // 辅助方法
    int getCollegeId(const QString &collegeName);
    int getMajorId(const QString &majorName);
    int getClassId(const QString &className);
    
    // 文件解析方法
    QList<QMap<QString, QString>> parseCSV(const QString &filePath);
    QStringList parseCSVLine(const QString &line);
};

#endif // TEACHERMYSTUDENTSPAGE_H
