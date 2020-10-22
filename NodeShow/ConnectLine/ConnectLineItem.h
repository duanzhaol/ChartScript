#ifndef CONNECTLINEITEM_H
#define CONNECTLINEITEM_H

#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include<QtMath>
#include <QObject>
#include "Interpreter/Exception/ImplicitTypeConversion.h"
#include "Interpreter/Exception/TypeUnconvertible.h"
#include "GraphicsNode/Dualputable.h"


class ConnectLineItem:public QGraphicsPolygonItem,public QObject
{

public:
    Q_OBJECT

public:
  explicit ConnectLineItem(Inputable*inputPort,Outputable*outputPort);

  // QGraphicsItem interface
public:
  QRectF boundingRect() const override;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
  QPainterPath shape() const override;

  int LineIndex=-1;
  Inputable*inputNode;
  Outputable*outputNode;

private:

  QPolygonF mArrow;

signals:
    void LineClickedWithDele(ConnectLineItem*);

  // QGraphicsItem interface
protected:
  virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

  // QGraphicsItem interface
protected:
  virtual void keyPressEvent(QKeyEvent *event) override;



};

#endif // CONNECTLINEITEM_H
