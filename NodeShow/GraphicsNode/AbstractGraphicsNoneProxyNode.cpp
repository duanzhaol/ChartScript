#include "AbstractGraphicsNoneProxyNode.h"

AbstractGraphicsNoneProxyNode::AbstractGraphicsNoneProxyNode()
{

}

QPointF AbstractGraphicsNoneProxyNode::getOutputPortCoordinate(QGraphicsItem *item)
{
    auto outputPort= this->getOutputPort();
    auto portChartCoordinate = outputPort->mapToGlobal(outputPort->pos());

}

QPointF AbstractGraphicsNoneProxyNode::getInputPortCoordinate(QGraphicsItem *item)
{

}
