#ifndef ADDTEACHERDIALOG_H
#define ADDTEACHERDIALOG_H

#include <QDialog>

namespace Ui {
class AddTeacherDialog;
}

class AddTeacherDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddTeacherDialog(QWidget *parent = nullptr);
    ~AddTeacherDialog();

    void setTeacherData(int userId, const QString &teacherNo, const QString &name, const QString &gender,
                        const QString &title, int collegeId, const QString &phone, const QString &email);
    int getUserId() const;

    QString getTeacherNo() const;
    QString getName() const;
    QString getGender() const;
    QString getTitle() const;
    int getCollegeId() const;
    QString getPhone() const;
    QString getEmail() const;

private:
    Ui::AddTeacherDialog *ui;
    int m_userId;

    void loadColleges();
};

#endif // ADDTEACHERDIALOG_H
