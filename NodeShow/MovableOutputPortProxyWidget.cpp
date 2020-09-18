#include "MovableOutputPortProxyWidget.h"

QWidget *MovableOutputPortProxyWidget::widget() const
{
	return MovableProxyWidget::widget();
}

MovableOutputPortProxyWidget::MovableOutputPortProxyWidget()
{

}

void MovableOutputPortProxyWidget::setOutputPortWidget(OutputPortWidget *node)
{
	QGraphicsProxyWidget::setWidget(node);
}

OutputPortWidget *MovableOutputPortProxyWidget::getOutputPortWidget()
{
	return reinterpret_cast<OutputPortWidget*>(this->widget());
}

OutputPort *MovableOutputPortProxyWidget::getOutputPort()
{
	return MovableOutputPortProxyWidget::getOutputPortWidget()->getOutputPort();
}

QPointF MovableOutputPortProxyWidget::getOutputPortCoordinate(const QGraphicsItem *item)
{
	return this->mapToItem(item,this->getOutputPort()->pos());
}
