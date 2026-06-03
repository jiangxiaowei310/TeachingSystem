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

class Ui_TeacherCoursePage
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *headerFrame;
    QHBoxLayout *horizontalLayout;
    QLabel *titleLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *addBtn;
    QPushButton *editBtn;
    QTableView *tableView;

    void setupUi(QWidget *TeacherCoursePage)
    {
        if (TeacherCoursePage->objectName().isEmpty())
            TeacherCoursePage->setObjectName("TeacherCoursePage");
        TeacherCoursePage->resize(1000, 650);
        TeacherCoursePage->setStyleSheet(QString::fromUtf8("QWidget {\n"
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
"    background: #48bb78;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(TeacherCoursePage);
        verticalLayout->setObjectName("verticalLayout");
        headerFrame = new QFrame(TeacherCoursePage);
        headerFrame->setObjectName("headerFrame");
        horizontalLayout = new QHBoxLayout(headerFrame);
        horizontalLayout->setObjectName("horizontalLayout");
        titleLabel = new QLabel(headerFrame);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setStyleSheet(QString::fromUtf8("font-size: 20px; font-weight: bold; color: #2d3748;"));

        horizontalLayout->addWidget(titleLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        addBtn = new QPushButton(headerFrame);
        addBtn->setObjectName("addBtn");
        addBtn->setStyleSheet(QString::fromUtf8("background: #4299e1; color: white;"));

        horizontalLayout->addWidget(addBtn);

        editBtn = new QPushButton(headerFrame);
        editBtn->setObjectName("editBtn");
        editBtn->setStyleSheet(QString::fromUtf8("background: #ed8936; color: white;"));

        horizontalLayout->addWidget(editBtn);


        verticalLayout->addWidget(headerFrame);

        tableView = new QTableView(TeacherCoursePage);
        tableView->setObjectName("tableView");
        tableView->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);

        verticalLayout->addWidget(tableView);


        retranslateUi(TeacherCoursePage);

        QMetaObject::connectSlotsByName(TeacherCoursePage);
    } // setupUi

    void retranslateUi(QWidget *TeacherCoursePage)
    {
        titleLabel->setText(QCoreApplication::translate("TeacherCoursePage", "\350\257\276\347\250\213\347\256\241\347\220\206", nullptr));
        addBtn->setText(QCoreApplication::translate("TeacherCoursePage", "\346\267\273\345\212\240\350\257\276\347\250\213\350\265\204\346\226\231", nullptr));
        editBtn->setText(QCoreApplication::translate("TeacherCoursePage", "\347\274\226\350\276\221\345\244\247\347\272\262", nullptr));
        (void)TeacherCoursePage;
    } // retranslateUi

};

namespace Ui {
    class TeacherCoursePage: public Ui_TeacherCoursePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHERCOURSEPAGE_H
