#ifndef CONNECTLINEITEM_H
#define CONNECTLINEITEM_H

#include "MovableSinglePortProxyWidget.h"
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include "DualPortInterface.h"



class ConnectLineItem:public QGraphicsPolygonItem
{

public:

  explicit ConnectLineItem(InputPortInterface*inputPort,OutputPortInterface*outputPort);

  // QGraphicsItem interface
public:
  QRectF boundingRect() const override;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
  QPainterPath shape() const override;

private:
  InputPortInterface*inputNode;
  OutputPortInterface*outputNode;
  QPolygonF mArrow;



};

#endif // CONNECTLINEITEM_H
