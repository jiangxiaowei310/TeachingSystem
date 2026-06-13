/********************************************************************************
** Form generated from reading UI file 'teachermainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHERMAINWINDOW_H
#define UI_TEACHERMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TeacherMainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QFrame *sidebarFrame;
    QVBoxLayout *verticalLayout;
    QFrame *logoFrame;
    QHBoxLayout *horizontalLayout_3;
    QLabel *logoLabel;
    QLabel *titleLabel;
    QLabel *welcomeLabel;
    QPushButton *homeBtn;
    QPushButton *myStudentsBtn;
    QPushButton *courseBtn;
    QPushButton *gradeBtn;
    QPushButton *infoBtn;
    QSpacerItem *verticalSpacer;
    QPushButton *logoutBtn;
    QStackedWidget *contentStack;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TeacherMainWindow)
    {
        if (TeacherMainWindow->objectName().isEmpty())
            TeacherMainWindow->setObjectName("TeacherMainWindow");
        TeacherMainWindow->resize(1200, 700);
        centralwidget = new QWidget(TeacherMainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        sidebarFrame = new QFrame(centralwidget);
        sidebarFrame->setObjectName("sidebarFrame");
        sidebarFrame->setMinimumSize(QSize(200, 0));
        sidebarFrame->setMaximumSize(QSize(200, 16777215));
        sidebarFrame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background: #2d3748;\n"
"    border-radius: 0;\n"
"}\n"
"QLabel {\n"
"    color: #a0aec0;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton {\n"
"    background: transparent;\n"
"    color: #a0aec0;\n"
"    border: none;\n"
"    text-align: left;\n"
"    padding: 12px 20px;\n"
"    font-size: 14px;\n"
"    border-radius: 6px;\n"
"    margin: 2px 8px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: #4a5568;\n"
"    color: white;\n"
"}\n"
"QPushButton:checked {\n"
"    background: #48bb78;\n"
"    color: white;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(sidebarFrame);
        verticalLayout->setObjectName("verticalLayout");
        logoFrame = new QFrame(sidebarFrame);
        logoFrame->setObjectName("logoFrame");
        logoFrame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background: #48bb78;\n"
"}\n"
"QLabel {\n"
"    color: white;\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(logoFrame);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        logoLabel = new QLabel(logoFrame);
        logoLabel->setObjectName("logoLabel");
        logoLabel->setStyleSheet(QString::fromUtf8("font-size: 24px;"));

        horizontalLayout_3->addWidget(logoLabel);

        titleLabel = new QLabel(logoFrame);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setStyleSheet(QString::fromUtf8("font-size: 16px; font-weight: bold;"));

        horizontalLayout_3->addWidget(titleLabel);


        verticalLayout->addWidget(logoFrame);

        welcomeLabel = new QLabel(sidebarFrame);
        welcomeLabel->setObjectName("welcomeLabel");
        welcomeLabel->setStyleSheet(QString::fromUtf8("color: white; font-size: 13px; padding: 10px;"));
        welcomeLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(welcomeLabel);

        homeBtn = new QPushButton(sidebarFrame);
        homeBtn->setObjectName("homeBtn");
        homeBtn->setCheckable(true);

        verticalLayout->addWidget(homeBtn);

        myStudentsBtn = new QPushButton(sidebarFrame);
        myStudentsBtn->setObjectName("myStudentsBtn");
        myStudentsBtn->setCheckable(true);

        verticalLayout->addWidget(myStudentsBtn);

        courseBtn = new QPushButton(sidebarFrame);
        courseBtn->setObjectName("courseBtn");
        courseBtn->setCheckable(true);

        verticalLayout->addWidget(courseBtn);

        gradeBtn = new QPushButton(sidebarFrame);
        gradeBtn->setObjectName("gradeBtn");
        gradeBtn->setCheckable(true);

        verticalLayout->addWidget(gradeBtn);

        infoBtn = new QPushButton(sidebarFrame);
        infoBtn->setObjectName("infoBtn");
        infoBtn->setCheckable(true);

        verticalLayout->addWidget(infoBtn);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        logoutBtn = new QPushButton(sidebarFrame);
        logoutBtn->setObjectName("logoutBtn");
        logoutBtn->setStyleSheet(QString::fromUtf8("background: #fc8181; color: white;"));

        verticalLayout->addWidget(logoutBtn);


        horizontalLayout->addWidget(sidebarFrame);

        contentStack = new QStackedWidget(centralwidget);
        contentStack->setObjectName("contentStack");
        contentStack->setStyleSheet(QString::fromUtf8("QStackedWidget {\n"
"    background: #f7fafc;\n"
"}"));

        horizontalLayout->addWidget(contentStack);

        TeacherMainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(TeacherMainWindow);
        statusbar->setObjectName("statusbar");
        statusbar->setStyleSheet(QString::fromUtf8("QStatusBar {\n"
"    background: #e2e8f0;\n"
"    color: #4a5568;\n"
"}"));
        TeacherMainWindow->setStatusBar(statusbar);

        retranslateUi(TeacherMainWindow);

        QMetaObject::connectSlotsByName(TeacherMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TeacherMainWindow)
    {
        TeacherMainWindow->setWindowTitle(QCoreApplication::translate("TeacherMainWindow", "\345\255\246\347\224\237\347\256\241\347\220\206\347\263\273\347\273\237 - \346\225\231\345\270\210\347\253\257", nullptr));
        logoLabel->setText(QCoreApplication::translate("TeacherMainWindow", "\360\237\221\250\342\200\215\360\237\217\253", nullptr));
        titleLabel->setText(QCoreApplication::translate("TeacherMainWindow", "\346\225\231\345\270\210\345\267\245\344\275\234\345\217\260", nullptr));
        welcomeLabel->setText(QCoreApplication::translate("TeacherMainWindow", "\346\254\242\350\277\216\357\274\214\350\200\201\345\270\210", nullptr));
        homeBtn->setText(QCoreApplication::translate("TeacherMainWindow", "\360\237\217\240 \351\246\226\351\241\265", nullptr));
        myStudentsBtn->setText(QCoreApplication::translate("TeacherMainWindow", "\360\237\221\250\342\200\215\360\237\216\223 \346\210\221\347\232\204\345\255\246\347\224\237", nullptr));
        courseBtn->setText(QCoreApplication::translate("TeacherMainWindow", "\360\237\223\232 \350\257\276\347\250\213\347\256\241\347\220\206", nullptr));
        gradeBtn->setText(QCoreApplication::translate("TeacherMainWindow", "\360\237\223\235 \346\210\220\347\273\251\345\275\225\345\205\245", nullptr));
        infoBtn->setText(QCoreApplication::translate("TeacherMainWindow", "\360\237\221\244 \344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        logoutBtn->setText(QCoreApplication::translate("TeacherMainWindow", "\360\237\232\252 \351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TeacherMainWindow: public Ui_TeacherMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHERMAINWINDOW_H
