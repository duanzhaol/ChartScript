#include "GraphicsStartNode.h"
#include "ui_GraphicsStartNode.h"
#include "Interpreter/DataModel/StartNode.h"
#include "Interpreter/Interpreter/InterpreterController.h"
#include <QDebug>
#include <QMouseEvent>

GraphicsStartNode::GraphicsStartNode(Proxy *proxy, QWidget *parent):
	AbstractGraphicsTopNode (proxy),
	ui(new Ui::GraphicsStartNode)
{
    ui->setupUi(this);

	proxy->setWidget(this);
}


GraphicsStartNode::~GraphicsStartNode()
{
    delete ui;
}

OutputPort *GraphicsStartNode::getOutputPort()
{
	return ui->outputPort;
}


NodeName GraphicsStartNode::getNodeName()const
{
	return QStringLiteral("Start");
}

void GraphicsStartNode::setNodeName(const NodeName &newNodeName)
{
	Q_UNUSED(newNodeName);
}


QPointF GraphicsStartNode::getOutputPortCoordinate(QGraphicsItem *item)
{
	OutputPort *outputPort = this->getOutputPort();
	return this->getProxy()->mapToItem(
				item,
				outputPort->pos()+QPointF(outputPort->width()/2.,outputPort->height()/2.)
				);
}

void GraphicsStartNode::start()
{
	InterpreterController::getGlobalInstance()->interprete();
}


