#ifndef STUDENTCOURSEPAGE_H
#define STUDENTCOURSEPAGE_H

#include <QWidget>

namespace Ui {
class StudentCoursePage;
}

class StudentCoursePage : public QWidget
{
    Q_OBJECT

public:
    explicit StudentCoursePage(QWidget *parent = nullptr);
    ~StudentCoursePage();

private slots:
    void on_selectBtn_clicked();
    void on_dropBtn_clicked();

private:
    Ui::StudentCoursePage *ui;
};

#endif // STUDENTCOURSEPAGE_H
