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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraphicsDataNode
{
public:
    QComboBox *comboBox;
    QLabel *nodeBackground;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_2;
    QWidget *inputPort;
    QPushButton *inputButton;
    QWidget *outputPort;
    QPushButton *outButton;

    void setupUi(QWidget *GraphicsDataNode)
    {
        if (GraphicsDataNode->objectName().isEmpty())
            GraphicsDataNode->setObjectName(QString::fromUtf8("GraphicsDataNode"));
        GraphicsDataNode->resize(658, 616);
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
        comboBox->setGeometry(QRect(330, 270, 101, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(9);
        comboBox->setFont(font);
        comboBox->setStyleSheet(QString::fromUtf8("\n"
"QComboBox {border-radius:10px;background:rgb(97, 97, 97);color:#ffffff;\n"
"padding-left:30px;\n"
"}  \n"
"\n"
"QComboBox QAbstractItemView {background:rgb(189, 189, 189);color:#ffffff;} \n"
" \n"
"\n"
"QComboBox::drop-down{\n"
"width: 20px;\n"
"border-left: 1px solid #ffffff; \n"
"}    \n"
"\n"
"QComboBox::down-arrow {image: url(:/img/img/xia.png);height:40px;width:20px;}   \n"
"\n"
"QListView::item{padding-left:30px;background:rgb(152, 152, 152);color:#ffffff;}  \n"
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
        nodeBackground->setGeometry(QRect(260, 220, 251, 131));
        nodeBackground->setStyleSheet(QString::fromUtf8("\n"
"\n"
"background: #222222;\n"
"    color: #BBBBBB;\n"
"    font-family: \"Segoe UI\";\n"
"border-radius:50%;\n"
""));
        lineEdit = new QLineEdit(GraphicsDataNode);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(320, 310, 131, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setWeight(50);
        lineEdit->setFont(font1);
        lineEdit->setStyleSheet(QString::fromUtf8("border:0px;\n"
"border-radius:10px;"));
        lineEdit_2 = new QLineEdit(GraphicsDataNode);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(300, 230, 171, 31));
        lineEdit_2->setFont(font1);
        lineEdit_2->setStyleSheet(QString::fromUtf8("border:3px solid rgb(126, 126, 126);\n"
"border-radius:10px;"));
        label = new QLabel(GraphicsDataNode);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(330, 140, 31, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(8);
        font2.setBold(false);
        font2.setWeight(50);
        label->setFont(font2);
        label_2 = new QLabel(GraphicsDataNode);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 140, 31, 21));
        label_2->setFont(font2);
        inputPort = new QWidget(GraphicsDataNode);
        inputPort->setObjectName(QString::fromUtf8("inputPort"));
        inputPort->setGeometry(QRect(200, 290, 20, 20));
        inputButton = new QPushButton(inputPort);
        inputButton->setObjectName(QString::fromUtf8("inputButton"));
        inputButton->setGeometry(QRect(0, 0, 20, 20));
        inputButton->setMinimumSize(QSize(0, 0));
        inputButton->setMaximumSize(QSize(16777215, 16777215));
        inputButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"							 border: 1px solid #333333;\n"
"							 padding: 4px;\n"
"							 border-radius:10px;\n"
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
        outputPort = new QWidget(GraphicsDataNode);
        outputPort->setObjectName(QString::fromUtf8("outputPort"));
        outputPort->setGeometry(QRect(280, 140, 20, 20));
        outButton = new QPushButton(outputPort);
        outButton->setObjectName(QString::fromUtf8("outButton"));
        outButton->setGeometry(QRect(0, 0, 20, 20));
        outButton->setMinimumSize(QSize(0, 0));
        outButton->setMaximumSize(QSize(16777215, 16777215));
        outButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"							 border: 1px solid #333333;\n"
"							 padding: 4px;\n"
"							 border-radius:10px;\n"
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
        nodeBackground->raise();
        comboBox->raise();
        lineEdit->raise();
        lineEdit_2->raise();
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
        comboBox->setItemText(0, QCoreApplication::translate("GraphicsDataNode", "String", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("GraphicsDataNode", "float", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("GraphicsDataNode", "double", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("GraphicsDataNode", "int", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("GraphicsDataNode", "long long", nullptr));

        nodeBackground->setText(QString());
        lineEdit->setText(QCoreApplication::translate("GraphicsDataNode", "Hello World!", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("GraphicsDataNode", " \346\225\260\346\215\256\350\212\202\347\202\271", nullptr));
        label->setText(QCoreApplication::translate("GraphicsDataNode", "out", nullptr));
        label_2->setText(QCoreApplication::translate("GraphicsDataNode", "in", nullptr));
        inputPort->setWindowTitle(QCoreApplication::translate("GraphicsDataNode", "Form", nullptr));
        inputButton->setText(QString());
        outputPort->setWindowTitle(QCoreApplication::translate("GraphicsDataNode", "Form", nullptr));
        outButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GraphicsDataNode: public Ui_GraphicsDataNode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHICSDATANODE_H
