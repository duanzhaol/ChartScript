#ifndef GRAPHICSRECTITEM_H
#define GRAPHICSRECTITEM_H
#include <QGraphicsRectItem>
#include "AbstractGraphicsShapeItem.h"

class GraphicsRectItem :public AbstractGraphicsShapeItem
{
	Q_OBJECT
public:
	GraphicsRectItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr);

	// AbstractGraphicsItem interface
protected:
	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};





#endif // GRAPHICSRECTITEM_H
