/********************************************************************************
** Form generated from reading UI file 'adduserdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDUSERDIALOG_H
#define UI_ADDUSERDIALOG_H

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

class Ui_AddUserDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QFrame *frame;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *usernameEdit;
    QLabel *label_2;
    QLineEdit *passwordEdit;
    QLabel *label_3;
    QComboBox *roleCombo;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;

    void setupUi(QDialog *AddUserDialog)
    {
        if (AddUserDialog->objectName().isEmpty())
            AddUserDialog->setObjectName("AddUserDialog");
        AddUserDialog->resize(400, 280);
        AddUserDialog->setStyleSheet(QString::fromUtf8("QWidget {\n"
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
"QLineEdit, QComboBox {\n"
"    border: 1px solid #e2e8f0;\n"
"    border-radius: 6px;\n"
"    padding: 8px 12px;\n"
"    font-size: 13px;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(AddUserDialog);
        verticalLayout->setObjectName("verticalLayout");
        titleLabel = new QLabel(AddUserDialog);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setStyleSheet(QString::fromUtf8("font-size: 18px; font-weight: bold; color: #2d3748;"));

        verticalLayout->addWidget(titleLabel);

        frame = new QFrame(AddUserDialog);
        frame->setObjectName("frame");
        formLayout = new QFormLayout(frame);
        formLayout->setObjectName("formLayout");
        label = new QLabel(frame);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label);

        usernameEdit = new QLineEdit(frame);
        usernameEdit->setObjectName("usernameEdit");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, usernameEdit);

        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_2);

        passwordEdit = new QLineEdit(frame);
        passwordEdit->setObjectName("passwordEdit");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, passwordEdit);

        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_3);

        roleCombo = new QComboBox(frame);
        roleCombo->setObjectName("roleCombo");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, roleCombo);


        verticalLayout->addWidget(frame);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(AddUserDialog);
        okBtn->setObjectName("okBtn");
        okBtn->setStyleSheet(QString::fromUtf8("background: #48bb78; color: white;"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(AddUserDialog);
        cancelBtn->setObjectName("cancelBtn");
        cancelBtn->setStyleSheet(QString::fromUtf8("background: #e2e8f0; color: #4a5568;"));

        horizontalLayout->addWidget(cancelBtn);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(AddUserDialog);
        QObject::connect(okBtn, &QPushButton::clicked, AddUserDialog, qOverload<>(&QDialog::accept));
        QObject::connect(cancelBtn, &QPushButton::clicked, AddUserDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddUserDialog);
    } // setupUi

    void retranslateUi(QDialog *AddUserDialog)
    {
        titleLabel->setText(QCoreApplication::translate("AddUserDialog", "\347\224\250\346\210\267\344\277\241\346\201\257", nullptr));
        label->setText(QCoreApplication::translate("AddUserDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("AddUserDialog", "\345\257\206\347\240\201\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("AddUserDialog", "\350\247\222\350\211\262\357\274\232", nullptr));
        okBtn->setText(QCoreApplication::translate("AddUserDialog", "\347\241\256\345\256\232", nullptr));
        cancelBtn->setText(QCoreApplication::translate("AddUserDialog", "\345\217\226\346\266\210", nullptr));
        (void)AddUserDialog;
    } // retranslateUi

};

namespace Ui {
    class AddUserDialog: public Ui_AddUserDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDUSERDIALOG_H
