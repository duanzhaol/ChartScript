#include "MovableProxyWidget.h"
#include <QGraphicsSceneMouseEvent>
#include <QWidget>
#include <QDebug>

MovableProxyWidget::MovableProxyWidget()
{

}



void MovableProxyWidget::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug()<<event;
  QGraphicsProxyWidget::mousePressEvent(event);
  QPointF y = mapToScene(event->pos());
  QPointF x = scenePos();
  this->coordinateDifference = y - x;
}

void MovableProxyWidget::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
  QGraphicsProxyWidget::mouseMoveEvent(event);
  QPointF y = mapToScene(event->pos());
  QPointF x = y - this->coordinateDifference;


  if(this->widget() != nullptr)
  {this->setGeometry(QRectF(x.rx(), x.ry(), this->widget()->width(), this->widget()->height()));

  }
}

