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

    QString getTeacherNo() const;
    QString getName() const;
    QString getGender() const;
    QString getTitle() const;
    int getCollegeId() const;
    QString getPhone() const;
    QString getEmail() const;

private:
    Ui::AddTeacherDialog *ui;

    void loadColleges();
};

#endif // ADDTEACHERDIALOG_H
