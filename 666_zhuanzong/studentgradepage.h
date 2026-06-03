#ifndef STUDENTGRADEPAGE_H
#define STUDENTGRADEPAGE_H

#include <QWidget>

namespace Ui {
class StudentGradePage;
}

class StudentGradePage : public QWidget
{
    Q_OBJECT

public:
    explicit StudentGradePage(QWidget *parent = nullptr);
    ~StudentGradePage();

private slots:
    void on_exportBtn_clicked();

private:
    Ui::StudentGradePage *ui;
};

#endif // STUDENTGRADEPAGE_H
