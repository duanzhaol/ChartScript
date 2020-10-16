/********************************************************************************
** Form generated from reading UI file 'GraphicsDataNode.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHICSDATANODE_H
#define UI_GRAPHICSDATANODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>
#include "port.h"

QT_BEGIN_NAMESPACE

class Ui_GraphicsDataNode
{
public:
    QComboBox *comboBox;
    QLabel *nodeBackground;
    QLineEdit *dataNodeData;
    QLineEdit *dataNodeName;
    QLabel *label;
    QLabel *label_2;
    Port *inputPort;
    Port *outputPort;

    void setupUi(QWidget *GraphicsDataNode)
    {
        if (GraphicsDataNode->objectName().isEmpty())
            GraphicsDataNode->setObjectName(QString::fromUtf8("GraphicsDataNode"));
        GraphicsDataNode->resize(352, 206);
        GraphicsDataNode->setMinimumSize(QSize(0, 0));
        GraphicsDataNode->setStyleSheet(QString::fromUtf8("\n"
"\n"
"background: rgba(255, 255, 255, 0);\n"
"    color: #BBBBBB;\n"
"    font-family: \"Segoe UI\";\n"
"\n"
""));
        comboBox = new QComboBox(GraphicsDataNode);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(70, 50, 91, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(9);
        comboBox->setFont(font);
        comboBox->setStyleSheet(QString::fromUtf8("\n"
"QComboBox {border-radius:10px;background:rgb(97, 97, 97);color:#ffffff;\n"
"padding-left:15px;\n"
"}  \n"
"\n"
"QComboBox QAbstractItemView {background:rgb(189, 189, 189);color:#ffffff;} \n"
" \n"
"\n"
"QComboBox::drop-down{\n"
"width: 15px;\n"
"border-left: 1px solid #ffffff; \n"
"}    \n"
"\n"
"QComboBox::down-arrow {image: url(:/img/img/xia.png);height:30px;width:15px;}   \n"
"\n"
"QListView::item{padding-left:15px;background:rgb(152, 152, 152);color:#ffffff;}  \n"
"\n"
"QListView::item:selected{ \n"
"color:#DCDCDC;\n"
"background:rgb(94,167,255);\n"
"}   \n"
"\n"
"QListView::item:hover{ \n"
"color:#DCDCDC;\n"
"background:rgb(94,167,255);\n"
"}"));
        nodeBackground = new QLabel(GraphicsDataNode);
        nodeBackground->setObjectName(QString::fromUtf8("nodeBackground"));
        nodeBackground->setGeometry(QRect(0, 0, 231, 121));
        nodeBackground->setStyleSheet(QString::fromUtf8("\n"
"\n"
"background: #222222;\n"
"    color: #BBBBBB;\n"
"    font-family: \"Segoe UI\";\n"
"border-radius:50%;\n"
""));
        dataNodeData = new QLineEdit(GraphicsDataNode);
        dataNodeData->setObjectName(QString::fromUtf8("dataNodeData"));
        dataNodeData->setGeometry(QRect(40, 90, 151, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setWeight(50);
        dataNodeData->setFont(font1);
        dataNodeData->setStyleSheet(QString::fromUtf8("border:1px solid rgba(255, 255, 255, 0)"));
        dataNodeName = new QLineEdit(GraphicsDataNode);
        dataNodeName->setObjectName(QString::fromUtf8("dataNodeName"));
        dataNodeName->setGeometry(QRect(30, 10, 161, 31));
        dataNodeName->setFont(font1);
        dataNodeName->setStyleSheet(QString::fromUtf8("border:2px solid rgb(111, 111, 111);\n"
"border-radius:5px;"));
        label = new QLabel(GraphicsDataNode);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 50, 31, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(8);
        font2.setBold(false);
        font2.setWeight(50);
        label->setFont(font2);
        label_2 = new QLabel(GraphicsDataNode);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 50, 31, 21));
        label_2->setFont(font2);
        inputPort = new Port(GraphicsDataNode);
        inputPort->setObjectName(QString::fromUtf8("inputPort"));
        inputPort->setGeometry(QRect(0, 50, 16, 16));
        outputPort = new Port(GraphicsDataNode);
        outputPort->setObjectName(QString::fromUtf8("outputPort"));
        outputPort->setGeometry(QRect(210, 50, 16, 16));
        nodeBackground->raise();
        comboBox->raise();
        dataNodeData->raise();
        dataNodeName->raise();
        label->raise();
        label_2->raise();
        inputPort->raise();
        outputPort->raise();

        retranslateUi(GraphicsDataNode);

        QMetaObject::connectSlotsByName(GraphicsDataNode);
    } // setupUi

    void retranslateUi(QWidget *GraphicsDataNode)
    {
        GraphicsDataNode->setWindowTitle(QCoreApplication::translate("GraphicsDataNode", "Form", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("GraphicsDataNode", "long long", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("GraphicsDataNode", "String", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("GraphicsDataNode", "float", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("GraphicsDataNode", "double", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("GraphicsDataNode", "int", nullptr));

        nodeBackground->setText(QString());
        dataNodeData->setText(QCoreApplication::translate("GraphicsDataNode", "\350\265\267\351\243\236", nullptr));
        dataNodeName->setText(QCoreApplication::translate("GraphicsDataNode", " \346\225\260\346\215\256\350\212\202\347\202\271", nullptr));
        label->setText(QCoreApplication::translate("GraphicsDataNode", "out", nullptr));
        label_2->setText(QCoreApplication::translate("GraphicsDataNode", "in", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GraphicsDataNode: public Ui_GraphicsDataNode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHICSDATANODE_H
