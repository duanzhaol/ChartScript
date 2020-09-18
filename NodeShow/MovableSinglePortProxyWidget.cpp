#include "MovableSinglePortProxyWidget.h"

QWidget *MovableSinglePortProxyWidget::widget()const
{
    return MovableProxyWidget::widget();
}

MovableSinglePortProxyWidget::MovableSinglePortProxyWidget()
{

}

void MovableSinglePortProxyWidget::setWidget(GraphicsDataNode *node)
{
    QGraphicsProxyWidget::setWidget(node);
}

GraphicsDataNode *MovableSinglePortProxyWidget::getGraphicsDataNode()
{
    return reinterpret_cast<GraphicsDataNode*>(this->widget());
}

InputPortType *MovableSinglePortProxyWidget::getInputPort()
{
    return this->getGraphicsDataNode()->getInputPort();
}


QPointF MovableSinglePortProxyWidget::getInputPortCoordinate(const QGraphicsItem *item)
{
	return this->mapToItem(item,this->getInputPort()->pos());
}
