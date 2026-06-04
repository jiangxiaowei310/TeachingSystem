#ifndef ADDSTUDENTDIALOG_H
#define ADDSTUDENTDIALOG_H

#include <QDialog>

namespace Ui {
class AddStudentDialog;
}

class AddStudentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddStudentDialog(QWidget *parent = nullptr);
    ~AddStudentDialog();

    void setStudentData(int userId, const QString &stuNo, const QString &name, const QString &gender,
                        int collegeId, int majorId, int classId, const QString &grade,
                        const QString &phone, const QString &email);
    int getUserId() const;

    QString getStuNo() const;
    QString getName() const;
    QString getGender() const;
    int getCollegeId() const;
    int getMajorId() const;
    int getClassId() const;
    QString getGrade() const;
    QString getPhone() const;
    QString getEmail() const;

private slots:
    void onCollegeChanged(int index);
    void onMajorChanged(int index);

private:
    Ui::AddStudentDialog *ui;
    int m_userId;

    void loadColleges();
};

#endif // ADDSTUDENTDIALOG_H
