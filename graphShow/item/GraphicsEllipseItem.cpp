#include "GraphicsEllipseItem.h"
#include "../AttributeDialog/ShapeItemDialog.h"


GraphicsEllipseItem :: GraphicsEllipseItem
(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent):
	AbstractGraphicsItem(x,y,width,height,parent)
{
	attribute.penColor = QColor(Qt::GlobalColor::black);
	attribute.brushColor = QColor(Qt::GlobalColor::white);
	attribute.penStyle = Qt::PenStyle::SolidLine;
	attribute.brushStyle = Qt::BrushStyle::NoBrush;
}

void GraphicsEllipseItem ::setAttr(const ShapeAttribute &attribute)
{
	this->attribute = attribute;
}

void GraphicsEllipseItem ::SLOT_openAttributeWidget()
{
	auto attrDialog = new ShapeItemDialog(attribute);
	attrDialog->show();
	connect(attrDialog,&ShapeItemDialog::confirm,this,&GraphicsEllipseItem::setAttr);
}



void GraphicsEllipseItem::setCoordinate(const QRectF &pos)
{
	setRect(pos);
}


void GraphicsEllipseItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

	AbstractGraphicsItem::paint(painter,option,widget);

	QPen pen;
	pen.setColor(attribute.penColor);
	pen.setStyle(attribute.penStyle);
	painter->setPen(pen);

	if(attribute.brushStyle == Qt::BrushStyle::NoBrush){
		painter->setBrush(attribute.brushColor);
	}
	else{
		painter->setBrush(QBrush(attribute.penStyle));
	}

	painter->drawEllipse(boundingRect());

}
