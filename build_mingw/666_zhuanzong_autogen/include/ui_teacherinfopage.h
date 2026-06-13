/********************************************************************************
** Form generated from reading UI file 'teacherinfopage.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHERINFOPAGE_H
#define UI_TEACHERINFOPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TeacherInfoPage
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *headerFrame;
    QHBoxLayout *horizontalLayout;
    QLabel *titleLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *editBtn;
    QPushButton *saveBtn;
    QFrame *infoFrame;
    QFormLayout *formLayout;
    QLabel *label_1;
    QLineEdit *idEdit;
    QLabel *label_2;
    QLineEdit *nameEdit;
    QLabel *label_3;
    QLineEdit *genderEdit;
    QLabel *label_4;
    QLineEdit *titleEdit;
    QLabel *label_5;
    QLineEdit *collegeEdit;
    QLabel *label_6;
    QLineEdit *phoneEdit;
    QLabel *label_7;
    QLineEdit *emailEdit;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *TeacherInfoPage)
    {
        if (TeacherInfoPage->objectName().isEmpty())
            TeacherInfoPage->setObjectName("TeacherInfoPage");
        TeacherInfoPage->resize(1000, 650);
        TeacherInfoPage->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background: #f7fafc;\n"
"}\n"
"QFrame {\n"
"    background: white;\n"
"    border-radius: 8px;\n"
"    border: 1px solid #e2e8f0;\n"
"}\n"
"QLabel {\n"
"    color: #4a5568;\n"
"}\n"
"QLineEdit {\n"
"    border: 1px solid #e2e8f0;\n"
"    border-radius: 6px;\n"
"    padding: 8px 12px;\n"
"    font-size: 13px;\n"
"}\n"
"QPushButton {\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 16px;\n"
"    font-size: 13px;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(TeacherInfoPage);
        verticalLayout->setObjectName("verticalLayout");
        headerFrame = new QFrame(TeacherInfoPage);
        headerFrame->setObjectName("headerFrame");
        horizontalLayout = new QHBoxLayout(headerFrame);
        horizontalLayout->setObjectName("horizontalLayout");
        titleLabel = new QLabel(headerFrame);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setStyleSheet(QString::fromUtf8("font-size: 20px; font-weight: bold; color: #2d3748;"));

        horizontalLayout->addWidget(titleLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        editBtn = new QPushButton(headerFrame);
        editBtn->setObjectName("editBtn");
        editBtn->setStyleSheet(QString::fromUtf8("background: #4299e1; color: white;"));

        horizontalLayout->addWidget(editBtn);

        saveBtn = new QPushButton(headerFrame);
        saveBtn->setObjectName("saveBtn");
        saveBtn->setStyleSheet(QString::fromUtf8("background: #48bb78; color: white;"));

        horizontalLayout->addWidget(saveBtn);


        verticalLayout->addWidget(headerFrame);

        infoFrame = new QFrame(TeacherInfoPage);
        infoFrame->setObjectName("infoFrame");
        formLayout = new QFormLayout(infoFrame);
        formLayout->setObjectName("formLayout");
        label_1 = new QLabel(infoFrame);
        label_1->setObjectName("label_1");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label_1);

        idEdit = new QLineEdit(infoFrame);
        idEdit->setObjectName("idEdit");
        idEdit->setEnabled(false);

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, idEdit);

        label_2 = new QLabel(infoFrame);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_2);

        nameEdit = new QLineEdit(infoFrame);
        nameEdit->setObjectName("nameEdit");
        nameEdit->setEnabled(false);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, nameEdit);

        label_3 = new QLabel(infoFrame);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_3);

        genderEdit = new QLineEdit(infoFrame);
        genderEdit->setObjectName("genderEdit");
        genderEdit->setEnabled(false);

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, genderEdit);

        label_4 = new QLabel(infoFrame);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label_4);

        titleEdit = new QLineEdit(infoFrame);
        titleEdit->setObjectName("titleEdit");
        titleEdit->setEnabled(false);

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, titleEdit);

        label_5 = new QLabel(infoFrame);
        label_5->setObjectName("label_5");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, label_5);

        collegeEdit = new QLineEdit(infoFrame);
        collegeEdit->setObjectName("collegeEdit");
        collegeEdit->setEnabled(false);

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, collegeEdit);

        label_6 = new QLabel(infoFrame);
        label_6->setObjectName("label_6");

        formLayout->setWidget(5, QFormLayout::ItemRole::LabelRole, label_6);

        phoneEdit = new QLineEdit(infoFrame);
        phoneEdit->setObjectName("phoneEdit");
        phoneEdit->setEnabled(false);

        formLayout->setWidget(5, QFormLayout::ItemRole::FieldRole, phoneEdit);

        label_7 = new QLabel(infoFrame);
        label_7->setObjectName("label_7");

        formLayout->setWidget(6, QFormLayout::ItemRole::LabelRole, label_7);

        emailEdit = new QLineEdit(infoFrame);
        emailEdit->setObjectName("emailEdit");
        emailEdit->setEnabled(false);

        formLayout->setWidget(6, QFormLayout::ItemRole::FieldRole, emailEdit);


        verticalLayout->addWidget(infoFrame);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(TeacherInfoPage);

        QMetaObject::connectSlotsByName(TeacherInfoPage);
    } // setupUi

    void retranslateUi(QWidget *TeacherInfoPage)
    {
        titleLabel->setText(QCoreApplication::translate("TeacherInfoPage", "\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        editBtn->setText(QCoreApplication::translate("TeacherInfoPage", "\347\274\226\350\276\221", nullptr));
        saveBtn->setText(QCoreApplication::translate("TeacherInfoPage", "\344\277\235\345\255\230", nullptr));
        label_1->setText(QCoreApplication::translate("TeacherInfoPage", "\345\267\245\345\217\267\357\274\232", nullptr));
        idEdit->setText(QCoreApplication::translate("TeacherInfoPage", "T2023001", nullptr));
        label_2->setText(QCoreApplication::translate("TeacherInfoPage", "\345\247\223\345\220\215\357\274\232", nullptr));
        nameEdit->setText(QCoreApplication::translate("TeacherInfoPage", "\345\274\240\350\200\201\345\270\210", nullptr));
        label_3->setText(QCoreApplication::translate("TeacherInfoPage", "\346\200\247\345\210\253\357\274\232", nullptr));
        genderEdit->setText(QCoreApplication::translate("TeacherInfoPage", "\347\224\267", nullptr));
        label_4->setText(QCoreApplication::translate("TeacherInfoPage", "\350\201\214\347\247\260\357\274\232", nullptr));
        titleEdit->setText(QCoreApplication::translate("TeacherInfoPage", "\345\211\257\346\225\231\346\216\210", nullptr));
        label_5->setText(QCoreApplication::translate("TeacherInfoPage", "\346\211\200\345\261\236\345\255\246\351\231\242\357\274\232", nullptr));
        collegeEdit->setText(QCoreApplication::translate("TeacherInfoPage", "\350\256\241\347\256\227\346\234\272\345\255\246\351\231\242", nullptr));
        label_6->setText(QCoreApplication::translate("TeacherInfoPage", "\350\201\224\347\263\273\347\224\265\350\257\235\357\274\232", nullptr));
        phoneEdit->setText(QCoreApplication::translate("TeacherInfoPage", "13800138000", nullptr));
        label_7->setText(QCoreApplication::translate("TeacherInfoPage", "\351\202\256\347\256\261\357\274\232", nullptr));
        emailEdit->setText(QCoreApplication::translate("TeacherInfoPage", "teacher@example.com", nullptr));
        (void)TeacherInfoPage;
    } // retranslateUi

};

namespace Ui {
    class TeacherInfoPage: public Ui_TeacherInfoPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHERINFOPAGE_H
