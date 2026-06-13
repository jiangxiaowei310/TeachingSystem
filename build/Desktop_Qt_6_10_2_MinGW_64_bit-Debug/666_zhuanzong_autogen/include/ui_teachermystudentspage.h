/********************************************************************************
** Form generated from reading UI file 'teachermystudentspage.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHERMYSTUDENTSPAGE_H
#define UI_TEACHERMYSTUDENTSPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TeacherMyStudentsPage
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *headerFrame;
    QHBoxLayout *horizontalLayout;
    QLabel *titleLabel;
    QSpacerItem *horizontalSpacer;
    QLineEdit *searchEdit;
    QPushButton *searchBtn;
    QPushButton *batchImportBtn;
    QPushButton *exportBtn;
    QTableView *tableView;

    void setupUi(QWidget *TeacherMyStudentsPage)
    {
        if (TeacherMyStudentsPage->objectName().isEmpty())
            TeacherMyStudentsPage->setObjectName("TeacherMyStudentsPage");
        TeacherMyStudentsPage->resize(1000, 650);
        TeacherMyStudentsPage->setStyleSheet(QString::fromUtf8("QWidget {\n"
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
        verticalLayout = new QVBoxLayout(TeacherMyStudentsPage);
        verticalLayout->setObjectName("verticalLayout");
        headerFrame = new QFrame(TeacherMyStudentsPage);
        headerFrame->setObjectName("headerFrame");
        horizontalLayout = new QHBoxLayout(headerFrame);
        horizontalLayout->setObjectName("horizontalLayout");
        titleLabel = new QLabel(headerFrame);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setStyleSheet(QString::fromUtf8("font-size: 20px; font-weight: bold; color: #2d3748;"));

        horizontalLayout->addWidget(titleLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        searchEdit = new QLineEdit(headerFrame);
        searchEdit->setObjectName("searchEdit");

        horizontalLayout->addWidget(searchEdit);

        searchBtn = new QPushButton(headerFrame);
        searchBtn->setObjectName("searchBtn");
        searchBtn->setStyleSheet(QString::fromUtf8("background: #48bb78; color: white;"));

        horizontalLayout->addWidget(searchBtn);

        batchImportBtn = new QPushButton(headerFrame);
        batchImportBtn->setObjectName("batchImportBtn");
        batchImportBtn->setStyleSheet(QString::fromUtf8("background: #9f7aea; color: white;"));

        horizontalLayout->addWidget(batchImportBtn);

        exportBtn = new QPushButton(headerFrame);
        exportBtn->setObjectName("exportBtn");
        exportBtn->setStyleSheet(QString::fromUtf8("background: #4299e1; color: white;"));

        horizontalLayout->addWidget(exportBtn);


        verticalLayout->addWidget(headerFrame);

        tableView = new QTableView(TeacherMyStudentsPage);
        tableView->setObjectName("tableView");
        tableView->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);

        verticalLayout->addWidget(tableView);


        retranslateUi(TeacherMyStudentsPage);

        QMetaObject::connectSlotsByName(TeacherMyStudentsPage);
    } // setupUi

    void retranslateUi(QWidget *TeacherMyStudentsPage)
    {
        titleLabel->setText(QCoreApplication::translate("TeacherMyStudentsPage", "\346\210\221\347\232\204\345\255\246\347\224\237", nullptr));
        searchEdit->setPlaceholderText(QCoreApplication::translate("TeacherMyStudentsPage", "\350\257\267\350\276\223\345\205\245\345\255\246\347\224\237\345\247\223\345\220\215\346\210\226\345\255\246\345\217\267", nullptr));
        searchBtn->setText(QCoreApplication::translate("TeacherMyStudentsPage", "\346\220\234\347\264\242", nullptr));
        batchImportBtn->setText(QCoreApplication::translate("TeacherMyStudentsPage", "\360\237\223\245 \346\211\271\351\207\217\345\257\274\345\205\245", nullptr));
        exportBtn->setText(QCoreApplication::translate("TeacherMyStudentsPage", "\345\257\274\345\207\272\345\220\215\345\215\225", nullptr));
        (void)TeacherMyStudentsPage;
    } // retranslateUi

};

namespace Ui {
    class TeacherMyStudentsPage: public Ui_TeacherMyStudentsPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHERMYSTUDENTSPAGE_H
