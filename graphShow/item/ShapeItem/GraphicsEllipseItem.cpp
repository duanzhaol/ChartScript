#include "GraphicsEllipseItem.h"


GraphicsEllipseItem :: GraphicsEllipseItem
(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent):
	AbstractGraphicsShapeItem<QGraphicsEllipseItem>(x,y,width,height,parent)
{

}


void GraphicsEllipseItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

	AbstractGraphicsShapeItem::paint(painter,option,widget);

	painter->drawEllipse(boundingRect());

}
