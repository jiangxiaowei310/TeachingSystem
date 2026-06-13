#ifndef STUDENTHOMEPAGE_H
#define STUDENTHOMEPAGE_H

#include <QWidget>

namespace Ui {
class StudentHomePage;
}

class StudentHomePage : public QWidget
{
    Q_OBJECT

public:
    explicit StudentHomePage(const QString &studentName, QWidget *parent = nullptr);
    ~StudentHomePage();

private:
    Ui::StudentHomePage *ui;
    QString m_studentName;
};

#endif // STUDENTHOMEPAGE_H
