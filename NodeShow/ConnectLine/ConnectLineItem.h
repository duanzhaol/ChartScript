#ifndef CONNECTLINEITEM_H
#define CONNECTLINEITEM_H

#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include<QtMath>
#include <QObject>
#include "Interpreter/Exception/ImplicitTypeConversion.h"
#include "Interpreter/Exception/TypeUnconvertible.h"
#include "GraphicsNode/Dualputable.h"

/**
 * @brief
 * 连接线图元素，用于在图节点编程部分绘制连接线
 */

class ConnectLineItem:public QObject,public QGraphicsPolygonItem
{

public:
	Q_OBJECT
	Q_INTERFACES(QGraphicsItem)
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




};

#endif // CONNECTLINEITEM_H
