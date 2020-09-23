#include "MovableInputPortProxyWidget.h"
#include <QDebug>
#include <QMessageBox>

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
	InputPort* inputPort = this->getInputPort();
	return this->mapToItem(item,inputPort->pos()+QPointF(inputPort->width()/2.,inputPort->height()/2.));
}
