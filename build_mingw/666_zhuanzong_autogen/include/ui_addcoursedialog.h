/********************************************************************************
** Form generated from reading UI file 'addcoursedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCOURSEDIALOG_H
#define UI_ADDCOURSEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddCourseDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *courseNameEdit;
    QLabel *label_2;
    QLineEdit *courseCodeEdit;
    QLabel *label_3;
    QLineEdit *creditEdit;
    QLabel *label_4;
    QLineEdit *classHourEdit;
    QLabel *label_5;
    QTextEdit *descriptionEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;

    void setupUi(QDialog *AddCourseDialog)
    {
        if (AddCourseDialog->objectName().isEmpty())
            AddCourseDialog->setObjectName("AddCourseDialog");
        AddCourseDialog->resize(400, 350);
        verticalLayout = new QVBoxLayout(AddCourseDialog);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(AddCourseDialog);
        groupBox->setObjectName("groupBox");
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName("formLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label);

        courseNameEdit = new QLineEdit(groupBox);
        courseNameEdit->setObjectName("courseNameEdit");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, courseNameEdit);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_2);

        courseCodeEdit = new QLineEdit(groupBox);
        courseCodeEdit->setObjectName("courseCodeEdit");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, courseCodeEdit);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_3);

        creditEdit = new QLineEdit(groupBox);
        creditEdit->setObjectName("creditEdit");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, creditEdit);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label_4);

        classHourEdit = new QLineEdit(groupBox);
        classHourEdit->setObjectName("classHourEdit");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, classHourEdit);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, label_5);

        descriptionEdit = new QTextEdit(groupBox);
        descriptionEdit->setObjectName("descriptionEdit");
        descriptionEdit->setMaximumHeight(80);

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, descriptionEdit);


        verticalLayout->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(AddCourseDialog);
        okBtn->setObjectName("okBtn");

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(AddCourseDialog);
        cancelBtn->setObjectName("cancelBtn");

        horizontalLayout->addWidget(cancelBtn);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(AddCourseDialog);
        QObject::connect(okBtn, &QPushButton::clicked, AddCourseDialog, qOverload<>(&QDialog::accept));
        QObject::connect(cancelBtn, &QPushButton::clicked, AddCourseDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddCourseDialog);
    } // setupUi

    void retranslateUi(QDialog *AddCourseDialog)
    {
        AddCourseDialog->setWindowTitle(QCoreApplication::translate("AddCourseDialog", "\346\267\273\345\212\240\350\257\276\347\250\213", nullptr));
        groupBox->setTitle(QCoreApplication::translate("AddCourseDialog", "\350\257\276\347\250\213\344\277\241\346\201\257", nullptr));
        label->setText(QCoreApplication::translate("AddCourseDialog", "\350\257\276\347\250\213\345\220\215\347\247\260\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("AddCourseDialog", "\350\257\276\347\250\213\347\274\226\345\217\267\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("AddCourseDialog", "\345\255\246\345\210\206\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("AddCourseDialog", "\350\257\276\346\227\266\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("AddCourseDialog", "\350\257\276\347\250\213\346\217\217\350\277\260\357\274\232", nullptr));
        okBtn->setText(QCoreApplication::translate("AddCourseDialog", "\347\241\256\345\256\232", nullptr));
        cancelBtn->setText(QCoreApplication::translate("AddCourseDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddCourseDialog: public Ui_AddCourseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCOURSEDIALOG_H
