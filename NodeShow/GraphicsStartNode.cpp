#include "GraphicsStartNode.h"
#include "ui_GraphicsStartNode.h"

GraphicsStartNode::GraphicsStartNode(QWidget *parent) :
      QWidget(parent),
      ui(new Ui::GraphicsStartNode)
{
    ui->setupUi(this);
}

GraphicsStartNode::~GraphicsStartNode()
{
    delete ui;
}
