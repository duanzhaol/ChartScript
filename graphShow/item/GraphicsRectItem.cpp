#include "GraphicsRectItem.h"

GraphicsRectItem :: GraphicsRectItem
(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent):
	AbstractGraphicsItem(x,y,width,height,parent){}

void GraphicsRectItem ::setAttr()
{

}

void GraphicsRectItem ::SLOT_openAttributeWidget()
{

}



void GraphicsRectItem::setCoordinate(const QRectF &pos)
{
	setRect(pos);
}
