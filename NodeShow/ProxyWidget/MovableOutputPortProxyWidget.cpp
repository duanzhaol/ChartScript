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
    MovableProxyWidget::setWidget(node);
}

OutputPortWidget *MovableOutputPortProxyWidget::getOutputPortWidget()
{
	return dynamic_cast<OutputPortWidget*>(this->widget());
}

OutputPort *MovableOutputPortProxyWidget::getOutputPort()
{
	return MovableOutputPortProxyWidget::getOutputPortWidget()->getOutputPort();
}

QPointF MovableOutputPortProxyWidget::getOutputPortCoordinate(const QGraphicsItem *item)
{
	OutputPort* outputPort = this->getOutputPort();
	return this->mapToItem(item,outputPort->pos()+QPointF(outputPort->width()/2.,outputPort->height()/2.));
}
