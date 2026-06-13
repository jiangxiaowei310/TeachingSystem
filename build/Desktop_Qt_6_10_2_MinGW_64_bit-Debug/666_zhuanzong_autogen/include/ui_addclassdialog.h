/********************************************************************************
** Form generated from reading UI file 'addclassdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCLASSDIALOG_H
#define UI_ADDCLASSDIALOG_H

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

class Ui_AddClassDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QFrame *frame;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *classNameEdit;
    QLabel *label_2;
    QLineEdit *classCodeEdit;
    QLabel *label_3;
    QLineEdit *gradeEdit;
    QLabel *label_4;
    QComboBox *collegeCombo;
    QLabel *label_5;
    QComboBox *majorCombo;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;

    void setupUi(QDialog *AddClassDialog)
    {
        if (AddClassDialog->objectName().isEmpty())
            AddClassDialog->setObjectName("AddClassDialog");
        AddClassDialog->resize(400, 320);
        AddClassDialog->setStyleSheet(QString::fromUtf8("QWidget {\n"
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
        verticalLayout = new QVBoxLayout(AddClassDialog);
        verticalLayout->setObjectName("verticalLayout");
        titleLabel = new QLabel(AddClassDialog);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setStyleSheet(QString::fromUtf8("font-size: 18px; font-weight: bold; color: #2d3748;"));

        verticalLayout->addWidget(titleLabel);

        frame = new QFrame(AddClassDialog);
        frame->setObjectName("frame");
        formLayout = new QFormLayout(frame);
        formLayout->setObjectName("formLayout");
        label = new QLabel(frame);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label);

        classNameEdit = new QLineEdit(frame);
        classNameEdit->setObjectName("classNameEdit");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, classNameEdit);

        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_2);

        classCodeEdit = new QLineEdit(frame);
        classCodeEdit->setObjectName("classCodeEdit");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, classCodeEdit);

        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_3);

        gradeEdit = new QLineEdit(frame);
        gradeEdit->setObjectName("gradeEdit");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, gradeEdit);

        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label_4);

        collegeCombo = new QComboBox(frame);
        collegeCombo->setObjectName("collegeCombo");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, collegeCombo);

        label_5 = new QLabel(frame);
        label_5->setObjectName("label_5");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, label_5);

        majorCombo = new QComboBox(frame);
        majorCombo->setObjectName("majorCombo");

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, majorCombo);


        verticalLayout->addWidget(frame);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(AddClassDialog);
        okBtn->setObjectName("okBtn");
        okBtn->setStyleSheet(QString::fromUtf8("background: #48bb78; color: white;"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(AddClassDialog);
        cancelBtn->setObjectName("cancelBtn");
        cancelBtn->setStyleSheet(QString::fromUtf8("background: #e2e8f0; color: #4a5568;"));

        horizontalLayout->addWidget(cancelBtn);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(AddClassDialog);
        QObject::connect(okBtn, &QPushButton::clicked, AddClassDialog, qOverload<>(&QDialog::accept));
        QObject::connect(cancelBtn, &QPushButton::clicked, AddClassDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddClassDialog);
    } // setupUi

    void retranslateUi(QDialog *AddClassDialog)
    {
        titleLabel->setText(QCoreApplication::translate("AddClassDialog", "\347\217\255\347\272\247\344\277\241\346\201\257", nullptr));
        label->setText(QCoreApplication::translate("AddClassDialog", "\347\217\255\347\272\247\345\220\215\347\247\260\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("AddClassDialog", "\347\217\255\347\272\247\344\273\243\347\240\201\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("AddClassDialog", "\345\271\264\347\272\247\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("AddClassDialog", "\346\211\200\345\261\236\345\255\246\351\231\242\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("AddClassDialog", "\346\211\200\345\261\236\344\270\223\344\270\232\357\274\232", nullptr));
        okBtn->setText(QCoreApplication::translate("AddClassDialog", "\347\241\256\345\256\232", nullptr));
        cancelBtn->setText(QCoreApplication::translate("AddClassDialog", "\345\217\226\346\266\210", nullptr));
        (void)AddClassDialog;
    } // retranslateUi

};

namespace Ui {
    class AddClassDialog: public Ui_AddClassDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCLASSDIALOG_H
