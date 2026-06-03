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

    void loadColleges();
};

#endif // ADDSTUDENTDIALOG_H
