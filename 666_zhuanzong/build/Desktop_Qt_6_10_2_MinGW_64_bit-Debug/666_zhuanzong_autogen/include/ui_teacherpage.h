/********************************************************************************
** Form generated from reading UI file 'teacherpage.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHERPAGE_H
#define UI_TEACHERPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
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

class Ui_TeacherPage
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *headerFrame;
    QHBoxLayout *horizontalLayout;
    QLabel *titleLabel;
    QSpacerItem *horizontalSpacer;
    QLineEdit *searchEdit;
    QPushButton *searchBtn;
    QPushButton *addBtn;
    QPushButton *editBtn;
    QPushButton *deleteBtn;
    QTableView *tableView;
    QFrame *footerFrame;
    QHBoxLayout *horizontalLayout_2;
    QLabel *totalLabel;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *prevBtn;
    QLabel *pageLabel;
    QPushButton *nextBtn;
    QLabel *pageSizeLabel;
    QComboBox *pageSizeCombo;
    QLabel *pageSizeUnit;

    void setupUi(QWidget *TeacherPage)
    {
        if (TeacherPage->objectName().isEmpty())
            TeacherPage->setObjectName("TeacherPage");
        TeacherPage->resize(1000, 650);
        TeacherPage->setStyleSheet(QString::fromUtf8("QWidget {\n"
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
        verticalLayout = new QVBoxLayout(TeacherPage);
        verticalLayout->setObjectName("verticalLayout");
        headerFrame = new QFrame(TeacherPage);
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

        addBtn = new QPushButton(headerFrame);
        addBtn->setObjectName("addBtn");
        addBtn->setStyleSheet(QString::fromUtf8("background: #4299e1; color: white;"));

        horizontalLayout->addWidget(addBtn);

        editBtn = new QPushButton(headerFrame);
        editBtn->setObjectName("editBtn");
        editBtn->setStyleSheet(QString::fromUtf8("background: #ed8936; color: white;"));

        horizontalLayout->addWidget(editBtn);

        deleteBtn = new QPushButton(headerFrame);
        deleteBtn->setObjectName("deleteBtn");
        deleteBtn->setStyleSheet(QString::fromUtf8("background: #fc8181; color: white;"));

        horizontalLayout->addWidget(deleteBtn);


        verticalLayout->addWidget(headerFrame);

        tableView = new QTableView(TeacherPage);
        tableView->setObjectName("tableView");
        tableView->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);

        verticalLayout->addWidget(tableView);

        footerFrame = new QFrame(TeacherPage);
        footerFrame->setObjectName("footerFrame");
        horizontalLayout_2 = new QHBoxLayout(footerFrame);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        totalLabel = new QLabel(footerFrame);
        totalLabel->setObjectName("totalLabel");
        totalLabel->setStyleSheet(QString::fromUtf8("font-size: 13px; color: #718096;"));

        horizontalLayout_2->addWidget(totalLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        prevBtn = new QPushButton(footerFrame);
        prevBtn->setObjectName("prevBtn");
        prevBtn->setStyleSheet(QString::fromUtf8("background: #e2e8f0; color: #4a5568;"));

        horizontalLayout_2->addWidget(prevBtn);

        pageLabel = new QLabel(footerFrame);
        pageLabel->setObjectName("pageLabel");
        pageLabel->setStyleSheet(QString::fromUtf8("font-size: 13px; color: #4a5568; padding: 0 10px;"));

        horizontalLayout_2->addWidget(pageLabel);

        nextBtn = new QPushButton(footerFrame);
        nextBtn->setObjectName("nextBtn");
        nextBtn->setStyleSheet(QString::fromUtf8("background: #e2e8f0; color: #4a5568;"));

        horizontalLayout_2->addWidget(nextBtn);

        pageSizeLabel = new QLabel(footerFrame);
        pageSizeLabel->setObjectName("pageSizeLabel");
        pageSizeLabel->setStyleSheet(QString::fromUtf8("font-size: 13px; color: #718096;"));

        horizontalLayout_2->addWidget(pageSizeLabel);

        pageSizeCombo = new QComboBox(footerFrame);
        pageSizeCombo->addItem(QString());
        pageSizeCombo->addItem(QString());
        pageSizeCombo->addItem(QString());
        pageSizeCombo->setObjectName("pageSizeCombo");
        pageSizeCombo->setStyleSheet(QString::fromUtf8("border: 1px solid #e2e8f0; border-radius: 6px; padding: 5px;"));

        horizontalLayout_2->addWidget(pageSizeCombo);

        pageSizeUnit = new QLabel(footerFrame);
        pageSizeUnit->setObjectName("pageSizeUnit");
        pageSizeUnit->setStyleSheet(QString::fromUtf8("font-size: 13px; color: #718096;"));

        horizontalLayout_2->addWidget(pageSizeUnit);


        verticalLayout->addWidget(footerFrame);


        retranslateUi(TeacherPage);

        QMetaObject::connectSlotsByName(TeacherPage);
    } // setupUi

    void retranslateUi(QWidget *TeacherPage)
    {
        titleLabel->setText(QCoreApplication::translate("TeacherPage", "\346\225\231\345\270\210\347\256\241\347\220\206", nullptr));
        searchEdit->setPlaceholderText(QCoreApplication::translate("TeacherPage", "\350\257\267\350\276\223\345\205\245\345\267\245\345\217\267\346\210\226\345\247\223\345\220\215\346\237\245\350\257\242", nullptr));
        searchBtn->setText(QCoreApplication::translate("TeacherPage", "\346\220\234\347\264\242", nullptr));
        addBtn->setText(QCoreApplication::translate("TeacherPage", "\342\236\225 \346\267\273\345\212\240\346\225\231\345\270\210", nullptr));
        editBtn->setText(QCoreApplication::translate("TeacherPage", "\342\234\217\357\270\217 \347\274\226\350\276\221", nullptr));
        deleteBtn->setText(QCoreApplication::translate("TeacherPage", "\360\237\227\221\357\270\217 \345\210\240\351\231\244", nullptr));
        totalLabel->setText(QCoreApplication::translate("TeacherPage", "\345\205\261 32 \346\235\241", nullptr));
        prevBtn->setText(QCoreApplication::translate("TeacherPage", "\344\270\212\344\270\200\351\241\265", nullptr));
        pageLabel->setText(QCoreApplication::translate("TeacherPage", "1 / 2", nullptr));
        nextBtn->setText(QCoreApplication::translate("TeacherPage", "\344\270\213\344\270\200\351\241\265", nullptr));
        pageSizeLabel->setText(QCoreApplication::translate("TeacherPage", "\346\257\217\351\241\265", nullptr));
        pageSizeCombo->setItemText(0, QCoreApplication::translate("TeacherPage", "20", nullptr));
        pageSizeCombo->setItemText(1, QCoreApplication::translate("TeacherPage", "50", nullptr));
        pageSizeCombo->setItemText(2, QCoreApplication::translate("TeacherPage", "100", nullptr));

        pageSizeUnit->setText(QCoreApplication::translate("TeacherPage", "\346\235\241", nullptr));
        (void)TeacherPage;
    } // retranslateUi

};

namespace Ui {
    class TeacherPage: public Ui_TeacherPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHERPAGE_H
