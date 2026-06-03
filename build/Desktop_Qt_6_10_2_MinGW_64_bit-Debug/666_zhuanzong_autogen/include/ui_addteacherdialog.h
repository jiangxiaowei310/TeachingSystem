/********************************************************************************
** Form generated from reading UI file 'addteacherdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDTEACHERDIALOG_H
#define UI_ADDTEACHERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddTeacherDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QFrame *formFrame;
    QFormLayout *formLayout;
    QLabel *teacherNoLabel;
    QLineEdit *teacherNoEdit;
    QLabel *nameLabel;
    QLineEdit *nameEdit;
    QLabel *genderLabel;
    QComboBox *genderCombo;
    QLabel *titleLabel1;
    QComboBox *titleCombo;
    QLabel *collegeLabel;
    QComboBox *collegeCombo;
    QLabel *phoneLabel;
    QLineEdit *phoneEdit;
    QLabel *emailLabel;
    QLineEdit *emailEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *AddTeacherDialog)
    {
        if (AddTeacherDialog->objectName().isEmpty())
            AddTeacherDialog->setObjectName("AddTeacherDialog");
        AddTeacherDialog->resize(500, 454);
        AddTeacherDialog->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    background: #f7fafc;\n"
"}\n"
"QFrame {\n"
"    background: white;\n"
"    border-radius: 8px;\n"
"    border: 1px solid #e2e8f0;\n"
"}\n"
"QLabel {\n"
"    color: #4a5568;\n"
"    font-size: 14px;\n"
"}\n"
"QLineEdit {\n"
"    border: 1px solid #e2e8f0;\n"
"    border-radius: 6px;\n"
"    padding: 8px 12px;\n"
"    font-size: 14px;\n"
"    background: white;\n"
"}\n"
"QLineEdit:focus {\n"
"    border-color: #48bb78;\n"
"}\n"
"QComboBox {\n"
"    border: 1px solid #e2e8f0;\n"
"    border-radius: 6px;\n"
"    padding: 8px 12px;\n"
"    font-size: 14px;\n"
"    background: white;\n"
"}\n"
"QComboBox:focus {\n"
"    border-color: #48bb78;\n"
"}\n"
"QPushButton {\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 10px 24px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton#okBtn {\n"
"    background: #48bb78;\n"
"    color: white;\n"
"}\n"
"QPushButton#okBtn:hover {\n"
"    background: #38a169;\n"
"}\n"
"QPushButton#cancelBtn {\n"
"    background: #e2e8f0;\n"
"    color: #4a5568;\n"
""
                        "}\n"
"QPushButton#cancelBtn:hover {\n"
"    background: #cbd5e0;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(AddTeacherDialog);
        verticalLayout->setObjectName("verticalLayout");
        titleLabel = new QLabel(AddTeacherDialog);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setStyleSheet(QString::fromUtf8("font-size: 20px; font-weight: bold; color: #2d3748; padding: 10px 0;"));
        titleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        formFrame = new QFrame(AddTeacherDialog);
        formFrame->setObjectName("formFrame");
        formLayout = new QFormLayout(formFrame);
        formLayout->setObjectName("formLayout");
        teacherNoLabel = new QLabel(formFrame);
        teacherNoLabel->setObjectName("teacherNoLabel");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, teacherNoLabel);

        teacherNoEdit = new QLineEdit(formFrame);
        teacherNoEdit->setObjectName("teacherNoEdit");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, teacherNoEdit);

        nameLabel = new QLabel(formFrame);
        nameLabel->setObjectName("nameLabel");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, nameLabel);

        nameEdit = new QLineEdit(formFrame);
        nameEdit->setObjectName("nameEdit");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, nameEdit);

        genderLabel = new QLabel(formFrame);
        genderLabel->setObjectName("genderLabel");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, genderLabel);

        genderCombo = new QComboBox(formFrame);
        genderCombo->addItem(QString());
        genderCombo->addItem(QString());
        genderCombo->setObjectName("genderCombo");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, genderCombo);

        titleLabel1 = new QLabel(formFrame);
        titleLabel1->setObjectName("titleLabel1");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, titleLabel1);

        titleCombo = new QComboBox(formFrame);
        titleCombo->addItem(QString());
        titleCombo->addItem(QString());
        titleCombo->addItem(QString());
        titleCombo->addItem(QString());
        titleCombo->setObjectName("titleCombo");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, titleCombo);

        collegeLabel = new QLabel(formFrame);
        collegeLabel->setObjectName("collegeLabel");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, collegeLabel);

        collegeCombo = new QComboBox(formFrame);
        collegeCombo->setObjectName("collegeCombo");

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, collegeCombo);

        phoneLabel = new QLabel(formFrame);
        phoneLabel->setObjectName("phoneLabel");

        formLayout->setWidget(5, QFormLayout::ItemRole::LabelRole, phoneLabel);

        phoneEdit = new QLineEdit(formFrame);
        phoneEdit->setObjectName("phoneEdit");

        formLayout->setWidget(5, QFormLayout::ItemRole::FieldRole, phoneEdit);

        emailLabel = new QLabel(formFrame);
        emailLabel->setObjectName("emailLabel");

        formLayout->setWidget(6, QFormLayout::ItemRole::LabelRole, emailLabel);

        emailEdit = new QLineEdit(formFrame);
        emailEdit->setObjectName("emailEdit");

        formLayout->setWidget(6, QFormLayout::ItemRole::FieldRole, emailEdit);


        verticalLayout->addWidget(formFrame);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(AddTeacherDialog);
        okBtn->setObjectName("okBtn");

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(AddTeacherDialog);
        cancelBtn->setObjectName("cancelBtn");

        horizontalLayout->addWidget(cancelBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(AddTeacherDialog);
        QObject::connect(okBtn, &QPushButton::clicked, AddTeacherDialog, qOverload<>(&QDialog::accept));
        QObject::connect(cancelBtn, &QPushButton::clicked, AddTeacherDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddTeacherDialog);
    } // setupUi

    void retranslateUi(QDialog *AddTeacherDialog)
    {
        AddTeacherDialog->setWindowTitle(QCoreApplication::translate("AddTeacherDialog", "\346\267\273\345\212\240\346\225\231\345\270\210", nullptr));
        titleLabel->setText(QCoreApplication::translate("AddTeacherDialog", "\346\267\273\345\212\240\346\226\260\346\225\231\345\270\210", nullptr));
        teacherNoLabel->setText(QCoreApplication::translate("AddTeacherDialog", "\345\267\245\345\217\267 *", nullptr));
        teacherNoEdit->setPlaceholderText(QCoreApplication::translate("AddTeacherDialog", "\350\257\267\350\276\223\345\205\245\345\267\245\345\217\267", nullptr));
        nameLabel->setText(QCoreApplication::translate("AddTeacherDialog", "\345\247\223\345\220\215 *", nullptr));
        nameEdit->setPlaceholderText(QCoreApplication::translate("AddTeacherDialog", "\350\257\267\350\276\223\345\205\245\345\247\223\345\220\215", nullptr));
        genderLabel->setText(QCoreApplication::translate("AddTeacherDialog", "\346\200\247\345\210\253 *", nullptr));
        genderCombo->setItemText(0, QCoreApplication::translate("AddTeacherDialog", "\347\224\267", nullptr));
        genderCombo->setItemText(1, QCoreApplication::translate("AddTeacherDialog", "\345\245\263", nullptr));

        titleLabel1->setText(QCoreApplication::translate("AddTeacherDialog", "\350\201\214\347\247\260 *", nullptr));
        titleCombo->setItemText(0, QCoreApplication::translate("AddTeacherDialog", "\345\212\251\346\225\231", nullptr));
        titleCombo->setItemText(1, QCoreApplication::translate("AddTeacherDialog", "\350\256\262\345\270\210", nullptr));
        titleCombo->setItemText(2, QCoreApplication::translate("AddTeacherDialog", "\345\211\257\346\225\231\346\216\210", nullptr));
        titleCombo->setItemText(3, QCoreApplication::translate("AddTeacherDialog", "\346\225\231\346\216\210", nullptr));

        collegeLabel->setText(QCoreApplication::translate("AddTeacherDialog", "\345\255\246\351\231\242 *", nullptr));
        phoneLabel->setText(QCoreApplication::translate("AddTeacherDialog", "\350\201\224\347\263\273\347\224\265\350\257\235", nullptr));
        phoneEdit->setPlaceholderText(QCoreApplication::translate("AddTeacherDialog", "\350\257\267\350\276\223\345\205\245\350\201\224\347\263\273\347\224\265\350\257\235", nullptr));
        emailLabel->setText(QCoreApplication::translate("AddTeacherDialog", "\351\202\256\347\256\261", nullptr));
        emailEdit->setPlaceholderText(QCoreApplication::translate("AddTeacherDialog", "\350\257\267\350\276\223\345\205\245\351\202\256\347\256\261\357\274\210\345\217\257\351\200\211\357\274\211", nullptr));
        okBtn->setText(QCoreApplication::translate("AddTeacherDialog", "\347\241\256\345\256\232\346\267\273\345\212\240", nullptr));
        cancelBtn->setText(QCoreApplication::translate("AddTeacherDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddTeacherDialog: public Ui_AddTeacherDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTEACHERDIALOG_H
