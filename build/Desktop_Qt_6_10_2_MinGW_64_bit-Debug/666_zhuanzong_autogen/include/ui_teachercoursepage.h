/********************************************************************************
** Form generated from reading UI file 'teachercoursepage.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHERCOURSEPAGE_H
#define UI_TEACHERCOURSEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TeacherCoursePage
{
public:

    void setupUi(QWidget *TeacherCoursePage)
    {
        if (TeacherCoursePage->objectName().isEmpty())
            TeacherCoursePage->setObjectName("TeacherCoursePage");
        TeacherCoursePage->resize(1200, 800);

        retranslateUi(TeacherCoursePage);

        QMetaObject::connectSlotsByName(TeacherCoursePage);
    } // setupUi

    void retranslateUi(QWidget *TeacherCoursePage)
    {
        TeacherCoursePage->setWindowTitle(QCoreApplication::translate("TeacherCoursePage", "\350\257\276\347\250\213\347\256\241\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TeacherCoursePage: public Ui_TeacherCoursePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHERCOURSEPAGE_H
