#include "AbstractGraphicsTopDualoutNode.h"

AbstractGraphicsTopDualoutNode::AbstractGraphicsTopDualoutNode(MovableProxyWidget *proxy):
	AbstractGraphicsTopNode (proxy)
{

}


QPointF AbstractGraphicsTopDualoutNode::getOutputPortCoordinate(QGraphicsItem *item)
{
	OutputPort *outputPort = this->getOutputPort();
	return this->getProxy()->mapToItem(
				item,
				outputPort->pos()+QPointF(outputPort->width()/2.,outputPort->height()/2.)
				);

}

QPointF AbstractGraphicsTopDualoutNode::getInputPortCoordinate(QGraphicsItem *item)
{
	InputPort *inputPort = this->getInputPort();
	return this->getProxy()->mapToItem(
				item,
				inputPort->pos()+QPointF(inputPort->width()/2.,inputPort->height()/2.)
				);

}


