/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QLabel *label;
    QLineEdit *usernameEdit;
    QLabel *label_2;
    QLineEdit *passwordEdit;
    QLabel *label_3;
    QComboBox *roleComboBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *loginBtn;
    QPushButton *exitBtn;

    void setupUi(QDialog *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(251, 241);
        LoginWindow->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #6a11cb, stop:1 #2575fc);\n"
"}\n"
"QFrame {\n"
"    background: white;\n"
"    border-radius: 10px;\n"
"}\n"
"QLabel {\n"
"    color: #333;\n"
"    font-size: 14px;\n"
"}\n"
"QLineEdit {\n"
"    border: 2px solid #e0e0e0;\n"
"    border-radius: 8px;\n"
"    padding: 8px 12px;\n"
"    font-size: 14px;\n"
"    background: #f8f9fa;\n"
"}\n"
"QLineEdit:focus {\n"
"    border-color: #6a11cb;\n"
"    background: white;\n"
"}\n"
"QPushButton {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #6a11cb, stop:1 #2575fc);\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 10px 30px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #7b2cbf, stop:1 #3498db);\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #5a10ba, stop:1 #1e6091);\n"
"}\n"
""));
        gridLayout = new QGridLayout(LoginWindow);
        gridLayout->setObjectName("gridLayout");
        frame = new QFrame(LoginWindow);
        frame->setObjectName("frame");
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName("verticalLayout");
        titleLabel = new QLabel(frame);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setStyleSheet(QString::fromUtf8("font-size: 20px; font-weight: bold; color: #6a11cb;"));
        titleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        label = new QLabel(frame);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        usernameEdit = new QLineEdit(frame);
        usernameEdit->setObjectName("usernameEdit");

        verticalLayout->addWidget(usernameEdit);

        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        passwordEdit = new QLineEdit(frame);
        passwordEdit->setObjectName("passwordEdit");

        verticalLayout->addWidget(passwordEdit);

        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        roleComboBox = new QComboBox(frame);
        roleComboBox->addItem(QString());
        roleComboBox->addItem(QString());
        roleComboBox->addItem(QString());
        roleComboBox->setObjectName("roleComboBox");
        roleComboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 2px solid #e0e0e0;\n"
"    border-radius: 8px;\n"
"    padding: 8px 12px;\n"
"    font-size: 14px;\n"
"    background: #f8f9fa;\n"
"}\n"
"QComboBox:focus {\n"
"    border-color: #6a11cb;\n"
"    background: white;\n"
"}\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"    padding-right: 10px;\n"
"}\n"
"QComboBox QAbstractItemView {\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 8px;\n"
"    background: white;\n"
"    selection-background-color: #6a11cb;\n"
"}"));

        verticalLayout->addWidget(roleComboBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        loginBtn = new QPushButton(frame);
        loginBtn->setObjectName("loginBtn");

        horizontalLayout->addWidget(loginBtn);

        exitBtn = new QPushButton(frame);
        exitBtn->setObjectName("exitBtn");

        horizontalLayout->addWidget(exitBtn);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QDialog *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "\345\255\246\347\224\237\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        titleLabel->setText(QCoreApplication::translate("LoginWindow", "\345\255\246\347\224\237\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        label->setText(QCoreApplication::translate("LoginWindow", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        usernameEdit->setPlaceholderText(QCoreApplication::translate("LoginWindow", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWindow", "\345\257\206\347\240\201\357\274\232", nullptr));
        passwordEdit->setPlaceholderText(QCoreApplication::translate("LoginWindow", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        label_3->setText(QCoreApplication::translate("LoginWindow", "\350\247\222\350\211\262\357\274\232", nullptr));
        roleComboBox->setItemText(0, QCoreApplication::translate("LoginWindow", "\347\256\241\347\220\206\345\221\230", nullptr));
        roleComboBox->setItemText(1, QCoreApplication::translate("LoginWindow", "\346\225\231\345\270\210", nullptr));
        roleComboBox->setItemText(2, QCoreApplication::translate("LoginWindow", "\345\255\246\347\224\237", nullptr));

        loginBtn->setText(QCoreApplication::translate("LoginWindow", "\347\231\273\345\275\225", nullptr));
        exitBtn->setText(QCoreApplication::translate("LoginWindow", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
