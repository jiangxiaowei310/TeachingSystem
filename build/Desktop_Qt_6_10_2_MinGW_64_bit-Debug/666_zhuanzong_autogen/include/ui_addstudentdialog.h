/********************************************************************************
** Form generated from reading UI file 'addstudentdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSTUDENTDIALOG_H
#define UI_ADDSTUDENTDIALOG_H

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

class Ui_AddStudentDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QFrame *formFrame;
    QFormLayout *formLayout;
    QLabel *stuNoLabel;
    QLineEdit *stuNoEdit;
    QLabel *nameLabel;
    QLineEdit *nameEdit;
    QLabel *genderLabel;
    QComboBox *genderCombo;
    QLabel *collegeLabel;
    QComboBox *collegeCombo;
    QLabel *majorLabel;
    QComboBox *majorCombo;
    QLabel *classLabel;
    QComboBox *classCombo;
    QLabel *gradeLabel;
    QLineEdit *gradeEdit;
    QLabel *phoneLabel;
    QLineEdit *phoneEdit;
    QLabel *emailLabel;
    QLineEdit *emailEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *AddStudentDialog)
    {
        if (AddStudentDialog->objectName().isEmpty())
            AddStudentDialog->setObjectName("AddStudentDialog");
        AddStudentDialog->resize(500, 450);
        AddStudentDialog->setStyleSheet(QString::fromUtf8("QDialog {\n"
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
"    border-color: #4299e1;\n"
"}\n"
"QComboBox {\n"
"    border: 1px solid #e2e8f0;\n"
"    border-radius: 6px;\n"
"    padding: 8px 12px;\n"
"    font-size: 14px;\n"
"    background: white;\n"
"}\n"
"QComboBox:focus {\n"
"    border-color: #4299e1;\n"
"}\n"
"QPushButton {\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 10px 24px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton#okBtn {\n"
"    background: #4299e1;\n"
"    color: white;\n"
"}\n"
"QPushButton#okBtn:hover {\n"
"    background: #3182ce;\n"
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
        verticalLayout = new QVBoxLayout(AddStudentDialog);
        verticalLayout->setObjectName("verticalLayout");
        titleLabel = new QLabel(AddStudentDialog);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setStyleSheet(QString::fromUtf8("font-size: 20px; font-weight: bold; color: #2d3748; padding: 10px 0;"));
        titleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        formFrame = new QFrame(AddStudentDialog);
        formFrame->setObjectName("formFrame");
        formLayout = new QFormLayout(formFrame);
        formLayout->setObjectName("formLayout");
        stuNoLabel = new QLabel(formFrame);
        stuNoLabel->setObjectName("stuNoLabel");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, stuNoLabel);

        stuNoEdit = new QLineEdit(formFrame);
        stuNoEdit->setObjectName("stuNoEdit");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, stuNoEdit);

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

        collegeLabel = new QLabel(formFrame);
        collegeLabel->setObjectName("collegeLabel");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, collegeLabel);

        collegeCombo = new QComboBox(formFrame);
        collegeCombo->setObjectName("collegeCombo");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, collegeCombo);

        majorLabel = new QLabel(formFrame);
        majorLabel->setObjectName("majorLabel");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, majorLabel);

        majorCombo = new QComboBox(formFrame);
        majorCombo->setObjectName("majorCombo");

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, majorCombo);

        classLabel = new QLabel(formFrame);
        classLabel->setObjectName("classLabel");

        formLayout->setWidget(5, QFormLayout::ItemRole::LabelRole, classLabel);

        classCombo = new QComboBox(formFrame);
        classCombo->setObjectName("classCombo");

        formLayout->setWidget(5, QFormLayout::ItemRole::FieldRole, classCombo);

        gradeLabel = new QLabel(formFrame);
        gradeLabel->setObjectName("gradeLabel");

        formLayout->setWidget(6, QFormLayout::ItemRole::LabelRole, gradeLabel);

        gradeEdit = new QLineEdit(formFrame);
        gradeEdit->setObjectName("gradeEdit");

        formLayout->setWidget(6, QFormLayout::ItemRole::FieldRole, gradeEdit);

        phoneLabel = new QLabel(formFrame);
        phoneLabel->setObjectName("phoneLabel");

        formLayout->setWidget(7, QFormLayout::ItemRole::LabelRole, phoneLabel);

        phoneEdit = new QLineEdit(formFrame);
        phoneEdit->setObjectName("phoneEdit");

        formLayout->setWidget(7, QFormLayout::ItemRole::FieldRole, phoneEdit);

        emailLabel = new QLabel(formFrame);
        emailLabel->setObjectName("emailLabel");

        formLayout->setWidget(8, QFormLayout::ItemRole::LabelRole, emailLabel);

        emailEdit = new QLineEdit(formFrame);
        emailEdit->setObjectName("emailEdit");

        formLayout->setWidget(8, QFormLayout::ItemRole::FieldRole, emailEdit);


        verticalLayout->addWidget(formFrame);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(AddStudentDialog);
        okBtn->setObjectName("okBtn");

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(AddStudentDialog);
        cancelBtn->setObjectName("cancelBtn");

        horizontalLayout->addWidget(cancelBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(AddStudentDialog);
        QObject::connect(okBtn, &QPushButton::clicked, AddStudentDialog, qOverload<>(&QDialog::accept));
        QObject::connect(cancelBtn, &QPushButton::clicked, AddStudentDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddStudentDialog);
    } // setupUi

    void retranslateUi(QDialog *AddStudentDialog)
    {
        AddStudentDialog->setWindowTitle(QCoreApplication::translate("AddStudentDialog", "\346\267\273\345\212\240\345\255\246\347\224\237", nullptr));
        titleLabel->setText(QCoreApplication::translate("AddStudentDialog", "\346\267\273\345\212\240\346\226\260\345\255\246\347\224\237", nullptr));
        stuNoLabel->setText(QCoreApplication::translate("AddStudentDialog", "\345\255\246\345\217\267 *", nullptr));
        stuNoEdit->setPlaceholderText(QCoreApplication::translate("AddStudentDialog", "\350\257\267\350\276\223\345\205\245\345\255\246\345\217\267", nullptr));
        nameLabel->setText(QCoreApplication::translate("AddStudentDialog", "\345\247\223\345\220\215 *", nullptr));
        nameEdit->setPlaceholderText(QCoreApplication::translate("AddStudentDialog", "\350\257\267\350\276\223\345\205\245\345\247\223\345\220\215", nullptr));
        genderLabel->setText(QCoreApplication::translate("AddStudentDialog", "\346\200\247\345\210\253 *", nullptr));
        genderCombo->setItemText(0, QCoreApplication::translate("AddStudentDialog", "\347\224\267", nullptr));
        genderCombo->setItemText(1, QCoreApplication::translate("AddStudentDialog", "\345\245\263", nullptr));

        collegeLabel->setText(QCoreApplication::translate("AddStudentDialog", "\345\255\246\351\231\242 *", nullptr));
        majorLabel->setText(QCoreApplication::translate("AddStudentDialog", "\344\270\223\344\270\232 *", nullptr));
        classLabel->setText(QCoreApplication::translate("AddStudentDialog", "\347\217\255\347\272\247 *", nullptr));
        gradeLabel->setText(QCoreApplication::translate("AddStudentDialog", "\345\271\264\347\272\247", nullptr));
        gradeEdit->setPlaceholderText(QCoreApplication::translate("AddStudentDialog", "\345\246\202\357\274\2322023\347\272\247", nullptr));
        phoneLabel->setText(QCoreApplication::translate("AddStudentDialog", "\346\211\213\346\234\272\345\217\267", nullptr));
        phoneEdit->setPlaceholderText(QCoreApplication::translate("AddStudentDialog", "\350\257\267\350\276\223\345\205\245\346\211\213\346\234\272\345\217\267", nullptr));
        emailLabel->setText(QCoreApplication::translate("AddStudentDialog", "\351\202\256\347\256\261", nullptr));
        emailEdit->setPlaceholderText(QCoreApplication::translate("AddStudentDialog", "\350\257\267\350\276\223\345\205\245\351\202\256\347\256\261\357\274\210\345\217\257\351\200\211\357\274\211", nullptr));
        okBtn->setText(QCoreApplication::translate("AddStudentDialog", "\347\241\256\345\256\232\346\267\273\345\212\240", nullptr));
        cancelBtn->setText(QCoreApplication::translate("AddStudentDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddStudentDialog: public Ui_AddStudentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSTUDENTDIALOG_H
