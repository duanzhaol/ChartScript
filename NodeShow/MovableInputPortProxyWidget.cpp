#include "MovableInputPortProxyWidget.h"
#include <QDebug>

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
	return dynamic_cast<InputPortWidget*>(this->widget());
}

InputPort *MovableInputPortProxyWidget::getInputPort()
{
	return this->getInputPortWidget()->getInputPort();
}


QPointF MovableInputPortProxyWidget::getInputPortCoordinate(const QGraphicsItem *item)
{
	return this->mapToItem(item,this->getInputPort()->pos()+QPointF(10,10));
}
