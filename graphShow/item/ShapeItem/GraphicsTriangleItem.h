#ifndef GRAPHICSTRIANGLEITEM_H
#define GRAPHICSTRIANGLEITEM_H

#include "AbstractGraphicsShapeItem.h"
#include <QGraphicsRectItem>

/**
 * @brief
 * 三角形元素，用于添加三角形
 */

class GraphicsTriangleItem:public AbstractGraphicsShapeItem
{
public:
	GraphicsTriangleItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr);

	// AbstractGraphicsItem interface
protected:
	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // GRAPHICSTRIANGLEITEM_H
