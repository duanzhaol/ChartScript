#include "GraphicsLineSeriesNode.h"
#include "ui_GraphicsLineSeriesNode.h"

GraphicsLineSeriesNode::GraphicsLineSeriesNode(QWidget *parent) :
      QWidget(parent),
      ui(new Ui::GraphicsLineSeriesNode)
{
    ui->setupUi(this);
}

GraphicsLineSeriesNode::~GraphicsLineSeriesNode()
{
    delete ui;
}
