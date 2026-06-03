/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

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

class Ui_MainWindow
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
    QPushButton *homeBtn;
    QPushButton *studentBtn;
    QPushButton *teacherBtn;
    QPushButton *classBtn;
    QPushButton *majorBtn;
    QPushButton *collegeBtn;
    QPushButton *userBtn;
    QSpacerItem *verticalSpacer;
    QStackedWidget *contentStack;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1200, 700);
        centralwidget = new QWidget(MainWindow);
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
"    background: #4299e1;\n"
"    color: white;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(sidebarFrame);
        verticalLayout->setObjectName("verticalLayout");
        logoFrame = new QFrame(sidebarFrame);
        logoFrame->setObjectName("logoFrame");
        logoFrame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background: #4299e1;\n"
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

        homeBtn = new QPushButton(sidebarFrame);
        homeBtn->setObjectName("homeBtn");
        homeBtn->setCheckable(true);

        verticalLayout->addWidget(homeBtn);

        studentBtn = new QPushButton(sidebarFrame);
        studentBtn->setObjectName("studentBtn");
        studentBtn->setCheckable(true);

        verticalLayout->addWidget(studentBtn);

        teacherBtn = new QPushButton(sidebarFrame);
        teacherBtn->setObjectName("teacherBtn");
        teacherBtn->setCheckable(true);

        verticalLayout->addWidget(teacherBtn);

        classBtn = new QPushButton(sidebarFrame);
        classBtn->setObjectName("classBtn");
        classBtn->setCheckable(true);

        verticalLayout->addWidget(classBtn);

        majorBtn = new QPushButton(sidebarFrame);
        majorBtn->setObjectName("majorBtn");
        majorBtn->setCheckable(true);

        verticalLayout->addWidget(majorBtn);

        collegeBtn = new QPushButton(sidebarFrame);
        collegeBtn->setObjectName("collegeBtn");
        collegeBtn->setCheckable(true);

        verticalLayout->addWidget(collegeBtn);

        userBtn = new QPushButton(sidebarFrame);
        userBtn->setObjectName("userBtn");
        userBtn->setCheckable(true);

        verticalLayout->addWidget(userBtn);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addWidget(sidebarFrame);

        contentStack = new QStackedWidget(centralwidget);
        contentStack->setObjectName("contentStack");
        contentStack->setStyleSheet(QString::fromUtf8("QStackedWidget {\n"
"    background: #f7fafc;\n"
"}"));

        horizontalLayout->addWidget(contentStack);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        statusbar->setStyleSheet(QString::fromUtf8("QStatusBar {\n"
"    background: #e2e8f0;\n"
"    color: #4a5568;\n"
"}"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\255\246\347\224\237\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        logoLabel->setText(QCoreApplication::translate("MainWindow", "\360\237\216\223", nullptr));
        titleLabel->setText(QCoreApplication::translate("MainWindow", "\345\255\246\347\224\237\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        homeBtn->setText(QCoreApplication::translate("MainWindow", "\360\237\217\240 \351\246\226\351\241\265", nullptr));
        studentBtn->setText(QCoreApplication::translate("MainWindow", "\360\237\221\250\342\200\215\360\237\216\223 \345\255\246\347\224\237\347\256\241\347\220\206", nullptr));
        teacherBtn->setText(QCoreApplication::translate("MainWindow", "\360\237\221\250\342\200\215\360\237\217\253 \346\225\231\345\270\210\347\256\241\347\220\206", nullptr));
        classBtn->setText(QCoreApplication::translate("MainWindow", "\360\237\217\253 \347\217\255\347\272\247\347\256\241\347\220\206", nullptr));
        majorBtn->setText(QCoreApplication::translate("MainWindow", "\360\237\223\232 \344\270\223\344\270\232\347\256\241\347\220\206", nullptr));
        collegeBtn->setText(QCoreApplication::translate("MainWindow", "\360\237\217\233\357\270\217 \345\255\246\351\231\242\347\256\241\347\220\206", nullptr));
        userBtn->setText(QCoreApplication::translate("MainWindow", "\360\237\221\244 \347\224\250\346\210\267\347\256\241\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
