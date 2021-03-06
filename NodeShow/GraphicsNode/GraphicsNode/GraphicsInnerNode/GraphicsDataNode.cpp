#include "GraphicsDataNode.h"
#include "ui_GraphicsDataNode.h"
#include <QBitmap>
#include <QListView>
#include <QPainter>
#include  <QDebug>
#include <QMessageBox>
#include "Interpreter/DataModel/AbstractDataNode.h"
#include <QGraphicsDropShadowEffect>
#include "QIntValidator"
#include "QDoubleValidator"
#include "QIntValidator"
#include "QRegExpValidator"
#include "QValidator"
#include "QRegExp"
#include "../../UTools/UniqueNamer.h"


GraphicsDataNode::GraphicsDataNode(QWidget *parent) :
	ui(new Ui::GraphicsDataNode)
{

	ui->setupUi(this);
	ui->comboBox->setView(new QListView());

	/*设置qcombox文字居中显示，放一个lineedit进去 哈哈（设置lineedit文字居中）*/
	QLineEdit *lineEdit = new QLineEdit;
	lineEdit->setReadOnly(true);
	lineEdit->setAlignment(Qt::AlignCenter);
	ui->comboBox->setLineEdit(lineEdit);

	/*两个单独lineedit文字居中*/
	ui->dataNodeName->setAlignment( Qt::AlignHCenter); //数据节点的名字居中显示
	ui->dataNodeData->setAlignment( Qt::AlignHCenter); //数据节点的数据居中显示


	ui->inputPort->setParent(this);
	ui->outputPort->setParent(this);
	this->initName();


}

GraphicsDataNode::~GraphicsDataNode()
{
	delete ui;
}

InputPort *GraphicsDataNode::getInputPort()
{
	return ui->inputPort;
}

OutputPort *GraphicsDataNode::getOutputPort()
{
	return ui->outputPort;
}



NodeName GraphicsDataNode::getNodeName()const
{
	return ui->dataNodeName->text();
}

void GraphicsDataNode::setNodeName(const NodeName&newNodeName)
{
	ui->dataNodeName->setText(newNodeName);
}



QVariant GraphicsDataNode::getNodeData()const
{
	return QVariant::fromValue(ui->dataNodeData->text());
}

void GraphicsDataNode::setNodeData(const QVariant&newData)
{
	ui->dataNodeData->setText(newData.toString());
}

void GraphicsDataNode::on_comboBox_currentIndexChanged(const QString &arg1)
{
	//***待修改正则表达式，约束范围
	if(arg1=="long long"){
		ui->dataNodeData->clear();

		QMessageBox::information(NULL, "提示", "long long输入范围为");

		QRegExp regExp("0|[1-9]\\d{0,4}");
		ui->dataNodeData->setValidator(new QRegExpValidator(regExp, this));
	}
	else if(arg1=="double"){
		ui->dataNodeData->clear();

		QMessageBox::information(NULL, "提示", "double输入范围为");
		QRegExp regExp("0|[1-9]\\d{0,4}");
		ui->dataNodeData->setValidator(new QRegExpValidator(regExp, this));
	}
	else if(arg1=="float"){
		ui->dataNodeData->clear();

		QMessageBox::information(NULL, "提示", "float输入范围为");
		QRegExp regExp("0|[1-9]\\d{0,4}");
		ui->dataNodeData->setValidator(new QRegExpValidator(regExp, this));
	}
	else if(arg1=="int"){
		ui->dataNodeData->clear();

		QMessageBox::information(NULL, "提示", "int输入范围为");
		QRegExp regExp("0|[1-9]\\d{0,4}");
		ui->dataNodeData->setValidator(new QRegExpValidator(regExp, this));

		qDebug()<<"int";
	}
	else if(arg1=="String"){
		ui->dataNodeData->clear();
		qDebug()<<"String";
	}

}

