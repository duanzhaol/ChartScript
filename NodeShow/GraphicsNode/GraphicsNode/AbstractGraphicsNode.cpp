#include "AbstractGraphicsNode.h"
#include <QMouseEvent>
#include <QDebug>
#include <ConnectController.h>

AbstractGraphicsNode::AbstractGraphicsNode(QWidget *parent, Qt::WindowFlags f):
	QWidget(parent,f)
{
	connectToLineController();
}


void AbstractGraphicsNode::mousePressEvent(QMouseEvent *event)
{
	QWidget::mousePressEvent(event);
    event->accept();
}

void AbstractGraphicsNode::connectToLineController()
{
	connect(this,&AbstractGraphicsNode::PortClicked,
			ConnectController::getInstance(),&ConnectController::ConnectLine);//代替SINGAL和SLOT，会提示是否匹配，不需要参数

}


