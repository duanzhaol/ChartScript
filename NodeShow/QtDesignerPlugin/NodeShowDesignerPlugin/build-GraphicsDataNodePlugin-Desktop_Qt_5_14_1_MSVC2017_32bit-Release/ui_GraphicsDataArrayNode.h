/********************************************************************************
** Form generated from reading UI file 'GraphicsDataArrayNode.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHICSDATAARRAYNODE_H
#define UI_GRAPHICSDATAARRAYNODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>
#include "port.h"

QT_BEGIN_NAMESPACE

class Ui_GraphicsDataArrayNode
{
public:
    QComboBox *comboBox;
    QLabel *label;
    Port *inputPort;
    QLabel *nodeBackground;
    QLineEdit *dataArrayNodeData;
    QLabel *label_2;
    Port *outputPort;
    QLineEdit *dataArrayNodeName;
    QLabel *label_3;

    void setupUi(QWidget *GraphicsDataArrayNode)
    {
        if (GraphicsDataArrayNode->objectName().isEmpty())
            GraphicsDataArrayNode->setObjectName(QString::fromUtf8("GraphicsDataArrayNode"));
        GraphicsDataArrayNode->resize(280, 121);
        GraphicsDataArrayNode->setStyleSheet(QString::fromUtf8("\n"
"\n"
"background: rgba(255, 255, 255, 0);\n"
"    color: #BBBBBB;\n"
"    font-family: \"Segoe UI\";"));
        comboBox = new QComboBox(GraphicsDataArrayNode);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(70, 50, 131, 31));
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
        label = new QLabel(GraphicsDataArrayNode);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 50, 31, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(8);
        font1.setBold(false);
        font1.setWeight(50);
        label->setFont(font1);
        inputPort = new Port(GraphicsDataArrayNode);
        inputPort->setObjectName(QString::fromUtf8("inputPort"));
        inputPort->setGeometry(QRect(0, 50, 16, 16));
        nodeBackground = new QLabel(GraphicsDataArrayNode);
        nodeBackground->setObjectName(QString::fromUtf8("nodeBackground"));
        nodeBackground->setGeometry(QRect(0, 0, 281, 121));
        nodeBackground->setStyleSheet(QString::fromUtf8("\n"
"\n"
"background: #222222;\n"
"    color: #BBBBBB;\n"
"    font-family: \"Segoe UI\";\n"
"border-radius:50%;\n"
""));
        dataArrayNodeData = new QLineEdit(GraphicsDataArrayNode);
        dataArrayNodeData->setObjectName(QString::fromUtf8("dataArrayNodeData"));
        dataArrayNodeData->setGeometry(QRect(40, 90, 201, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(9);
        font2.setBold(false);
        font2.setWeight(50);
        dataArrayNodeData->setFont(font2);
        dataArrayNodeData->setStyleSheet(QString::fromUtf8("border:1px solid rgba(255, 255, 255, 0)"));
        label_2 = new QLabel(GraphicsDataArrayNode);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 50, 31, 21));
        label_2->setFont(font1);
        outputPort = new Port(GraphicsDataArrayNode);
        outputPort->setObjectName(QString::fromUtf8("outputPort"));
        outputPort->setGeometry(QRect(260, 50, 16, 16));
        dataArrayNodeName = new QLineEdit(GraphicsDataArrayNode);
        dataArrayNodeName->setObjectName(QString::fromUtf8("dataArrayNodeName"));
        dataArrayNodeName->setGeometry(QRect(30, 10, 211, 31));
        dataArrayNodeName->setFont(font2);
        dataArrayNodeName->setStyleSheet(QString::fromUtf8("border:2px solid rgb(111, 111, 111);\n"
"border-radius:5px;"));
        label_3 = new QLabel(GraphicsDataArrayNode);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(140, 50, 51, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Segoe UI"));
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setWeight(50);
        label_3->setFont(font3);
        nodeBackground->raise();
        comboBox->raise();
        label->raise();
        inputPort->raise();
        dataArrayNodeData->raise();
        label_2->raise();
        outputPort->raise();
        dataArrayNodeName->raise();
        label_3->raise();

        retranslateUi(GraphicsDataArrayNode);

        QMetaObject::connectSlotsByName(GraphicsDataArrayNode);
    } // setupUi

    void retranslateUi(QWidget *GraphicsDataArrayNode)
    {
        GraphicsDataArrayNode->setWindowTitle(QCoreApplication::translate("GraphicsDataArrayNode", "Form", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("GraphicsDataArrayNode", "long long", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("GraphicsDataArrayNode", "String", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("GraphicsDataArrayNode", "float", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("GraphicsDataArrayNode", "double", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("GraphicsDataArrayNode", "int", nullptr));

        label->setText(QCoreApplication::translate("GraphicsDataArrayNode", "out", nullptr));
        nodeBackground->setText(QString());
        dataArrayNodeData->setText(QCoreApplication::translate("GraphicsDataArrayNode", "\350\265\267\351\243\236", nullptr));
        label_2->setText(QCoreApplication::translate("GraphicsDataArrayNode", "in", nullptr));
        dataArrayNodeName->setText(QCoreApplication::translate("GraphicsDataArrayNode", " \346\225\260\345\210\227\350\212\202\347\202\271", nullptr));
        label_3->setText(QCoreApplication::translate("GraphicsDataArrayNode", "Array", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GraphicsDataArrayNode: public Ui_GraphicsDataArrayNode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHICSDATAARRAYNODE_H
