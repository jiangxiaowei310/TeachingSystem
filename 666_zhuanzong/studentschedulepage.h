#ifndef STUDENTSCHEDULEPAGE_H
#define STUDENTSCHEDULEPAGE_H

#include <QWidget>

namespace Ui {
class StudentSchedulePage;
}

class StudentSchedulePage : public QWidget
{
    Q_OBJECT

public:
    explicit StudentSchedulePage(QWidget *parent = nullptr);
    ~StudentSchedulePage();

private:
    Ui::StudentSchedulePage *ui;
};

#endif // STUDENTSCHEDULEPAGE_H
