/********************************************************************************
** Form generated from reading UI file 'studentgradepage.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTGRADEPAGE_H
#define UI_STUDENTGRADEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentGradePage
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *headerFrame;
    QHBoxLayout *horizontalLayout;
    QLabel *titleLabel;
    QSpacerItem *horizontalSpacer;
    QComboBox *semesterCombo;
    QPushButton *exportBtn;
    QTableView *tableView;
    QFrame *summaryFrame;
    QHBoxLayout *horizontalLayout_2;
    QLabel *gpaLabel;
    QLabel *creditLabel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *StudentGradePage)
    {
        if (StudentGradePage->objectName().isEmpty())
            StudentGradePage->setObjectName("StudentGradePage");
        StudentGradePage->resize(1000, 650);
        StudentGradePage->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background: #f7fafc;\n"
"}\n"
"QFrame {\n"
"    background: white;\n"
"    border-radius: 8px;\n"
"    border: 1px solid #e2e8f0;\n"
"}\n"
"QPushButton {\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 16px;\n"
"    font-size: 13px;\n"
"}\n"
"QTableView {\n"
"    border: 1px solid #e2e8f0;\n"
"    border-radius: 8px;\n"
"    alternate-background-color: #f7fafc;\n"
"}\n"
"QTableView::header {\n"
"    background: #4299e1;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(StudentGradePage);
        verticalLayout->setObjectName("verticalLayout");
        headerFrame = new QFrame(StudentGradePage);
        headerFrame->setObjectName("headerFrame");
        horizontalLayout = new QHBoxLayout(headerFrame);
        horizontalLayout->setObjectName("horizontalLayout");
        titleLabel = new QLabel(headerFrame);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setStyleSheet(QString::fromUtf8("font-size: 20px; font-weight: bold; color: #2d3748;"));

        horizontalLayout->addWidget(titleLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        semesterCombo = new QComboBox(headerFrame);
        semesterCombo->setObjectName("semesterCombo");
        semesterCombo->setMinimumSize(QSize(150, 0));

        horizontalLayout->addWidget(semesterCombo);

        exportBtn = new QPushButton(headerFrame);
        exportBtn->setObjectName("exportBtn");
        exportBtn->setStyleSheet(QString::fromUtf8("background: #4299e1; color: white;"));

        horizontalLayout->addWidget(exportBtn);


        verticalLayout->addWidget(headerFrame);

        tableView = new QTableView(StudentGradePage);
        tableView->setObjectName("tableView");
        tableView->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);

        verticalLayout->addWidget(tableView);

        summaryFrame = new QFrame(StudentGradePage);
        summaryFrame->setObjectName("summaryFrame");
        horizontalLayout_2 = new QHBoxLayout(summaryFrame);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        gpaLabel = new QLabel(summaryFrame);
        gpaLabel->setObjectName("gpaLabel");
        gpaLabel->setStyleSheet(QString::fromUtf8("font-size: 16px; font-weight: bold; color: #2d3748;"));

        horizontalLayout_2->addWidget(gpaLabel);

        creditLabel = new QLabel(summaryFrame);
        creditLabel->setObjectName("creditLabel");
        creditLabel->setStyleSheet(QString::fromUtf8("font-size: 16px; font-weight: bold; color: #2d3748;"));

        horizontalLayout_2->addWidget(creditLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(summaryFrame);


        retranslateUi(StudentGradePage);

        QMetaObject::connectSlotsByName(StudentGradePage);
    } // setupUi

    void retranslateUi(QWidget *StudentGradePage)
    {
        titleLabel->setText(QCoreApplication::translate("StudentGradePage", "\346\210\220\347\273\251\346\237\245\350\257\242", nullptr));
        exportBtn->setText(QCoreApplication::translate("StudentGradePage", "\345\257\274\345\207\272\346\210\220\347\273\251\345\215\225", nullptr));
        gpaLabel->setText(QCoreApplication::translate("StudentGradePage", "\345\271\263\345\235\207\347\273\251\347\202\271\357\274\2323.85", nullptr));
        creditLabel->setText(QCoreApplication::translate("StudentGradePage", "\346\200\273\345\255\246\345\210\206\357\274\23285.5", nullptr));
        (void)StudentGradePage;
    } // retranslateUi

};

namespace Ui {
    class StudentGradePage: public Ui_StudentGradePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTGRADEPAGE_H
