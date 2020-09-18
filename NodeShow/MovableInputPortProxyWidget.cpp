#include "MovableInputPortProxyWidget.h"

QWidget *MovableInputPortProxyWidget::widget()const
{
    return MovableProxyWidget::widget();
}

MovableInputPortProxyWidget::MovableInputPortProxyWidget()
{

}

void MovableInputPortProxyWidget::setInputPortWidget(InputPortWidget *node)
{
    QGraphicsProxyWidget::setWidget(node);
}

InputPortWidget *MovableInputPortProxyWidget::getInputPortWidget()
{
	return reinterpret_cast<InputPortWidget*>(this->widget());
}

InputPort *MovableInputPortProxyWidget::getInputPort()
{
	return this->getInputPortWidget()->getInputPort();
}


QPointF MovableInputPortProxyWidget::getInputPortCoordinate(const QGraphicsItem *item)
{
	return this->mapToItem(item,this->getInputPort()->pos());
}
