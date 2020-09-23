#include "GraphicsDataArrayNode.h"
#include "ui_GraphicsDataArrayNode.h"

#include <QListView>

GraphicsDataArrayNode::GraphicsDataArrayNode(QWidget *parent) :
      PortWidget(parent),
      ui(new Ui::GraphicsDataArrayNode)
{
    ui->setupUi(this);
    ui->comboBox->setView(new QListView());



    /*两个单独lineedit文字居中*/
    ui->dataArrayNodeName->setAlignment( Qt::AlignHCenter); //数据节点的名字居中显示
    ui->dataArrayNodeData->setAlignment( Qt::AlignHCenter); //数据节点的数据居中显示

}

GraphicsDataArrayNode::~GraphicsDataArrayNode()
{
    delete ui;
}

NodeName GraphicsDataArrayNode::getNodeName() const
{
    return ui->dataArrayNodeName->text();
}

void GraphicsDataArrayNode::setNodeName(const NodeName &newNodeName)
{
    ui->dataArrayNodeName->setText(newNodeName);
}

QVariant GraphicsDataArrayNode::getNodeData() const
{
	return QStringList()<<"233"<<"344";
    return QVariant::fromValue(ui->dataArrayNodeData->text());
}

void GraphicsDataArrayNode::setNodeData(const QVariant &newData)
{
    ui->dataArrayNodeData->setText(newData.toString());
}

OutputPort *GraphicsDataArrayNode::getOutputPort()
{
    return ui->outputPort;
}

InputPort *GraphicsDataArrayNode::getInputPort()
{
    return ui->inputPort;
}

QVariant::Type GraphicsDataArrayNode::getElementType() const
{
	//to do
	return QVariant::Type::String;
}


void GraphicsDataArrayNode::setElementType(QVariant::Type type)
{
	//todo
}
