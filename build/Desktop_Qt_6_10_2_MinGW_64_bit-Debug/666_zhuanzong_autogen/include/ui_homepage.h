/********************************************************************************
** Form generated from reading UI file 'homepage.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEPAGE_H
#define UI_HOMEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomePage
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *headerFrame;
    QHBoxLayout *horizontalLayout;
    QLabel *welcomeLabel;
    QSpacerItem *horizontalSpacer;
    QLabel *userLabel;
    QHBoxLayout *horizontalLayout_2;
    QFrame *studentCountFrame;
    QVBoxLayout *verticalLayout_2;
    QLabel *studentIcon;
    QLabel *studentCount;
    QLabel *studentLabel;
    QFrame *teacherCountFrame;
    QVBoxLayout *verticalLayout_3;
    QLabel *teacherIcon;
    QLabel *teacherCount;
    QLabel *teacherLabel;
    QFrame *classCountFrame;
    QVBoxLayout *verticalLayout_4;
    QLabel *classIcon;
    QLabel *classCount;
    QLabel *classLabel;
    QFrame *collegeCountFrame;
    QVBoxLayout *verticalLayout_5;
    QLabel *collegeIcon;
    QLabel *collegeCount;
    QLabel *collegeLabel;
    QHBoxLayout *horizontalLayout_3;
    QFrame *chartFrame1;
    QVBoxLayout *verticalLayout_6;
    QLabel *chart1Title;
    QLabel *pieChart;
    QFrame *chartFrame2;
    QVBoxLayout *verticalLayout_7;
    QLabel *chart2Title;
    QLabel *barChart;
    QHBoxLayout *horizontalLayout_4;
    QFrame *recentFrame;
    QVBoxLayout *verticalLayout_8;
    QLabel *recentTitle;
    QLabel *recentList;
    QFrame *quickFrame;
    QVBoxLayout *verticalLayout_9;
    QLabel *quickTitle;
    QGridLayout *gridLayout;
    QPushButton *AddStudentsquickBtn;
    QPushButton *AddTeachersquickBtn;
    QPushButton *quickBtn3;
    QPushButton *quickBtn4;

    void setupUi(QWidget *HomePage)
    {
        if (HomePage->objectName().isEmpty())
            HomePage->setObjectName("HomePage");
        HomePage->resize(1000, 650);
        HomePage->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background: #f7fafc;\n"
"}\n"
"QFrame {\n"
"    background: white;\n"
"    border-radius: 8px;\n"
"    border: 1px solid #e2e8f0;\n"
"}\n"
"QLabel {\n"
"    color: #4a5568;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(HomePage);
        verticalLayout->setObjectName("verticalLayout");
        headerFrame = new QFrame(HomePage);
        headerFrame->setObjectName("headerFrame");
        horizontalLayout = new QHBoxLayout(headerFrame);
        horizontalLayout->setObjectName("horizontalLayout");
        welcomeLabel = new QLabel(headerFrame);
        welcomeLabel->setObjectName("welcomeLabel");
        welcomeLabel->setStyleSheet(QString::fromUtf8("font-size: 24px; font-weight: bold; color: #1a202c;"));

        horizontalLayout->addWidget(welcomeLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        userLabel = new QLabel(headerFrame);
        userLabel->setObjectName("userLabel");
        userLabel->setStyleSheet(QString::fromUtf8("font-size: 14px; color: #718096;"));

        horizontalLayout->addWidget(userLabel);


        verticalLayout->addWidget(headerFrame);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        studentCountFrame = new QFrame(HomePage);
        studentCountFrame->setObjectName("studentCountFrame");
        studentCountFrame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"        background-color: qlineargradient(\n"
"            x1:0, y1:0,\n"
"            x2:1, y2:1,\n"
"            stop:0 #667eea,\n"
"            stop:1 #764ba2\n"
"        );\n"
"        border: none;\n"
"    }\n"
"    QLabel {\n"
"        color: white;\n"
"    }"));
        verticalLayout_2 = new QVBoxLayout(studentCountFrame);
        verticalLayout_2->setObjectName("verticalLayout_2");
        studentIcon = new QLabel(studentCountFrame);
        studentIcon->setObjectName("studentIcon");
        studentIcon->setStyleSheet(QString::fromUtf8("font-size: 32px;"));

        verticalLayout_2->addWidget(studentIcon);

        studentCount = new QLabel(studentCountFrame);
        studentCount->setObjectName("studentCount");
        studentCount->setStyleSheet(QString::fromUtf8("font-size: 28px; font-weight: bold;"));

        verticalLayout_2->addWidget(studentCount);

        studentLabel = new QLabel(studentCountFrame);
        studentLabel->setObjectName("studentLabel");
        studentLabel->setStyleSheet(QString::fromUtf8("font-size: 14px; opacity: 0.9;"));

        verticalLayout_2->addWidget(studentLabel);


        horizontalLayout_2->addWidget(studentCountFrame);

        teacherCountFrame = new QFrame(HomePage);
        teacherCountFrame->setObjectName("teacherCountFrame");
        teacherCountFrame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"        background-color: qlineargradient(\n"
"            x1:0, y1:0,\n"
"            x2:1, y2:1,\n"
"            stop:0 #f093fb,\n"
"            stop:1 #f5576c\n"
"        );\n"
"    border: none;\n"
"}\n"
"QLabel {\n"
"    color: white;\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(teacherCountFrame);
        verticalLayout_3->setObjectName("verticalLayout_3");
        teacherIcon = new QLabel(teacherCountFrame);
        teacherIcon->setObjectName("teacherIcon");
        teacherIcon->setStyleSheet(QString::fromUtf8("font-size: 32px;"));

        verticalLayout_3->addWidget(teacherIcon);

        teacherCount = new QLabel(teacherCountFrame);
        teacherCount->setObjectName("teacherCount");
        teacherCount->setStyleSheet(QString::fromUtf8("font-size: 28px; font-weight: bold;"));

        verticalLayout_3->addWidget(teacherCount);

        teacherLabel = new QLabel(teacherCountFrame);
        teacherLabel->setObjectName("teacherLabel");
        teacherLabel->setStyleSheet(QString::fromUtf8("font-size: 14px; opacity: 0.9;"));

        verticalLayout_3->addWidget(teacherLabel);


        horizontalLayout_2->addWidget(teacherCountFrame);

        classCountFrame = new QFrame(HomePage);
        classCountFrame->setObjectName("classCountFrame");
        classCountFrame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"        background-color: qlineargradient(\n"
"            x1:0, y1:0,\n"
"            x2:1, y2:1,\n"
"            stop:0 #4facfe,\n"
"            stop:1 #00f2fe\n"
"        );\n"
"    border: none;\n"
"}\n"
"QLabel {\n"
"    color: white;\n"
"}"));
        verticalLayout_4 = new QVBoxLayout(classCountFrame);
        verticalLayout_4->setObjectName("verticalLayout_4");
        classIcon = new QLabel(classCountFrame);
        classIcon->setObjectName("classIcon");
        classIcon->setStyleSheet(QString::fromUtf8("font-size: 32px;"));

        verticalLayout_4->addWidget(classIcon);

        classCount = new QLabel(classCountFrame);
        classCount->setObjectName("classCount");
        classCount->setStyleSheet(QString::fromUtf8("font-size: 28px; font-weight: bold;"));

        verticalLayout_4->addWidget(classCount);

        classLabel = new QLabel(classCountFrame);
        classLabel->setObjectName("classLabel");
        classLabel->setStyleSheet(QString::fromUtf8("font-size: 14px; opacity: 0.9;"));

        verticalLayout_4->addWidget(classLabel);


        horizontalLayout_2->addWidget(classCountFrame);

        collegeCountFrame = new QFrame(HomePage);
        collegeCountFrame->setObjectName("collegeCountFrame");
        collegeCountFrame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"        background-color: qlineargradient(\n"
"            x1:0, y1:0,\n"
"            x2:1, y2:1,\n"
"            stop:0 #43e97b,\n"
"            stop:1 #38f9d7\n"
"        );\n"
"    border: none;\n"
"}\n"
"QLabel {\n"
"    color: white;\n"
"}"));
        verticalLayout_5 = new QVBoxLayout(collegeCountFrame);
        verticalLayout_5->setObjectName("verticalLayout_5");
        collegeIcon = new QLabel(collegeCountFrame);
        collegeIcon->setObjectName("collegeIcon");
        collegeIcon->setStyleSheet(QString::fromUtf8("font-size: 32px;"));

        verticalLayout_5->addWidget(collegeIcon);

        collegeCount = new QLabel(collegeCountFrame);
        collegeCount->setObjectName("collegeCount");
        collegeCount->setStyleSheet(QString::fromUtf8("font-size: 28px; font-weight: bold;"));

        verticalLayout_5->addWidget(collegeCount);

        collegeLabel = new QLabel(collegeCountFrame);
        collegeLabel->setObjectName("collegeLabel");
        collegeLabel->setStyleSheet(QString::fromUtf8("font-size: 14px; opacity: 0.9;"));

        verticalLayout_5->addWidget(collegeLabel);


        horizontalLayout_2->addWidget(collegeCountFrame);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        chartFrame1 = new QFrame(HomePage);
        chartFrame1->setObjectName("chartFrame1");
        verticalLayout_6 = new QVBoxLayout(chartFrame1);
        verticalLayout_6->setObjectName("verticalLayout_6");
        chart1Title = new QLabel(chartFrame1);
        chart1Title->setObjectName("chart1Title");
        chart1Title->setStyleSheet(QString::fromUtf8("font-size: 16px; font-weight: bold; color: #2d3748;"));

        verticalLayout_6->addWidget(chart1Title);

        pieChart = new QLabel(chartFrame1);
        pieChart->setObjectName("pieChart");
        pieChart->setStyleSheet(QString::fromUtf8("font-family: monospace; font-size: 14px; color: #4a5568;"));

        verticalLayout_6->addWidget(pieChart);


        horizontalLayout_3->addWidget(chartFrame1);

        chartFrame2 = new QFrame(HomePage);
        chartFrame2->setObjectName("chartFrame2");
        verticalLayout_7 = new QVBoxLayout(chartFrame2);
        verticalLayout_7->setObjectName("verticalLayout_7");
        chart2Title = new QLabel(chartFrame2);
        chart2Title->setObjectName("chart2Title");
        chart2Title->setStyleSheet(QString::fromUtf8("font-size: 16px; font-weight: bold; color: #2d3748;"));

        verticalLayout_7->addWidget(chart2Title);

        barChart = new QLabel(chartFrame2);
        barChart->setObjectName("barChart");
        barChart->setStyleSheet(QString::fromUtf8("font-family: monospace; font-size: 12px; color: #4a5568;"));

        verticalLayout_7->addWidget(barChart);


        horizontalLayout_3->addWidget(chartFrame2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        recentFrame = new QFrame(HomePage);
        recentFrame->setObjectName("recentFrame");
        verticalLayout_8 = new QVBoxLayout(recentFrame);
        verticalLayout_8->setObjectName("verticalLayout_8");
        recentTitle = new QLabel(recentFrame);
        recentTitle->setObjectName("recentTitle");
        recentTitle->setStyleSheet(QString::fromUtf8("font-size: 16px; font-weight: bold; color: #2d3748;"));

        verticalLayout_8->addWidget(recentTitle);

        recentList = new QLabel(recentFrame);
        recentList->setObjectName("recentList");
        recentList->setStyleSheet(QString::fromUtf8("font-size: 13px; color: #4a5568;"));

        verticalLayout_8->addWidget(recentList);


        horizontalLayout_4->addWidget(recentFrame);

        quickFrame = new QFrame(HomePage);
        quickFrame->setObjectName("quickFrame");
        verticalLayout_9 = new QVBoxLayout(quickFrame);
        verticalLayout_9->setObjectName("verticalLayout_9");
        quickTitle = new QLabel(quickFrame);
        quickTitle->setObjectName("quickTitle");
        quickTitle->setStyleSheet(QString::fromUtf8("font-size: 16px; font-weight: bold; color: #2d3748;"));

        verticalLayout_9->addWidget(quickTitle);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        AddStudentsquickBtn = new QPushButton(quickFrame);
        AddStudentsquickBtn->setObjectName("AddStudentsquickBtn");
        AddStudentsquickBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: #4299e1;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 10px;\n"
"    font-size: 13px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: #3182ce;\n"
"}"));

        gridLayout->addWidget(AddStudentsquickBtn, 0, 0, 1, 1);

        AddTeachersquickBtn = new QPushButton(quickFrame);
        AddTeachersquickBtn->setObjectName("AddTeachersquickBtn");
        AddTeachersquickBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: #48bb78;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 10px;\n"
"    font-size: 13px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: #38a169;\n"
"}"));

        gridLayout->addWidget(AddTeachersquickBtn, 0, 1, 1, 1);

        quickBtn3 = new QPushButton(quickFrame);
        quickBtn3->setObjectName("quickBtn3");
        quickBtn3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: #ed8936;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 10px;\n"
"    font-size: 13px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: #dd6b20;\n"
"}"));

        gridLayout->addWidget(quickBtn3, 1, 0, 1, 1);

        quickBtn4 = new QPushButton(quickFrame);
        quickBtn4->setObjectName("quickBtn4");
        quickBtn4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: #805ad5;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 10px;\n"
"    font-size: 13px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: #6b46c1;\n"
"}"));

        gridLayout->addWidget(quickBtn4, 1, 1, 1, 1);


        verticalLayout_9->addLayout(gridLayout);


        horizontalLayout_4->addWidget(quickFrame);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(HomePage);

        QMetaObject::connectSlotsByName(HomePage);
    } // setupUi

    void retranslateUi(QWidget *HomePage)
    {
        welcomeLabel->setText(QCoreApplication::translate("HomePage", "\346\254\242\350\277\216\344\275\277\347\224\250\345\255\246\347\224\237\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        userLabel->setText(QCoreApplication::translate("HomePage", "\347\256\241\347\220\206\345\221\230\357\274\232admin", nullptr));
        studentIcon->setText(QCoreApplication::translate("HomePage", "\345\255\246\347\224\237", nullptr));
        studentCount->setText(QCoreApplication::translate("HomePage", "1,286", nullptr));
        studentLabel->setText(QCoreApplication::translate("HomePage", "\345\255\246\347\224\237\346\200\273\346\225\260", nullptr));
        teacherIcon->setText(QCoreApplication::translate("HomePage", "\346\225\231\345\270\210", nullptr));
        teacherCount->setText(QCoreApplication::translate("HomePage", "320", nullptr));
        teacherLabel->setText(QCoreApplication::translate("HomePage", "\346\225\231\345\270\210\346\200\273\346\225\260", nullptr));
        classIcon->setText(QCoreApplication::translate("HomePage", "\347\217\255\347\272\247", nullptr));
        classCount->setText(QCoreApplication::translate("HomePage", "48", nullptr));
        classLabel->setText(QCoreApplication::translate("HomePage", "\347\217\255\347\272\247\346\200\273\346\225\260", nullptr));
        collegeIcon->setText(QCoreApplication::translate("HomePage", "\345\255\246\346\240\241\357\270\217", nullptr));
        collegeCount->setText(QCoreApplication::translate("HomePage", "6", nullptr));
        collegeLabel->setText(QCoreApplication::translate("HomePage", "\345\255\246\351\231\242\346\200\273\346\225\260", nullptr));
        chart1Title->setText(QCoreApplication::translate("HomePage", "\345\255\246\347\224\237\346\200\247\345\210\253\346\257\224\344\276\213", nullptr));
        pieChart->setText(QCoreApplication::translate("HomePage", "\n"
"\346\200\247\345\210\253\346\257\224\344\276\213\n"
"\342\224\214\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\220\n"
"\342\224\202    \347\224\267: 58%  \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\224\202\n"
"\342\224\202    \345\245\263: 42%  \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210    \342\224\202\n"
"\342\224\224\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342"
                        "\224\200\342\224\200\342\224\230\n"
"           ", nullptr));
        chart2Title->setText(QCoreApplication::translate("HomePage", "\345\220\204\345\255\246\351\231\242\345\255\246\347\224\237\344\272\272\346\225\260\347\273\237\350\256\241", nullptr));
        barChart->setText(QCoreApplication::translate("HomePage", "\n"
"\345\255\246\351\231\242\344\272\272\346\225\260\n"
"\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\n"
"\350\256\241\347\256\227\346\234\272\345\255\246\351\231\242   \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210 320\n"
"\347\224\265\345\255\220\345\267\245\347\250\213\345\255\246\351\231\242 \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342"
                        "\226\210\342\226\210\342\226\210\342\226\210      250\n"
"\350\275\257\344\273\266\345\267\245\347\250\213\345\255\246\351\231\242 \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210         220\n"
"\347\273\217\346\265\216\347\256\241\347\220\206\345\255\246\351\231\242 \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210          200\n"
"\345\244\226\345\233\275\350\257\255\345\255\246\351\231\242   \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210              180\n"
"\350\211\272\346\234\257\345\255\246\351\231\242     \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210                116\n"
"\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200"
                        "\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\n"
"           ", nullptr));
        recentTitle->setText(QCoreApplication::translate("HomePage", "\346\234\200\350\277\221\345\212\250\346\200\201", nullptr));
        recentList->setText(QCoreApplication::translate("HomePage", "\n"
"\342\200\242 \345\255\246\347\224\237\345\274\240\344\270\211\346\210\220\345\212\237\346\263\250\345\206\214\346\226\260\350\264\246\345\217\267       2024-01-15 10:30\n"
"\342\200\242 \346\225\231\345\270\210\346\235\216\345\233\233\346\233\264\346\226\260\344\270\252\344\272\272\344\277\241\346\201\257         2024-01-15 09:20\n"
"\342\200\242 \346\226\260\345\242\236\347\217\255\347\272\2472024\347\272\2471\347\217\255           2024-01-14 16:45\n"
"\342\200\242 \345\255\246\347\224\237\347\216\213\344\272\224\346\217\220\344\272\244\351\200\211\350\257\276\347\224\263\350\257\267         2024-01-14 14:20\n"
"\342\200\242 \345\255\246\351\231\242\345\217\221\345\270\203\346\226\260\345\255\246\346\234\237\351\200\232\347\237\245           2024-01-14 10:00\n"
"\342\200\242 \347\224\250\346\210\267admin\347\231\273\345\275\225\347\263\273\347\273\237           2024-01-15 08:00\n"
"           ", nullptr));
        quickTitle->setText(QCoreApplication::translate("HomePage", "\345\277\253\346\215\267\346\223\215\344\275\234", nullptr));
        AddStudentsquickBtn->setText(QCoreApplication::translate("HomePage", "\346\267\273\345\212\240\345\255\246\347\224\237", nullptr));
        AddTeachersquickBtn->setText(QCoreApplication::translate("HomePage", "\346\267\273\345\212\240\346\225\231\345\270\210", nullptr));
        quickBtn3->setText(QCoreApplication::translate("HomePage", "\346\225\260\346\215\256\347\273\237\350\256\241", nullptr));
        quickBtn4->setText(QCoreApplication::translate("HomePage", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
        (void)HomePage;
    } // retranslateUi

};

namespace Ui {
    class HomePage: public Ui_HomePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEPAGE_H
