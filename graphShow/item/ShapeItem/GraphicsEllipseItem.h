#ifndef GRAPHICSELLIPSEITEM_H
#define GRAPHICSELLIPSEITEM_H
#include "../AbstractGraphicsItem.h"
#include <QGraphicsRectItem>
#include "../../AttributeDialog/ShapeItemDialog.h"
#include "AbstractGraphicsShapeItem.h"


class GraphicsEllipseItem :public AbstractGraphicsShapeItem
{
	Q_OBJECT
public:
	GraphicsEllipseItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr);

	// AbstractGraphicsItem interface
protected:
	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // GRAPHICSRECTITEM_H


