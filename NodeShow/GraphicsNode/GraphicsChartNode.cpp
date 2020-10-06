#include "GraphicsChartNode.h"
#include "ui_GraphicsChartNode.h"

GraphicsChartNode::GraphicsChartNode(QWidget *parent) :
      QWidget(parent),
      ui(new Ui::GraphicsChartNode)
{
    ui->setupUi(this);
}

GraphicsChartNode::~GraphicsChartNode()
{
    delete ui;
}
