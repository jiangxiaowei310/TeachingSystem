#ifndef ADDMAJORDIALOG_H
#define ADDMAJORDIALOG_H

#include <QDialog>

namespace Ui {
class AddMajorDialog;
}

class AddMajorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddMajorDialog(QWidget *parent = nullptr);
    ~AddMajorDialog();

    void setMajorData(int majorId, const QString &majorName, const QString &majorCode, int collegeId);
    int getMajorId() const;

    QString getMajorName() const;
    QString getMajorCode() const;
    int getCollegeId() const;

private:
    Ui::AddMajorDialog *ui;
    int m_majorId;

    void loadColleges();
};

#endif // ADDMAJORDIALOG_H
