#include "GraphicsScatterSeriesNode.h"
#include "ui_GraphicsScatterSeriesNode.h"

GraphicsScatterSeriesNode::GraphicsScatterSeriesNode(QWidget *parent) :
      QWidget(parent),
      ui(new Ui::GraphicsScatterSeriesNode)
{
    ui->setupUi(this);
}

GraphicsScatterSeriesNode::~GraphicsScatterSeriesNode()
{
    delete ui;
}
