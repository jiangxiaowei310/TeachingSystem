#ifndef STUDENTDIALOG_H
#define STUDENTDIALOG_H

#include <QDialog>
#include "studentmodel.h"

namespace Ui {
class StudentDialog;
}

class StudentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StudentDialog(QWidget *parent = nullptr, bool isEdit = false);
    ~StudentDialog();

    void setStudentData(const Student &student);
    Student getStudentData() const;

private slots:
    void on_okBtn_clicked();
    void on_cancelBtn_clicked();

private:
    Ui::StudentDialog *ui;
    bool m_isEdit;
};

#endif // STUDENTDIALOG_H