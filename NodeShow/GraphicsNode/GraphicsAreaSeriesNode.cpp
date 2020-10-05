#include "GraphicsAreaSeriesNode.h"
#include "ui_GraphicsAreaSeriesNode.h"

GraphicsAreaSeriesNode::GraphicsAreaSeriesNode(QWidget *parent) :
      QWidget(parent),
      ui(new Ui::GraphicsAreaSeriesNode)
{
    ui->setupUi(this);
}

GraphicsAreaSeriesNode::~GraphicsAreaSeriesNode()
{
    delete ui;
}
