#ifndef TEACHERCOURSEPAGE_H
#define TEACHERCOURSEPAGE_H

#include <QWidget>

namespace Ui {
class TeacherCoursePage;
}

class TeacherCoursePage : public QWidget
{
    Q_OBJECT

public:
    explicit TeacherCoursePage(QWidget *parent = nullptr);
    ~TeacherCoursePage();

private slots:
    void on_addBtn_clicked();
    void on_editBtn_clicked();

private:
    Ui::TeacherCoursePage *ui;
};

#endif // TEACHERCOURSEPAGE_H
