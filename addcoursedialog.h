#ifndef ADDCOURSEDIALOG_H
#define ADDCOURSEDIALOG_H

#include <QDialog>

namespace Ui {
class AddCourseDialog;
}

class AddCourseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddCourseDialog(QWidget *parent = nullptr);
    ~AddCourseDialog();

    void setCourseData(int courseId, const QString &courseName, const QString &courseCode,
                       const QString &credit, const QString &classHour, const QString &description);

    QString getCourseName() const;
    QString getCourseCode() const;
    QString getCredit() const;
    QString getClassHour() const;
    QString getDescription() const;
    int getCourseId() const;

private:
    Ui::AddCourseDialog *ui;
    int m_courseId;
};

#endif // ADDCOURSEDIALOG_H