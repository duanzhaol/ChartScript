#include "GraphicsStartNode.h"
#include "ui_GraphicsStartNode.h"

GraphicsStartNode::GraphicsStartNode(QWidget *parent) :
	PortWidget(parent),
      ui(new Ui::GraphicsStartNode)
{
    ui->setupUi(this);
}

GraphicsStartNode::~GraphicsStartNode()
{
    delete ui;
}

OutputPort *GraphicsStartNode::getOutputPort()
{
	return ui->outputPort;
}
