#include "GraphicsRectItem.h"

GraphicsRectItem :: GraphicsRectItem
(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent):
	AbstractGraphicsShapeItem(x,y,width,height,parent)
{

}



void GraphicsRectItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	AbstractGraphicsShapeItem::paint(painter,option,widget);
	painter->drawRect(boundingRect());
}
