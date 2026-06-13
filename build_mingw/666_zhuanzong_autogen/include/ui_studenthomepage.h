/********************************************************************************
** Form generated from reading UI file 'studenthomepage.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTHOMEPAGE_H
#define UI_STUDENTHOMEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentHomePage
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *headerFrame;
    QHBoxLayout *horizontalLayout;
    QLabel *studentNameLabel;
    QSpacerItem *horizontalSpacer;
    QLabel *dateLabel;
    QHBoxLayout *horizontalLayout_2;
    QFrame *courseCountFrame;
    QVBoxLayout *verticalLayout_2;
    QLabel *courseIcon;
    QLabel *courseCount;
    QLabel *courseLabel;
    QFrame *creditFrame;
    QVBoxLayout *verticalLayout_3;
    QLabel *creditIcon;
    QLabel *creditCount;
    QLabel *creditLabel;
    QFrame *gpaFrame;
    QVBoxLayout *verticalLayout_4;
    QLabel *gpaIcon;
    QLabel *gpaCount;
    QLabel *gpaLabel;
    QFrame *rankFrame;
    QVBoxLayout *verticalLayout_5;
    QLabel *rankIcon;
    QLabel *rankCount;
    QLabel *rankLabel;
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

    void setupUi(QWidget *StudentHomePage)
    {
        if (StudentHomePage->objectName().isEmpty())
            StudentHomePage->setObjectName("StudentHomePage");
        StudentHomePage->resize(1000, 650);
        StudentHomePage->setStyleSheet(QString::fromUtf8("QWidget {\n"
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
        verticalLayout = new QVBoxLayout(StudentHomePage);
        verticalLayout->setObjectName("verticalLayout");
        headerFrame = new QFrame(StudentHomePage);
        headerFrame->setObjectName("headerFrame");
        horizontalLayout = new QHBoxLayout(headerFrame);
        horizontalLayout->setObjectName("horizontalLayout");
        studentNameLabel = new QLabel(headerFrame);
        studentNameLabel->setObjectName("studentNameLabel");
        studentNameLabel->setStyleSheet(QString::fromUtf8("font-size: 24px; font-weight: bold; color: #1a202c;"));

        horizontalLayout->addWidget(studentNameLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        dateLabel = new QLabel(headerFrame);
        dateLabel->setObjectName("dateLabel");
        dateLabel->setStyleSheet(QString::fromUtf8("font-size: 14px; color: #718096;"));

        horizontalLayout->addWidget(dateLabel);


        verticalLayout->addWidget(headerFrame);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        courseCountFrame = new QFrame(StudentHomePage);
        courseCountFrame->setObjectName("courseCountFrame");
        courseCountFrame->setStyleSheet(QString::fromUtf8("QFrame {\n"
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
        verticalLayout_2 = new QVBoxLayout(courseCountFrame);
        verticalLayout_2->setObjectName("verticalLayout_2");
        courseIcon = new QLabel(courseCountFrame);
        courseIcon->setObjectName("courseIcon");
        courseIcon->setStyleSheet(QString::fromUtf8("font-size: 32px;"));

        verticalLayout_2->addWidget(courseIcon);

        courseCount = new QLabel(courseCountFrame);
        courseCount->setObjectName("courseCount");
        courseCount->setStyleSheet(QString::fromUtf8("font-size: 28px; font-weight: bold;"));

        verticalLayout_2->addWidget(courseCount);

        courseLabel = new QLabel(courseCountFrame);
        courseLabel->setObjectName("courseLabel");
        courseLabel->setStyleSheet(QString::fromUtf8("font-size: 14px; opacity: 0.9;"));

        verticalLayout_2->addWidget(courseLabel);


        horizontalLayout_2->addWidget(courseCountFrame);

        creditFrame = new QFrame(StudentHomePage);
        creditFrame->setObjectName("creditFrame");
        creditFrame->setStyleSheet(QString::fromUtf8("QFrame {\n"
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
        verticalLayout_3 = new QVBoxLayout(creditFrame);
        verticalLayout_3->setObjectName("verticalLayout_3");
        creditIcon = new QLabel(creditFrame);
        creditIcon->setObjectName("creditIcon");
        creditIcon->setStyleSheet(QString::fromUtf8("font-size: 32px;"));

        verticalLayout_3->addWidget(creditIcon);

        creditCount = new QLabel(creditFrame);
        creditCount->setObjectName("creditCount");
        creditCount->setStyleSheet(QString::fromUtf8("font-size: 28px; font-weight: bold;"));

        verticalLayout_3->addWidget(creditCount);

        creditLabel = new QLabel(creditFrame);
        creditLabel->setObjectName("creditLabel");
        creditLabel->setStyleSheet(QString::fromUtf8("font-size: 14px; opacity: 0.9;"));

        verticalLayout_3->addWidget(creditLabel);


        horizontalLayout_2->addWidget(creditFrame);

        gpaFrame = new QFrame(StudentHomePage);
        gpaFrame->setObjectName("gpaFrame");
        gpaFrame->setStyleSheet(QString::fromUtf8("QFrame {\n"
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
        verticalLayout_4 = new QVBoxLayout(gpaFrame);
        verticalLayout_4->setObjectName("verticalLayout_4");
        gpaIcon = new QLabel(gpaFrame);
        gpaIcon->setObjectName("gpaIcon");
        gpaIcon->setStyleSheet(QString::fromUtf8("font-size: 32px;"));

        verticalLayout_4->addWidget(gpaIcon);

        gpaCount = new QLabel(gpaFrame);
        gpaCount->setObjectName("gpaCount");
        gpaCount->setStyleSheet(QString::fromUtf8("font-size: 28px; font-weight: bold;"));

        verticalLayout_4->addWidget(gpaCount);

        gpaLabel = new QLabel(gpaFrame);
        gpaLabel->setObjectName("gpaLabel");
        gpaLabel->setStyleSheet(QString::fromUtf8("font-size: 14px; opacity: 0.9;"));

        verticalLayout_4->addWidget(gpaLabel);


        horizontalLayout_2->addWidget(gpaFrame);

        rankFrame = new QFrame(StudentHomePage);
        rankFrame->setObjectName("rankFrame");
        rankFrame->setStyleSheet(QString::fromUtf8("QFrame {\n"
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
        verticalLayout_5 = new QVBoxLayout(rankFrame);
        verticalLayout_5->setObjectName("verticalLayout_5");
        rankIcon = new QLabel(rankFrame);
        rankIcon->setObjectName("rankIcon");
        rankIcon->setStyleSheet(QString::fromUtf8("font-size: 32px;"));

        verticalLayout_5->addWidget(rankIcon);

        rankCount = new QLabel(rankFrame);
        rankCount->setObjectName("rankCount");
        rankCount->setStyleSheet(QString::fromUtf8("font-size: 28px; font-weight: bold;"));

        verticalLayout_5->addWidget(rankCount);

        rankLabel = new QLabel(rankFrame);
        rankLabel->setObjectName("rankLabel");
        rankLabel->setStyleSheet(QString::fromUtf8("font-size: 14px; opacity: 0.9;"));

        verticalLayout_5->addWidget(rankLabel);


        horizontalLayout_2->addWidget(rankFrame);


        verticalLayout->addLayout(horizontalLayout_2);

        noticeFrame = new QFrame(StudentHomePage);
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

        scheduleFrame = new QFrame(StudentHomePage);
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


        retranslateUi(StudentHomePage);

        QMetaObject::connectSlotsByName(StudentHomePage);
    } // setupUi

    void retranslateUi(QWidget *StudentHomePage)
    {
        studentNameLabel->setText(QCoreApplication::translate("StudentHomePage", "\346\254\242\350\277\216\344\275\277\347\224\250\345\255\246\347\224\237\346\234\215\345\212\241\344\270\255\345\277\203", nullptr));
        dateLabel->setText(QCoreApplication::translate("StudentHomePage", "\344\273\212\345\244\251\346\230\257 2026\345\271\2645\346\234\21028\346\227\245 \346\230\237\346\234\237\345\233\233", nullptr));
        courseIcon->setText(QCoreApplication::translate("StudentHomePage", "\360\237\223\232", nullptr));
        courseCount->setText(QCoreApplication::translate("StudentHomePage", "6", nullptr));
        courseLabel->setText(QCoreApplication::translate("StudentHomePage", "\346\234\254\345\255\246\346\234\237\350\257\276\347\250\213", nullptr));
        creditIcon->setText(QCoreApplication::translate("StudentHomePage", "\360\237\216\257", nullptr));
        creditCount->setText(QCoreApplication::translate("StudentHomePage", "18.5", nullptr));
        creditLabel->setText(QCoreApplication::translate("StudentHomePage", "\345\267\262\344\277\256\345\255\246\345\210\206", nullptr));
        gpaIcon->setText(QCoreApplication::translate("StudentHomePage", "\360\237\223\212", nullptr));
        gpaCount->setText(QCoreApplication::translate("StudentHomePage", "3.85", nullptr));
        gpaLabel->setText(QCoreApplication::translate("StudentHomePage", "\345\271\263\345\235\207\347\273\251\347\202\271", nullptr));
        rankIcon->setText(QCoreApplication::translate("StudentHomePage", "\360\237\217\206", nullptr));
        rankCount->setText(QCoreApplication::translate("StudentHomePage", "5/45", nullptr));
        rankLabel->setText(QCoreApplication::translate("StudentHomePage", "\347\217\255\347\272\247\346\216\222\345\220\215", nullptr));
        noticeTitle->setText(QCoreApplication::translate("StudentHomePage", "\360\237\223\242 \345\255\246\346\240\241\345\205\254\345\221\212", nullptr));
        notice1->setText(QCoreApplication::translate("StudentHomePage", "\342\200\242 \345\205\263\344\272\2162026\345\271\264\346\232\221\345\201\207\346\224\276\345\201\207\345\256\211\346\216\222\347\232\204\351\200\232\347\237\245", nullptr));
        notice2->setText(QCoreApplication::translate("StudentHomePage", "\342\200\242 \346\234\237\346\234\253\350\200\203\350\257\225\346\227\266\351\227\264\350\241\250\345\267\262\345\217\221\345\270\203\357\274\214\350\257\267\345\217\212\346\227\266\346\237\245\347\234\213", nullptr));
        notice3->setText(QCoreApplication::translate("StudentHomePage", "\342\200\242 \345\233\276\344\271\246\351\246\206\346\232\221\346\234\237\345\274\200\346\224\276\346\227\266\351\227\264\350\260\203\346\225\264\351\200\232\347\237\245", nullptr));
        scheduleTitle->setText(QCoreApplication::translate("StudentHomePage", "\360\237\223\205 \344\273\212\346\227\245\350\257\276\347\250\213", nullptr));
        schedule1->setText(QCoreApplication::translate("StudentHomePage", "08:00 - 09:40  \351\253\230\347\255\211\346\225\260\345\255\246 @ \346\225\231\345\255\246\346\245\274A301", nullptr));
        schedule2->setText(QCoreApplication::translate("StudentHomePage", "10:00 - 11:40  \345\244\247\345\255\246\350\213\261\350\257\255 @ \346\225\231\345\255\246\346\245\274B205", nullptr));
        schedule3->setText(QCoreApplication::translate("StudentHomePage", "14:00 - 15:40  \346\225\260\346\215\256\347\273\223\346\236\204 @ \345\256\236\351\252\214\346\245\274C102", nullptr));
        (void)StudentHomePage;
    } // retranslateUi

};

namespace Ui {
    class StudentHomePage: public Ui_StudentHomePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTHOMEPAGE_H
