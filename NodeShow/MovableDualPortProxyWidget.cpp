#include "MovableDualPortProxyWidget.h"

MovableDualPortProxyWidget::MovableDualPortProxyWidget()
{

}

OutputPortType *MovableDualPortProxyWidget::getOutputPort()
{
	return MovableSinglePortProxyWidget::getGraphicsDataNode()->getOutputPort();
}

QPointF MovableDualPortProxyWidget::getOutputPortCoordinate(const QGraphicsItem *item)
{
	return this->mapToItem(item,this->getOutputPort()->pos());
}
