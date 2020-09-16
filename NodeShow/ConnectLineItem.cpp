#include "ConnectLineItem.h"

#include <QPainter>


ConnectLineItem::ConnectLineItem(InputPortInterface *inputNode, OutputPortInterface *outputNode)
    :inputNode(inputNode),
      outputNode(outputNode)
{

}

QRectF ConnectLineItem::boundingRect() const
{
  return shape().controlPointRect();
  //return QRectF(leftWidget->centerCoordinate,rightWidget->centerCoordinate);
}


QPainterPath ConnectLineItem::shape() const
{
  QPainterPath path = QGraphicsPolygonItem::shape();
  path.addPolygon(mArrow);
  return path;
}

#include <QDebug>


void ConnectLineItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  Q_UNUSED(option)
  Q_UNUSED(widget)
//  painter->setPen(QPen(Qt::blue,5));

  QPointF right = inputNode->getInputPortCoordinate(this);
  QPointF left = outputNode->getOutputPortCoordinate(this);
  qDebug()<<left<<right;

//  painter->drawLine(left,right);

  mArrow.clear();
  double par = 12;//箭头部分三角形的腰长
  double slopy = atan2((right.y() - left.y()), (right.x() - left.x()));
  double cosy = cos(slopy);
  double siny = sin(slopy);
  QPointF point1 = QPoint(right.x() + int(-par*cosy - (par / 2.0*siny)), right.y() + int(-par*siny + (par / 2.0*cosy)));
  QPointF point2 = QPoint(right.x() + int(-par*cosy + (par / 2.0*siny)), right.y() - int(par / 2.0*cosy + par*siny));
  QPointF points[3] = { right, point1, point2 };
  painter->setRenderHint(QPainter::Antialiasing, true);//消锯齿
  painter->setBrush(QBrush(QColor(94,167,255,255)));
  painter->setPen(QPen(QColor(94,167,255,255)));


  int offsetX = int(par*siny / 3);
  int offsetY = int(par*cosy / 3);
  QPoint point3, point4;
  point3 = QPoint(right.x() + int(-par*cosy - (par / 2.0*siny)) + offsetX, right.y() + int(-par*siny + (par / 2.0*cosy)) - offsetY);
  point4 = QPoint(right.x() + int(-par*cosy + (par / 2.0*siny) - offsetX), right.y() - int(par / 2.0*cosy + par*siny) + offsetY);

  mArrow<<right<<point1<<point3<<left<<point4<<point2;
  QPointF arrowBodyPoints[3]= { left, point3, point4 };
  painter->drawPolygon(points, 3);//绘制箭头部分
  painter->drawPolygon(arrowBodyPoints, 3);//绘制箭身部分
  QGraphicsPolygonItem::paint(painter,option,widget);
}


