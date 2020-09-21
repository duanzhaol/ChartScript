#include "GraphicsStartNode.h"
#include "ui_GraphicsStartNode.h"
#include "Interpreter/DataModel/StartNode.h"
#include "Interpreter/Interpreter/InterpreterController.h"
#include <QDebug>
#include <QMouseEvent>

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


NodeName GraphicsStartNode::getNodeName()const
{
	return QStringLiteral("Start");
}

void GraphicsStartNode::setNodeName(const NodeName &newNodeName)
{
	Q_UNUSED(newNodeName);
}



void GraphicsStartNode::mousePressEvent(QMouseEvent *event)
{
	OutputPortWidget::mousePressEvent(event);
	qDebug()<<"S"<<endl;
	InterpreterController::getGlobalInstance()->interprete();
	event->accept();
}

