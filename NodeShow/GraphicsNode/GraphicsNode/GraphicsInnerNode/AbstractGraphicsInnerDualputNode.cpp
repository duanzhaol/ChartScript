#include "AbstractGraphicsInnerDualputNode.h"
#include "GraphicsChartNode.h"
#include "GraphicsDataArrayNode.h"
#include "GraphicsLineSeriesNode.h"
#include <QPointF>
#include <QDebug>


AbstractGraphicsInnerDualputNode::AbstractGraphicsInnerDualputNode()
{

}

QPointF AbstractGraphicsInnerDualputNode::getOutputPortCoordinate(QGraphicsItem *item)
{

	OutputPort* outputPort = this->getOutputPort();
	Q_ASSERT_X(outputPort->parent() != nullptr,__FILE__ + __LINE__,"do not forget to call Port::setParent");

	return this->getTopProxy()->mapToItem(item,outputPort->mapTo(
											  this->getTopProxy()->widget(),
											  QPoint(outputPort->width()/2,
													 outputPort->height()/2)));
}


QPointF AbstractGraphicsInnerDualputNode::getInputPortCoordinate(QGraphicsItem *item)
{
	InputPort* inputPort = this->getInputPort();
	Q_ASSERT_X(inputPort->parent() != nullptr,__FILE__ + __LINE__,"do not forget to call Port::setParent");


	return this->getTopProxy()->mapToItem(item,inputPort->mapTo(
											  this->getTopProxy()->widget(),
											  QPoint(inputPort->width()/2,
													 inputPort->height()/2)));
}

