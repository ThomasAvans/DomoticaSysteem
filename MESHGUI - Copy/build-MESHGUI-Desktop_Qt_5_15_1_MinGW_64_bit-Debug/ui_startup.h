/********************************************************************************
** Form generated from reading UI file 'startup.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTUP_H
#define UI_STARTUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Startup
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QDialog *Startup)
    {
        if (Startup->objectName().isEmpty())
            Startup->setObjectName(QString::fromUtf8("Startup"));
        Startup->resize(400, 300);
        buttonBox = new QDialogButtonBox(Startup);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 160, 341, 21));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);
        label = new QLabel(Startup);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 60, 291, 31));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        lineEdit = new QLineEdit(Startup);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(60, 90, 141, 20));
        lineEdit->setCursor(QCursor(Qt::CrossCursor));
        lineEdit->setInputMethodHints(Qt::ImhNone);

        retranslateUi(Startup);
        QObject::connect(buttonBox, SIGNAL(accepted()), Startup, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Startup, SLOT(reject()));

        QMetaObject::connectSlotsByName(Startup);
    } // setupUi

    void retranslateUi(QDialog *Startup)
    {
        Startup->setWindowTitle(QCoreApplication::translate("Startup", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Startup", "Please enter the COM port of your border router:", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("Startup", "Example: COMx", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Startup: public Ui_Startup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTUP_H
