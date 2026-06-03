#ifndef TEACHERINFOPAGE_H
#define TEACHERINFOPAGE_H

#include <QWidget>

namespace Ui {
class TeacherInfoPage;
}

class TeacherInfoPage : public QWidget
{
    Q_OBJECT

public:
    explicit TeacherInfoPage(QWidget *parent = nullptr);
    ~TeacherInfoPage();

private slots:
    void on_editBtn_clicked();
    void on_saveBtn_clicked();

private:
    Ui::TeacherInfoPage *ui;
};

#endif // TEACHERINFOPAGE_H
