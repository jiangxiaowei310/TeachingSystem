/********************************************************************************
** Form generated from reading UI file 'studentcoursepage.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTCOURSEPAGE_H
#define UI_STUDENTCOURSEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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

class Ui_StudentCoursePage
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *headerFrame;
    QHBoxLayout *horizontalLayout;
    QLabel *titleLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *selectBtn;
    QPushButton *dropBtn;
    QTableView *tableView;

    void setupUi(QWidget *StudentCoursePage)
    {
        if (StudentCoursePage->objectName().isEmpty())
            StudentCoursePage->setObjectName("StudentCoursePage");
        StudentCoursePage->resize(1000, 650);
        StudentCoursePage->setStyleSheet(QString::fromUtf8("QWidget {\n"
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
        verticalLayout = new QVBoxLayout(StudentCoursePage);
        verticalLayout->setObjectName("verticalLayout");
        headerFrame = new QFrame(StudentCoursePage);
        headerFrame->setObjectName("headerFrame");
        horizontalLayout = new QHBoxLayout(headerFrame);
        horizontalLayout->setObjectName("horizontalLayout");
        titleLabel = new QLabel(headerFrame);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setStyleSheet(QString::fromUtf8("font-size: 20px; font-weight: bold; color: #2d3748;"));

        horizontalLayout->addWidget(titleLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        selectBtn = new QPushButton(headerFrame);
        selectBtn->setObjectName("selectBtn");
        selectBtn->setStyleSheet(QString::fromUtf8("background: #48bb78; color: white;"));

        horizontalLayout->addWidget(selectBtn);

        dropBtn = new QPushButton(headerFrame);
        dropBtn->setObjectName("dropBtn");
        dropBtn->setStyleSheet(QString::fromUtf8("background: #fc8181; color: white;"));

        horizontalLayout->addWidget(dropBtn);


        verticalLayout->addWidget(headerFrame);

        tableView = new QTableView(StudentCoursePage);
        tableView->setObjectName("tableView");
        tableView->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);

        verticalLayout->addWidget(tableView);


        retranslateUi(StudentCoursePage);

        QMetaObject::connectSlotsByName(StudentCoursePage);
    } // setupUi

    void retranslateUi(QWidget *StudentCoursePage)
    {
        titleLabel->setText(QCoreApplication::translate("StudentCoursePage", "\346\210\221\347\232\204\350\257\276\347\250\213", nullptr));
        selectBtn->setText(QCoreApplication::translate("StudentCoursePage", "\351\200\211\350\257\276", nullptr));
        dropBtn->setText(QCoreApplication::translate("StudentCoursePage", "\351\200\200\350\257\276", nullptr));
        (void)StudentCoursePage;
    } // retranslateUi

};

namespace Ui {
    class StudentCoursePage: public Ui_StudentCoursePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTCOURSEPAGE_H
