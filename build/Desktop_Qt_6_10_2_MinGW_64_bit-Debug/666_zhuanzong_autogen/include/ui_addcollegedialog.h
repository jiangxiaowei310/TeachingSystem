/********************************************************************************
** Form generated from reading UI file 'addcollegedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCOLLEGEDIALOG_H
#define UI_ADDCOLLEGEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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

class Ui_AddCollegeDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QFrame *frame;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *collegeNameEdit;
    QLabel *label_2;
    QLineEdit *collegeCodeEdit;
    QLabel *label_3;
    QLineEdit *deanEdit;
    QLabel *label_4;
    QLineEdit *phoneEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;

    void setupUi(QDialog *AddCollegeDialog)
    {
        if (AddCollegeDialog->objectName().isEmpty())
            AddCollegeDialog->setObjectName("AddCollegeDialog");
        AddCollegeDialog->resize(400, 320);
        AddCollegeDialog->setStyleSheet(QString::fromUtf8("QWidget {\n"
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
""));
        verticalLayout = new QVBoxLayout(AddCollegeDialog);
        verticalLayout->setObjectName("verticalLayout");
        titleLabel = new QLabel(AddCollegeDialog);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setStyleSheet(QString::fromUtf8("font-size: 18px; font-weight: bold; color: #2d3748;"));

        verticalLayout->addWidget(titleLabel);

        frame = new QFrame(AddCollegeDialog);
        frame->setObjectName("frame");
        formLayout = new QFormLayout(frame);
        formLayout->setObjectName("formLayout");
        label = new QLabel(frame);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label);

        collegeNameEdit = new QLineEdit(frame);
        collegeNameEdit->setObjectName("collegeNameEdit");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, collegeNameEdit);

        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_2);

        collegeCodeEdit = new QLineEdit(frame);
        collegeCodeEdit->setObjectName("collegeCodeEdit");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, collegeCodeEdit);

        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_3);

        deanEdit = new QLineEdit(frame);
        deanEdit->setObjectName("deanEdit");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, deanEdit);

        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label_4);

        phoneEdit = new QLineEdit(frame);
        phoneEdit->setObjectName("phoneEdit");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, phoneEdit);


        verticalLayout->addWidget(frame);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(AddCollegeDialog);
        okBtn->setObjectName("okBtn");
        okBtn->setStyleSheet(QString::fromUtf8("background: #48bb78; color: white;"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(AddCollegeDialog);
        cancelBtn->setObjectName("cancelBtn");
        cancelBtn->setStyleSheet(QString::fromUtf8("background: #e2e8f0; color: #4a5568;"));

        horizontalLayout->addWidget(cancelBtn);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(AddCollegeDialog);
        QObject::connect(okBtn, &QPushButton::clicked, AddCollegeDialog, qOverload<>(&QDialog::accept));
        QObject::connect(cancelBtn, &QPushButton::clicked, AddCollegeDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddCollegeDialog);
    } // setupUi

    void retranslateUi(QDialog *AddCollegeDialog)
    {
        titleLabel->setText(QCoreApplication::translate("AddCollegeDialog", "\345\255\246\351\231\242\344\277\241\346\201\257", nullptr));
        label->setText(QCoreApplication::translate("AddCollegeDialog", "\345\255\246\351\231\242\345\220\215\347\247\260\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("AddCollegeDialog", "\345\255\246\351\231\242\344\273\243\347\240\201\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("AddCollegeDialog", "\351\231\242\351\225\277\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("AddCollegeDialog", "\350\201\224\347\263\273\347\224\265\350\257\235\357\274\232", nullptr));
        okBtn->setText(QCoreApplication::translate("AddCollegeDialog", "\347\241\256\345\256\232", nullptr));
        cancelBtn->setText(QCoreApplication::translate("AddCollegeDialog", "\345\217\226\346\266\210", nullptr));
        (void)AddCollegeDialog;
    } // retranslateUi

};

namespace Ui {
    class AddCollegeDialog: public Ui_AddCollegeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCOLLEGEDIALOG_H
