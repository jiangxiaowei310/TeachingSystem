/********************************************************************************
** Form generated from reading UI file 'teachergradepage.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHERGRADEPAGE_H
#define UI_TEACHERGRADEPAGE_H

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

class Ui_TeacherGradePage
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *headerFrame;
    QHBoxLayout *horizontalLayout;
    QLabel *titleLabel;
    QSpacerItem *horizontalSpacer;
    QComboBox *courseCombo;
    QPushButton *inputBtn;
    QPushButton *saveBtn;
    QPushButton *importBtn;
    QTableView *tableView;

    void setupUi(QWidget *TeacherGradePage)
    {
        if (TeacherGradePage->objectName().isEmpty())
            TeacherGradePage->setObjectName("TeacherGradePage");
        TeacherGradePage->resize(1000, 650);
        TeacherGradePage->setStyleSheet(QString::fromUtf8("QWidget {\n"
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
"QLineEdit {\n"
"    border: 1px solid #e2e8f0;\n"
"    border-radius: 6px;\n"
"    padding: 8px 12px;\n"
"    font-size: 13px;\n"
"}\n"
"QTableView {\n"
"    border: 1px solid #e2e8f0;\n"
"    border-radius: 8px;\n"
"    alternate-background-color: #f7fafc;\n"
"}\n"
"QTableView::header {\n"
"    background: #48bb78;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(TeacherGradePage);
        verticalLayout->setObjectName("verticalLayout");
        headerFrame = new QFrame(TeacherGradePage);
        headerFrame->setObjectName("headerFrame");
        horizontalLayout = new QHBoxLayout(headerFrame);
        horizontalLayout->setObjectName("horizontalLayout");
        titleLabel = new QLabel(headerFrame);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setStyleSheet(QString::fromUtf8("font-size: 20px; font-weight: bold; color: #2d3748;"));

        horizontalLayout->addWidget(titleLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        courseCombo = new QComboBox(headerFrame);
        courseCombo->setObjectName("courseCombo");
        courseCombo->setMinimumSize(QSize(150, 0));

        horizontalLayout->addWidget(courseCombo);

        inputBtn = new QPushButton(headerFrame);
        inputBtn->setObjectName("inputBtn");
        inputBtn->setStyleSheet(QString::fromUtf8("background: #4299e1; color: white;"));

        horizontalLayout->addWidget(inputBtn);

        saveBtn = new QPushButton(headerFrame);
        saveBtn->setObjectName("saveBtn");
        saveBtn->setStyleSheet(QString::fromUtf8("background: #48bb78; color: white;"));

        horizontalLayout->addWidget(saveBtn);

        importBtn = new QPushButton(headerFrame);
        importBtn->setObjectName("importBtn");
        importBtn->setStyleSheet(QString::fromUtf8("background: #ed8936; color: white;"));

        horizontalLayout->addWidget(importBtn);


        verticalLayout->addWidget(headerFrame);

        tableView = new QTableView(TeacherGradePage);
        tableView->setObjectName("tableView");
        tableView->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);

        verticalLayout->addWidget(tableView);


        retranslateUi(TeacherGradePage);

        QMetaObject::connectSlotsByName(TeacherGradePage);
    } // setupUi

    void retranslateUi(QWidget *TeacherGradePage)
    {
        titleLabel->setText(QCoreApplication::translate("TeacherGradePage", "\346\210\220\347\273\251\345\275\225\345\205\245", nullptr));
        inputBtn->setText(QCoreApplication::translate("TeacherGradePage", "\345\275\225\345\205\245\346\210\220\347\273\251", nullptr));
        saveBtn->setText(QCoreApplication::translate("TeacherGradePage", "\344\277\235\345\255\230", nullptr));
        importBtn->setText(QCoreApplication::translate("TeacherGradePage", "\346\211\271\351\207\217\345\257\274\345\205\245", nullptr));
        (void)TeacherGradePage;
    } // retranslateUi

};

namespace Ui {
    class TeacherGradePage: public Ui_TeacherGradePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHERGRADEPAGE_H
