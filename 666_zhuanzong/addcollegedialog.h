#ifndef ADDCOLLEGEDIALOG_H
#define ADDCOLLEGEDIALOG_H

#include <QDialog>

namespace Ui {
class AddCollegeDialog;
}

class AddCollegeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddCollegeDialog(QWidget *parent = nullptr);
    ~AddCollegeDialog();

    void setCollegeData(int collegeId, const QString &collegeName, const QString &collegeCode,
                        const QString &dean, const QString &phone);
    int getCollegeId() const;

    QString getCollegeName() const;
    QString getCollegeCode() const;
    QString getDean() const;
    QString getPhone() const;

private:
    Ui::AddCollegeDialog *ui;
    int m_collegeId;
};

#endif // ADDCOLLEGEDIALOG_H
