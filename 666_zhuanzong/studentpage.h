#ifndef STUDENTPAGE_H
#define STUDENTPAGE_H

#include <QSqlRelationalTableModel>
#include <QWidget>
#include <QMap>
#include <QList>

namespace Ui {
class StudentPage;
}

class StudentPage : public QWidget
{
    Q_OBJECT

public:
    explicit StudentPage(QWidget *parent = nullptr);
    ~StudentPage();

private slots:
    void on_addBtn_clicked();
    void on_editBtn_clicked();
    void on_deleteBtn_clicked();
    void on_searchBtn_clicked();
    void on_batchImportBtn_clicked();
    void loadStudents();

private:
    Ui::StudentPage *ui;
    QSqlRelationalTableModel *model;

    // 辅助方法
    int getCollegeId(const QString &collegeName);
    int getMajorId(const QString &majorName);
    int getClassId(const QString &className);
    
    // 文件解析方法
    QList<QMap<QString, QString>> parseCSV(const QString &filePath);
    QStringList parseCSVLine(const QString &line);
};

#endif // STUDENTPAGE_H
