#include "GraphicsTextItem.h"



GraphicsTextItem::GraphicsTextItem(QGraphicsItem *parent):
	AbstractGraphicsItem(parent)
{
	setPlainText(QStringLiteral("请输入..."));

}

void GraphicsTextItem::setAttr()
{
	AbstractGraphicsItem::setAttr();
}

void GraphicsTextItem::SLOT_openAttributeWidget()
{
	AbstractGraphicsItem::SLOT_openAttributeWidget();
	this->connect(attr,&ChartAttribute::confirm,
				  this,& GraphicsTextItem ::setAttr);
}


void GraphicsTextItem::setCoordinate(const QRectF &pos)
{
	setPos(pos.topLeft());
	setTextWidth(pos.width());
}
