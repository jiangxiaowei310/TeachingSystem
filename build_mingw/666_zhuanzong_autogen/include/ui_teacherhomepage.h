/********************************************************************************
** Form generated from reading UI file 'teacherhomepage.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHERHOMEPAGE_H
#define UI_TEACHERHOMEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TeacherHomePage
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *headerFrame;
    QHBoxLayout *horizontalLayout;
    QLabel *teacherNameLabel;
    QSpacerItem *horizontalSpacer;
    QLabel *dateLabel;
    QHBoxLayout *horizontalLayout_2;
    QFrame *studentCountFrame;
    QVBoxLayout *verticalLayout_2;
    QLabel *studentIcon;
    QLabel *studentCount;
    QLabel *studentLabel;
    QFrame *courseCountFrame;
    QVBoxLayout *verticalLayout_3;
    QLabel *courseIcon;
    QLabel *courseCount;
    QLabel *courseLabel;
    QFrame *taskCountFrame;
    QVBoxLayout *verticalLayout_4;
    QLabel *taskIcon;
    QLabel *taskCount;
    QLabel *taskLabel;
    QFrame *hoursCountFrame;
    QVBoxLayout *verticalLayout_5;
    QLabel *hoursIcon;
    QLabel *hoursCount;
    QLabel *hoursLabel;
    QFrame *noticeFrame;
    QVBoxLayout *verticalLayout_6;
    QLabel *noticeTitle;
    QLabel *notice1;
    QLabel *notice2;
    QLabel *notice3;
    QFrame *scheduleFrame;
    QVBoxLayout *verticalLayout_7;
    QLabel *scheduleTitle;
    QLabel *schedule1;
    QLabel *schedule2;
    QLabel *schedule3;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *TeacherHomePage)
    {
        if (TeacherHomePage->objectName().isEmpty())
            TeacherHomePage->setObjectName("TeacherHomePage");
        TeacherHomePage->resize(1000, 650);
        TeacherHomePage->setStyleSheet(QString::fromUtf8("QWidget {\n"
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
        verticalLayout = new QVBoxLayout(TeacherHomePage);
        verticalLayout->setObjectName("verticalLayout");
        headerFrame = new QFrame(TeacherHomePage);
        headerFrame->setObjectName("headerFrame");
        horizontalLayout = new QHBoxLayout(headerFrame);
        horizontalLayout->setObjectName("horizontalLayout");
        teacherNameLabel = new QLabel(headerFrame);
        teacherNameLabel->setObjectName("teacherNameLabel");
        teacherNameLabel->setStyleSheet(QString::fromUtf8("font-size: 24px; font-weight: bold; color: #1a202c;"));

        horizontalLayout->addWidget(teacherNameLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        dateLabel = new QLabel(headerFrame);
        dateLabel->setObjectName("dateLabel");
        dateLabel->setStyleSheet(QString::fromUtf8("font-size: 14px; color: #718096;"));

        horizontalLayout->addWidget(dateLabel);


        verticalLayout->addWidget(headerFrame);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        studentCountFrame = new QFrame(TeacherHomePage);
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

        courseCountFrame = new QFrame(TeacherHomePage);
        courseCountFrame->setObjectName("courseCountFrame");
        courseCountFrame->setStyleSheet(QString::fromUtf8("QFrame {\n"
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
        verticalLayout_3 = new QVBoxLayout(courseCountFrame);
        verticalLayout_3->setObjectName("verticalLayout_3");
        courseIcon = new QLabel(courseCountFrame);
        courseIcon->setObjectName("courseIcon");
        courseIcon->setStyleSheet(QString::fromUtf8("font-size: 32px;"));

        verticalLayout_3->addWidget(courseIcon);

        courseCount = new QLabel(courseCountFrame);
        courseCount->setObjectName("courseCount");
        courseCount->setStyleSheet(QString::fromUtf8("font-size: 28px; font-weight: bold;"));

        verticalLayout_3->addWidget(courseCount);

        courseLabel = new QLabel(courseCountFrame);
        courseLabel->setObjectName("courseLabel");
        courseLabel->setStyleSheet(QString::fromUtf8("font-size: 14px; opacity: 0.9;"));

        verticalLayout_3->addWidget(courseLabel);


        horizontalLayout_2->addWidget(courseCountFrame);

        taskCountFrame = new QFrame(TeacherHomePage);
        taskCountFrame->setObjectName("taskCountFrame");
        taskCountFrame->setStyleSheet(QString::fromUtf8("QFrame {\n"
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
        verticalLayout_4 = new QVBoxLayout(taskCountFrame);
        verticalLayout_4->setObjectName("verticalLayout_4");
        taskIcon = new QLabel(taskCountFrame);
        taskIcon->setObjectName("taskIcon");
        taskIcon->setStyleSheet(QString::fromUtf8("font-size: 32px;"));

        verticalLayout_4->addWidget(taskIcon);

        taskCount = new QLabel(taskCountFrame);
        taskCount->setObjectName("taskCount");
        taskCount->setStyleSheet(QString::fromUtf8("font-size: 28px; font-weight: bold;"));

        verticalLayout_4->addWidget(taskCount);

        taskLabel = new QLabel(taskCountFrame);
        taskLabel->setObjectName("taskLabel");
        taskLabel->setStyleSheet(QString::fromUtf8("font-size: 14px; opacity: 0.9;"));

        verticalLayout_4->addWidget(taskLabel);


        horizontalLayout_2->addWidget(taskCountFrame);

        hoursCountFrame = new QFrame(TeacherHomePage);
        hoursCountFrame->setObjectName("hoursCountFrame");
        hoursCountFrame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"        background-color: qlineargradient(\n"
"            x1:0, y1:0,\n"
"            x2:1, y2:1,\n"
"            stop:0 #fa709a,\n"
"            stop:1 #fee140\n"
"        );\n"
"    border: none;\n"
"}\n"
"QLabel {\n"
"    color: white;\n"
"}"));
        verticalLayout_5 = new QVBoxLayout(hoursCountFrame);
        verticalLayout_5->setObjectName("verticalLayout_5");
        hoursIcon = new QLabel(hoursCountFrame);
        hoursIcon->setObjectName("hoursIcon");
        hoursIcon->setStyleSheet(QString::fromUtf8("font-size: 32px;"));

        verticalLayout_5->addWidget(hoursIcon);

        hoursCount = new QLabel(hoursCountFrame);
        hoursCount->setObjectName("hoursCount");
        hoursCount->setStyleSheet(QString::fromUtf8("font-size: 28px; font-weight: bold;"));

        verticalLayout_5->addWidget(hoursCount);

        hoursLabel = new QLabel(hoursCountFrame);
        hoursLabel->setObjectName("hoursLabel");
        hoursLabel->setStyleSheet(QString::fromUtf8("font-size: 14px; opacity: 0.9;"));

        verticalLayout_5->addWidget(hoursLabel);


        horizontalLayout_2->addWidget(hoursCountFrame);


        verticalLayout->addLayout(horizontalLayout_2);

        noticeFrame = new QFrame(TeacherHomePage);
        noticeFrame->setObjectName("noticeFrame");
        verticalLayout_6 = new QVBoxLayout(noticeFrame);
        verticalLayout_6->setObjectName("verticalLayout_6");
        noticeTitle = new QLabel(noticeFrame);
        noticeTitle->setObjectName("noticeTitle");
        noticeTitle->setStyleSheet(QString::fromUtf8("font-size: 18px; font-weight: bold; color: #2d3748;"));

        verticalLayout_6->addWidget(noticeTitle);

        notice1 = new QLabel(noticeFrame);
        notice1->setObjectName("notice1");
        notice1->setStyleSheet(QString::fromUtf8("font-size: 14px; color: #4a5568; padding: 5px 0;"));

        verticalLayout_6->addWidget(notice1);

        notice2 = new QLabel(noticeFrame);
        notice2->setObjectName("notice2");
        notice2->setStyleSheet(QString::fromUtf8("font-size: 14px; color: #4a5568; padding: 5px 0;"));

        verticalLayout_6->addWidget(notice2);

        notice3 = new QLabel(noticeFrame);
        notice3->setObjectName("notice3");
        notice3->setStyleSheet(QString::fromUtf8("font-size: 14px; color: #4a5568; padding: 5px 0;"));

        verticalLayout_6->addWidget(notice3);


        verticalLayout->addWidget(noticeFrame);

        scheduleFrame = new QFrame(TeacherHomePage);
        scheduleFrame->setObjectName("scheduleFrame");
        verticalLayout_7 = new QVBoxLayout(scheduleFrame);
        verticalLayout_7->setObjectName("verticalLayout_7");
        scheduleTitle = new QLabel(scheduleFrame);
        scheduleTitle->setObjectName("scheduleTitle");
        scheduleTitle->setStyleSheet(QString::fromUtf8("font-size: 18px; font-weight: bold; color: #2d3748;"));

        verticalLayout_7->addWidget(scheduleTitle);

        schedule1 = new QLabel(scheduleFrame);
        schedule1->setObjectName("schedule1");
        schedule1->setStyleSheet(QString::fromUtf8("font-size: 14px; color: #4a5568; padding: 5px 0;"));

        verticalLayout_7->addWidget(schedule1);

        schedule2 = new QLabel(scheduleFrame);
        schedule2->setObjectName("schedule2");
        schedule2->setStyleSheet(QString::fromUtf8("font-size: 14px; color: #4a5568; padding: 5px 0;"));

        verticalLayout_7->addWidget(schedule2);

        schedule3 = new QLabel(scheduleFrame);
        schedule3->setObjectName("schedule3");
        schedule3->setStyleSheet(QString::fromUtf8("font-size: 14px; color: #4a5568; padding: 5px 0;"));

        verticalLayout_7->addWidget(schedule3);


        verticalLayout->addWidget(scheduleFrame);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(TeacherHomePage);

        QMetaObject::connectSlotsByName(TeacherHomePage);
    } // setupUi

    void retranslateUi(QWidget *TeacherHomePage)
    {
        teacherNameLabel->setText(QCoreApplication::translate("TeacherHomePage", "\346\254\242\350\277\216\344\275\277\347\224\250\346\225\231\345\270\210\345\267\245\344\275\234\345\217\260", nullptr));
        dateLabel->setText(QCoreApplication::translate("TeacherHomePage", "\344\273\212\345\244\251\346\230\257 2026\345\271\2645\346\234\21028\346\227\245 \346\230\237\346\234\237\345\233\233", nullptr));
        studentIcon->setText(QCoreApplication::translate("TeacherHomePage", "\360\237\221\250\342\200\215\360\237\216\223", nullptr));
        studentCount->setText(QCoreApplication::translate("TeacherHomePage", "45", nullptr));
        studentLabel->setText(QCoreApplication::translate("TeacherHomePage", "\346\216\210\350\257\276\345\255\246\347\224\237", nullptr));
        courseIcon->setText(QCoreApplication::translate("TeacherHomePage", "\360\237\223\232", nullptr));
        courseCount->setText(QCoreApplication::translate("TeacherHomePage", "3", nullptr));
        courseLabel->setText(QCoreApplication::translate("TeacherHomePage", "\346\234\254\345\255\246\346\234\237\350\257\276\347\250\213", nullptr));
        taskIcon->setText(QCoreApplication::translate("TeacherHomePage", "\360\237\223\235", nullptr));
        taskCount->setText(QCoreApplication::translate("TeacherHomePage", "5", nullptr));
        taskLabel->setText(QCoreApplication::translate("TeacherHomePage", "\345\276\205\345\275\225\345\205\245\346\210\220\347\273\251", nullptr));
        hoursIcon->setText(QCoreApplication::translate("TeacherHomePage", "\342\217\260", nullptr));
        hoursCount->setText(QCoreApplication::translate("TeacherHomePage", "12", nullptr));
        hoursLabel->setText(QCoreApplication::translate("TeacherHomePage", "\346\234\254\345\221\250\350\257\276\346\227\266", nullptr));
        noticeTitle->setText(QCoreApplication::translate("TeacherHomePage", "\360\237\223\242 \347\263\273\347\273\237\345\205\254\345\221\212", nullptr));
        notice1->setText(QCoreApplication::translate("TeacherHomePage", "\342\200\242 \346\234\237\344\270\255\350\200\203\350\257\225\346\210\220\347\273\251\345\275\225\345\205\245\346\210\252\346\255\242\346\227\266\351\227\264\357\274\2322026\345\271\2646\346\234\21015\346\227\245", nullptr));
        notice2->setText(QCoreApplication::translate("TeacherHomePage", "\342\200\242 \346\225\231\345\255\246\345\244\247\347\272\262\346\233\264\346\226\260\351\200\232\347\237\245\357\274\214\350\257\267\345\217\212\346\227\266\346\237\245\347\234\213\345\271\266\347\241\256\350\256\244", nullptr));
        notice3->setText(QCoreApplication::translate("TeacherHomePage", "\342\200\242 \344\270\213\345\221\250\344\270\211\344\270\213\345\215\210\345\217\254\345\274\200\346\225\231\345\255\246\347\240\224\350\256\250\344\274\232\357\274\214\350\257\267\345\207\206\346\227\266\345\217\202\345\212\240", nullptr));
        scheduleTitle->setText(QCoreApplication::translate("TeacherHomePage", "\360\237\223\205 \344\273\212\346\227\245\350\257\276\350\241\250", nullptr));
        schedule1->setText(QCoreApplication::translate("TeacherHomePage", "08:00 - 09:40  \351\253\230\347\255\211\346\225\260\345\255\246\357\274\2102023\347\272\247\350\256\241\347\256\227\346\234\2721\347\217\255\357\274\211", nullptr));
        schedule2->setText(QCoreApplication::translate("TeacherHomePage", "10:00 - 11:40  \347\272\277\346\200\247\344\273\243\346\225\260\357\274\2102023\347\272\247\350\275\257\344\273\266\345\267\245\347\250\2132\347\217\255\357\274\211", nullptr));
        schedule3->setText(QCoreApplication::translate("TeacherHomePage", "14:00 - 15:40  \346\246\202\347\216\207\350\256\272\344\270\216\346\225\260\347\220\206\347\273\237\350\256\241\357\274\2102022\347\272\247\345\244\247\346\225\260\346\215\2561\347\217\255\357\274\211", nullptr));
        (void)TeacherHomePage;
    } // retranslateUi

};

namespace Ui {
    class TeacherHomePage: public Ui_TeacherHomePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHERHOMEPAGE_H
