#ifndef CONNECTLINEITEM_H
#define CONNECTLINEITEM_H

#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include "Dualputable.h"
#include<QtMath>
#include "Interpreter/Exception/ImplicitTypeConversion.h"
#include "Interpreter/Exception/TypeUnconvertible.h"


class ConnectLineItem:public QGraphicsPolygonItem
{

public:


  explicit ConnectLineItem(Inputable*inputPort,Outputable*outputPort);

  // QGraphicsItem interface
public:
  QRectF boundingRect() const override;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
  QPainterPath shape() const override;

private:
  Inputable*inputNode;
  Outputable*outputNode;
  QPolygonF mArrow;



};

#endif // CONNECTLINEITEM_H
