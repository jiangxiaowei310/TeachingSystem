#ifndef TEACHERGRADEPAGE_H
#define TEACHERGRADEPAGE_H

#include <QWidget>

namespace Ui {
class TeacherGradePage;
}

class TeacherGradePage : public QWidget
{
    Q_OBJECT

public:
    explicit TeacherGradePage(QWidget *parent = nullptr);
    ~TeacherGradePage();

private slots:
    void on_inputBtn_clicked();
    void on_saveBtn_clicked();
    void on_importBtn_clicked();

private:
    Ui::TeacherGradePage *ui;
};

#endif // TEACHERGRADEPAGE_H
