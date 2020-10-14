#include "MovableProxyWidget.h"
#include <QGraphicsSceneMouseEvent>
#include "GraphicsStartNode.h"
#include <QWidget>
#include <QDebug>
#include <QApplication>
#include "../GraphicsNode/AbstractGraphicsNode.h"
#include <QGraphicsScene>
#include "AbstractGraphicsTopNode.h"

MovableProxyWidget::MovableProxyWidget(){

}

void MovableProxyWidget::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
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

void MovableProxyWidget::setWidget(QWidget *widget)
{
    QGraphicsProxyWidget::setWidget(widget);
    prepareGeometryChange();
    this->setMinimumSize(0,0);
    this->setMaximumSize(100000,100000);
    this->resize(widget->width(),widget->height());
    update(this->geometry());
    this->widget()->resize(widget->width(),widget->height());

}



