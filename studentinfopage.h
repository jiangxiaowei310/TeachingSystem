#ifndef STUDENTINFOPAGE_H
#define STUDENTINFOPAGE_H

#include <QWidget>

namespace Ui {
class StudentInfoPage;
}

class StudentInfoPage : public QWidget
{
    Q_OBJECT

public:
    explicit StudentInfoPage(QWidget *parent = nullptr);
    ~StudentInfoPage();
    void setUsername(const QString &username);

private:
    QString m_username;
    void loadStudentInfo();
    void setEditMode(bool editable);

private slots:
    void on_editBtn_clicked();
    void on_saveBtn_clicked();

private:
    Ui::StudentInfoPage *ui;
};

#endif // STUDENTINFOPAGE_H
