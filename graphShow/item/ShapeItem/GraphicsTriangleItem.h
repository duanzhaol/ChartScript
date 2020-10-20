#ifndef GRAPHICSTRIANGLEITEM_H
#define GRAPHICSTRIANGLEITEM_H

#include "AbstractGraphicsShapeItem.h"
#include <QGraphicsRectItem>

class GraphicsTriangleItem:public AbstractGraphicsShapeItem
{
public:
	GraphicsTriangleItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr);

	// AbstractGraphicsItem interface
protected:
	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // GRAPHICSTRIANGLEITEM_H
