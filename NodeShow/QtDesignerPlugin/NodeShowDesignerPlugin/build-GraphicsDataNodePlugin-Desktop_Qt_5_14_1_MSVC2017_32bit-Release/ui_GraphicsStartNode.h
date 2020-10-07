/********************************************************************************
** Form generated from reading UI file 'GraphicsStartNode.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHICSSTARTNODE_H
#define UI_GRAPHICSSTARTNODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraphicsStartNode
{
public:
    QPushButton *outputPort;

    void setupUi(QWidget *GraphicsStartNode)
    {
        if (GraphicsStartNode->objectName().isEmpty())
            GraphicsStartNode->setObjectName(QString::fromUtf8("GraphicsStartNode"));
        GraphicsStartNode->resize(64, 65);
        GraphicsStartNode->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        outputPort = new QPushButton(GraphicsStartNode);
        outputPort->setObjectName(QString::fromUtf8("outputPort"));
        outputPort->setGeometry(QRect(0, 0, 71, 71));
        outputPort->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-image:url(:/img/img/startNode.png);\n"
"	\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"QPushButton:hover{\n"
"	background-image:url(:/img/img/startNode-hover.png);\n"
"	\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"QPushButton:pressed{\n"
"	\n"
"	background-image:url(:/img/img/startNode-press.png);\n"
"	\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}"));

        retranslateUi(GraphicsStartNode);

        QMetaObject::connectSlotsByName(GraphicsStartNode);
    } // setupUi

    void retranslateUi(QWidget *GraphicsStartNode)
    {
        GraphicsStartNode->setWindowTitle(QCoreApplication::translate("GraphicsStartNode", "Form", nullptr));
        outputPort->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GraphicsStartNode: public Ui_GraphicsStartNode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHICSSTARTNODE_H
