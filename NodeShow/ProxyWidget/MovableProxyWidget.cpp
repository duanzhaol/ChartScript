#include "MovableProxyWidget.h"
#include <QGraphicsSceneMouseEvent>
#include "GraphicsStartNode.h"
#include <QWidget>
#include <QDebug>
#include <QApplication>

MovableProxyWidget::MovableProxyWidget(){

}

void MovableProxyWidget::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
  QGraphicsProxyWidget::mousePressEvent(event);
  QPointF y = mapToScene(event->pos());
  QPointF x = scenePos();
  this->coordinateDifference = y - x;
  qDebug()<<"???";
  auto start = dynamic_cast<GraphicsStartNode*>(widget());
  if(start!= nullptr){
	  start->mousePressEvent(new QMouseEvent(event->type(),event->pos(),
											 event->button(),event->buttons(),event->modifiers()));
  }
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
}

