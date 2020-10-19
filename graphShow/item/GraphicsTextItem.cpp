#include "GraphicsTextItem.h"
#include "../AttributeDialog/TextItemDialog.h"



GraphicsTextItem::GraphicsTextItem(QGraphicsItem *parent):
	AbstractGraphicsItem(parent)
{
	setPlainText(QStringLiteral("请输入..."));

}

void GraphicsTextItem::setAttr()
{
	this->setDocument(dialog->getDocument());
}

void GraphicsTextItem::SLOT_openAttributeWidget()
{
	dialog = new TextItemDialog;
	dialog->setDocument(this->document());
	dialog->show();
	connect(dialog,&TextItemDialog::accepted,this,&GraphicsTextItem::setAttr);
}


void GraphicsTextItem::setCoordinate(const QRectF &pos)
{
	setPos(pos.topLeft());
	setTextWidth(pos.width());
}
