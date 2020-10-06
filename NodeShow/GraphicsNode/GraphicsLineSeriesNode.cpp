#include "GraphicsLineSeriesNode.h"
#include "ui_GraphicsLineSeriesNode.h"

GraphicsLineSeriesNode::GraphicsLineSeriesNode(QWidget *parent) :
      DualPortWidget(),
      ui(new Ui::GraphicsLineSeriesNode)
{
    ui->setupUi(this);


//    /*标题lineedit文字居中*/
//    ui->lineSeriesName->setAlignment( Qt::AlignHCenter);
}

GraphicsLineSeriesNode::~GraphicsLineSeriesNode()
{
    delete ui;
}

NodeName GraphicsLineSeriesNode::getNodeName() const
{
    return ui->lineSeriesName->text();
}

void GraphicsLineSeriesNode::setNodeName(const NodeName &newNodeName)
{
    ui->lineSeriesName->setText(newNodeName);
}

AbstractArrayNode *GraphicsLineSeriesNode::getXData() const
{
    return ui->XDataArray;
}

AbstractArrayNode *GraphicsLineSeriesNode::getYData() const
{
    return ui->YDataArray;
}

OutputPort *GraphicsLineSeriesNode::getOutputPort()
{
    return ui->outputPort;
}



InputPort *GraphicsLineSeriesNode::getInputPort()
{
    return ui->inputPort;
}
