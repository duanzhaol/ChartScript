/********************************************************************************
** Form generated from reading UI file 'Port.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PORT_H
#define UI_PORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Port
{
public:
    QPushButton *inputButton;

    void setupUi(QWidget *Port)
    {
        if (Port->objectName().isEmpty())
            Port->setObjectName(QString::fromUtf8("Port"));
        Port->resize(16, 16);
        inputButton = new QPushButton(Port);
        inputButton->setObjectName(QString::fromUtf8("inputButton"));
        inputButton->setGeometry(QRect(0, 0, 16, 16));
        inputButton->setMinimumSize(QSize(0, 0));
        inputButton->setMaximumSize(QSize(16777215, 16777215));
        inputButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"							 border: 1px solid #333333;\n"
"							 padding: 4px;\n"
"							 border-radius:8px;\n"
"\n"
"							 background-color: rgb(255, 255, 255);\n"
"						 }\n"
"\n"
"						 QPushButton:hover {\n"
"							 background-color: rgb(52, 167, 255);\n"
"							 border-color: #444444;\n"
"						 }\n"
"\n"
"						 QPushButton:pressed {\n"
"							 background-color: rgb(46, 39, 239);\n"
"							 border-color: #333333;\n"
"							 color: yellow;\n"
"						 }\n"
"\n"
"						 QPushButton:disabled {\n"
"							 color: #333333;\n"
"						 }"));

        retranslateUi(Port);

        QMetaObject::connectSlotsByName(Port);
    } // setupUi

    void retranslateUi(QWidget *Port)
    {
        Port->setWindowTitle(QCoreApplication::translate("Port", "Form", nullptr));
        inputButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Port: public Ui_Port {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PORT_H
