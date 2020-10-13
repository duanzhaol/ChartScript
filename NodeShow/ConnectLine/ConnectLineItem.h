#ifndef CONNECTLINEITEM_H
#define CONNECTLINEITEM_H

#include "MovableInputPortProxyWidget.h"
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include "DualPortWidget.h"
#include "MovableOutputPortProxyWidget.h"
#include<QtMath>
#include "Interpreter/Exception/ImplicitTypeConversion.h"
#include "Interpreter/Exception/TypeUnconvertible.h"


class ConnectLineItem:public QGraphicsPolygonItem
{

public:


  explicit ConnectLineItem(InputPortWidget*inputPort,OutputPortWidget*outputPort);

  // QGraphicsItem interface
public:
  QRectF boundingRect() const override;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
  QPainterPath shape() const override;

private:
  InputPortWidget*inputNode;
  OutputPortWidget*outputNode;
  QPolygonF mArrow;



};

#endif // CONNECTLINEITEM_H
