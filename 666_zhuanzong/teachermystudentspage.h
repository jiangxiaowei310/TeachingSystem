#ifndef TEACHERMYSTUDENTSPAGE_H
#define TEACHERMYSTUDENTSPAGE_H

#include <QWidget>

namespace Ui {
class TeacherMyStudentsPage;
}

class TeacherMyStudentsPage : public QWidget
{
    Q_OBJECT

public:
    explicit TeacherMyStudentsPage(QWidget *parent = nullptr);
    ~TeacherMyStudentsPage();

private slots:
    void on_searchBtn_clicked();
    void on_exportBtn_clicked();

private:
    Ui::TeacherMyStudentsPage *ui;
};

#endif // TEACHERMYSTUDENTSPAGE_H
