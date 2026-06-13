/********************************************************************************
** Form generated from reading UI file 'batchimportdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BATCHIMPORTDIALOG_H
#define UI_BATCHIMPORTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BatchImportDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *fileEdit;
    QPushButton *browseBtn;
    QLabel *tipLabel;
    QLabel *tipLabel2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;

    void setupUi(QDialog *BatchImportDialog)
    {
        if (BatchImportDialog->objectName().isEmpty())
            BatchImportDialog->setObjectName("BatchImportDialog");
        BatchImportDialog->resize(500, 220);
        BatchImportDialog->setStyleSheet(QString::fromUtf8("QWidget {\n"
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
        verticalLayout = new QVBoxLayout(BatchImportDialog);
        verticalLayout->setObjectName("verticalLayout");
        titleLabel = new QLabel(BatchImportDialog);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setStyleSheet(QString::fromUtf8("font-size: 18px; font-weight: bold; color: #2d3748;"));

        verticalLayout->addWidget(titleLabel);

        frame = new QFrame(BatchImportDialog);
        frame->setObjectName("frame");
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        fileEdit = new QLineEdit(frame);
        fileEdit->setObjectName("fileEdit");
        fileEdit->setReadOnly(true);

        horizontalLayout_2->addWidget(fileEdit);

        browseBtn = new QPushButton(frame);
        browseBtn->setObjectName("browseBtn");
        browseBtn->setStyleSheet(QString::fromUtf8("background: #4299e1; color: white;"));

        horizontalLayout_2->addWidget(browseBtn);


        verticalLayout_2->addLayout(horizontalLayout_2);

        tipLabel = new QLabel(frame);
        tipLabel->setObjectName("tipLabel");
        tipLabel->setStyleSheet(QString::fromUtf8("color: #718096; font-size: 12px;"));

        verticalLayout_2->addWidget(tipLabel);

        tipLabel2 = new QLabel(frame);
        tipLabel2->setObjectName("tipLabel2");
        tipLabel2->setStyleSheet(QString::fromUtf8("color: #ed8936; font-size: 12px;"));

        verticalLayout_2->addWidget(tipLabel2);


        verticalLayout->addWidget(frame);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        okBtn = new QPushButton(BatchImportDialog);
        okBtn->setObjectName("okBtn");
        okBtn->setStyleSheet(QString::fromUtf8("background: #48bb78; color: white;"));

        horizontalLayout_3->addWidget(okBtn);

        cancelBtn = new QPushButton(BatchImportDialog);
        cancelBtn->setObjectName("cancelBtn");
        cancelBtn->setStyleSheet(QString::fromUtf8("background: #e2e8f0; color: #4a5568;"));

        horizontalLayout_3->addWidget(cancelBtn);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(BatchImportDialog);

        QMetaObject::connectSlotsByName(BatchImportDialog);
    } // setupUi

    void retranslateUi(QDialog *BatchImportDialog)
    {
        titleLabel->setText(QCoreApplication::translate("BatchImportDialog", "\346\211\271\351\207\217\345\257\274\345\205\245\345\255\246\347\224\237", nullptr));
        label_2->setText(QCoreApplication::translate("BatchImportDialog", "\351\200\211\346\213\251CSV\346\226\207\344\273\266\357\274\232", nullptr));
        browseBtn->setText(QCoreApplication::translate("BatchImportDialog", "\346\265\217\350\247\210...", nullptr));
        tipLabel->setText(QCoreApplication::translate("BatchImportDialog", "\346\217\220\347\244\272\357\274\232\346\226\207\344\273\266\351\234\200\345\214\205\345\220\253\344\273\245\344\270\213\345\210\227\357\274\210\351\241\272\345\272\217\344\270\215\351\231\220\357\274\211\357\274\232\345\255\246\345\217\267\343\200\201\345\247\223\345\220\215\343\200\201\346\200\247\345\210\253\343\200\201\345\255\246\351\231\242\343\200\201\344\270\223\344\270\232\343\200\201\347\217\255\347\272\247\343\200\201\345\271\264\347\272\247\343\200\201\347\224\265\350\257\235\343\200\201\351\202\256\347\256\261", nullptr));
        tipLabel2->setText(QCoreApplication::translate("BatchImportDialog", "\345\246\202\346\236\234\344\275\277\347\224\250Excel\357\274\214\350\257\267\345\205\210\345\217\246\345\255\230\344\270\272CSV\346\240\274\345\274\217\345\206\215\345\257\274\345\205\245", nullptr));
        okBtn->setText(QCoreApplication::translate("BatchImportDialog", "\345\274\200\345\247\213\345\257\274\345\205\245", nullptr));
        cancelBtn->setText(QCoreApplication::translate("BatchImportDialog", "\345\217\226\346\266\210", nullptr));
        (void)BatchImportDialog;
    } // retranslateUi

};

namespace Ui {
    class BatchImportDialog: public Ui_BatchImportDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BATCHIMPORTDIALOG_H
