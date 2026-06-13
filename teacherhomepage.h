#ifndef TEACHERHOMEPAGE_H
#define TEACHERHOMEPAGE_H

#include <QWidget>

namespace Ui {
class TeacherHomePage;
}

class TeacherHomePage : public QWidget
{
    Q_OBJECT

public:
    explicit TeacherHomePage(const QString &teacherName, QWidget *parent = nullptr);
    ~TeacherHomePage();

private:
    Ui::TeacherHomePage *ui;
    QString m_teacherName;
};

#endif // TEACHERHOMEPAGE_H
