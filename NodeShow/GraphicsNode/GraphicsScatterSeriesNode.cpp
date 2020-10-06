﻿#include "GraphicsScatterSeriesNode.h"
#include "ui_GraphicsScatterSeriesNode.h"

GraphicsScatterSeriesNode::GraphicsScatterSeriesNode(QWidget *parent) :
      DualPortWidget(),
      ui(new Ui::GraphicsScatterSeriesNode)
{
    ui->setupUi(this);

//    /*标题lineedit文字居中*/
//    ui->ScatterSeriesName->setAlignment( Qt::AlignHCenter);
}

GraphicsScatterSeriesNode::~GraphicsScatterSeriesNode()
{
    delete ui;
}

NodeName GraphicsScatterSeriesNode::getNodeName() const
{
    return ui->ScatterSeriesName->text();
}

void GraphicsScatterSeriesNode::setNodeName(const NodeName &newNodeName)
{
    ui->ScatterSeriesName->setText(newNodeName);
}

AbstractArrayNode *GraphicsScatterSeriesNode::getXData() const
{
    return ui->XDataArray;
}

AbstractArrayNode *GraphicsScatterSeriesNode::getYData() const
{
    return ui->YDataArray;
}

OutputPort *GraphicsScatterSeriesNode::getOutputPort()
{
    return ui->outputPort;
}

InputPort *GraphicsScatterSeriesNode::getInputPort()
{
    return ui->inputPort;
}
