#ifndef ADDCLASSDIALOG_H
#define ADDCLASSDIALOG_H

#include <QDialog>

namespace Ui {
class AddClassDialog;
}

class AddClassDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddClassDialog(QWidget *parent = nullptr);
    ~AddClassDialog();

    void setClassData(int classId, const QString &className, const QString &classCode,
                      const QString &grade, int majorId, int collegeId);
    int getClassId() const;

    QString getClassName() const;
    QString getClassCode() const;
    QString getGrade() const;
    int getMajorId() const;
    int getCollegeId() const;

private slots:
    void onCollegeChanged(int index);

private:
    Ui::AddClassDialog *ui;
    int m_classId;

    void loadColleges();
    void loadMajors(int collegeId);
};

#endif // ADDCLASSDIALOG_H
