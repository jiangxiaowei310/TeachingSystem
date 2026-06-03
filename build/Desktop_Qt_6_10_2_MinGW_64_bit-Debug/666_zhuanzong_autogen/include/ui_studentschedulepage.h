/********************************************************************************
** Form generated from reading UI file 'studentschedulepage.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTSCHEDULEPAGE_H
#define UI_STUDENTSCHEDULEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentSchedulePage
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *headerFrame;
    QHBoxLayout *horizontalLayout;
    QLabel *titleLabel;
    QSpacerItem *horizontalSpacer;
    QComboBox *weekCombo;
    QFrame *scheduleFrame;
    QGridLayout *gridLayout;
    QLabel *timeLabel;
    QLabel *monLabel;
    QLabel *tueLabel;
    QLabel *wedLabel;
    QLabel *thuLabel;
    QLabel *friLabel;
    QLabel *slot1;
    QLabel *slot2;
    QLabel *slot3;
    QLabel *slot4;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *StudentSchedulePage)
    {
        if (StudentSchedulePage->objectName().isEmpty())
            StudentSchedulePage->setObjectName("StudentSchedulePage");
        StudentSchedulePage->resize(1000, 650);
        StudentSchedulePage->setStyleSheet(QString::fromUtf8("QWidget {\n"
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
        verticalLayout = new QVBoxLayout(StudentSchedulePage);
        verticalLayout->setObjectName("verticalLayout");
        headerFrame = new QFrame(StudentSchedulePage);
        headerFrame->setObjectName("headerFrame");
        horizontalLayout = new QHBoxLayout(headerFrame);
        horizontalLayout->setObjectName("horizontalLayout");
        titleLabel = new QLabel(headerFrame);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setStyleSheet(QString::fromUtf8("font-size: 20px; font-weight: bold; color: #2d3748;"));

        horizontalLayout->addWidget(titleLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        weekCombo = new QComboBox(headerFrame);
        weekCombo->setObjectName("weekCombo");
        weekCombo->setMinimumSize(QSize(120, 0));

        horizontalLayout->addWidget(weekCombo);


        verticalLayout->addWidget(headerFrame);

        scheduleFrame = new QFrame(StudentSchedulePage);
        scheduleFrame->setObjectName("scheduleFrame");
        gridLayout = new QGridLayout(scheduleFrame);
        gridLayout->setObjectName("gridLayout");
        timeLabel = new QLabel(scheduleFrame);
        timeLabel->setObjectName("timeLabel");
        timeLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        timeLabel->setStyleSheet(QString::fromUtf8("font-weight: bold; padding: 10px; background: #e2e8f0;"));

        gridLayout->addWidget(timeLabel, 0, 0, 1, 1);

        monLabel = new QLabel(scheduleFrame);
        monLabel->setObjectName("monLabel");
        monLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        monLabel->setStyleSheet(QString::fromUtf8("font-weight: bold; padding: 10px; background: #4299e1; color: white;"));

        gridLayout->addWidget(monLabel, 0, 1, 1, 1);

        tueLabel = new QLabel(scheduleFrame);
        tueLabel->setObjectName("tueLabel");
        tueLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        tueLabel->setStyleSheet(QString::fromUtf8("font-weight: bold; padding: 10px; background: #4299e1; color: white;"));

        gridLayout->addWidget(tueLabel, 0, 2, 1, 1);

        wedLabel = new QLabel(scheduleFrame);
        wedLabel->setObjectName("wedLabel");
        wedLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        wedLabel->setStyleSheet(QString::fromUtf8("font-weight: bold; padding: 10px; background: #4299e1; color: white;"));

        gridLayout->addWidget(wedLabel, 0, 3, 1, 1);

        thuLabel = new QLabel(scheduleFrame);
        thuLabel->setObjectName("thuLabel");
        thuLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        thuLabel->setStyleSheet(QString::fromUtf8("font-weight: bold; padding: 10px; background: #4299e1; color: white;"));

        gridLayout->addWidget(thuLabel, 0, 4, 1, 1);

        friLabel = new QLabel(scheduleFrame);
        friLabel->setObjectName("friLabel");
        friLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        friLabel->setStyleSheet(QString::fromUtf8("font-weight: bold; padding: 10px; background: #4299e1; color: white;"));

        gridLayout->addWidget(friLabel, 0, 5, 1, 1);

        slot1 = new QLabel(scheduleFrame);
        slot1->setObjectName("slot1");
        slot1->setAlignment(Qt::AlignmentFlag::AlignCenter);
        slot1->setStyleSheet(QString::fromUtf8("padding: 20px; background: #f7fafc;"));

        gridLayout->addWidget(slot1, 1, 0, 1, 1);

        slot2 = new QLabel(scheduleFrame);
        slot2->setObjectName("slot2");
        slot2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        slot2->setStyleSheet(QString::fromUtf8("padding: 20px; background: #f7fafc;"));

        gridLayout->addWidget(slot2, 2, 0, 1, 1);

        slot3 = new QLabel(scheduleFrame);
        slot3->setObjectName("slot3");
        slot3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        slot3->setStyleSheet(QString::fromUtf8("padding: 20px; background: #f7fafc;"));

        gridLayout->addWidget(slot3, 3, 0, 1, 1);

        slot4 = new QLabel(scheduleFrame);
        slot4->setObjectName("slot4");
        slot4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        slot4->setStyleSheet(QString::fromUtf8("padding: 20px; background: #f7fafc;"));

        gridLayout->addWidget(slot4, 4, 0, 1, 1);


        verticalLayout->addWidget(scheduleFrame);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(StudentSchedulePage);

        QMetaObject::connectSlotsByName(StudentSchedulePage);
    } // setupUi

    void retranslateUi(QWidget *StudentSchedulePage)
    {
        titleLabel->setText(QCoreApplication::translate("StudentSchedulePage", "\346\210\221\347\232\204\350\257\276\350\241\250", nullptr));
        timeLabel->setText(QCoreApplication::translate("StudentSchedulePage", "\346\227\266\351\227\264/\346\230\237\346\234\237", nullptr));
        monLabel->setText(QCoreApplication::translate("StudentSchedulePage", "\345\221\250\344\270\200", nullptr));
        tueLabel->setText(QCoreApplication::translate("StudentSchedulePage", "\345\221\250\344\272\214", nullptr));
        wedLabel->setText(QCoreApplication::translate("StudentSchedulePage", "\345\221\250\344\270\211", nullptr));
        thuLabel->setText(QCoreApplication::translate("StudentSchedulePage", "\345\221\250\345\233\233", nullptr));
        friLabel->setText(QCoreApplication::translate("StudentSchedulePage", "\345\221\250\344\272\224", nullptr));
        slot1->setText(QCoreApplication::translate("StudentSchedulePage", "\347\254\2541-2\350\212\202", nullptr));
        slot2->setText(QCoreApplication::translate("StudentSchedulePage", "\347\254\2543-4\350\212\202", nullptr));
        slot3->setText(QCoreApplication::translate("StudentSchedulePage", "\347\254\2545-6\350\212\202", nullptr));
        slot4->setText(QCoreApplication::translate("StudentSchedulePage", "\347\254\2547-8\350\212\202", nullptr));
        (void)StudentSchedulePage;
    } // retranslateUi

};

namespace Ui {
    class StudentSchedulePage: public Ui_StudentSchedulePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTSCHEDULEPAGE_H
