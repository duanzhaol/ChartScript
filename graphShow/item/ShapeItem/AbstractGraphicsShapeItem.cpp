#include "AbstractGraphicsShapeItem.h"






AbstractGraphicsShapeItem::AbstractGraphicsShapeItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent):
	AbstractGraphicsItem(x,y,width,height,parent)
{
	attribute.penColor = QColor(Qt::GlobalColor::black);
	attribute.brushColor = QColor(Qt::GlobalColor::white);
	attribute.penStyle = Qt::PenStyle::SolidLine;
	attribute.brushStyle = Qt::BrushStyle::NoBrush;
}

void AbstractGraphicsShapeItem::setAttr(const ShapeAttribute &attribute)
{
	this->attribute = attribute;
}

void AbstractGraphicsShapeItem::SLOT_openAttributeWidget()
{
	auto attrDialog = new ShapeItemDialog(attribute);
	attrDialog->show();
	connect(attrDialog,&ShapeItemDialog::confirm,this,&AbstractGraphicsShapeItem::setAttr);
}

void AbstractGraphicsShapeItem::setCoordinate(const QRectF &pos)
{
	setRect(pos);
}

void AbstractGraphicsShapeItem::setPainter(QPainter *painter) const
{
	QPen pen;
	pen.setColor(attribute.penColor);
	pen.setStyle(attribute.penStyle);
	painter->setPen(pen);

	QBrush brush;
	brush.setColor(attribute.brushColor);
	brush.setStyle(attribute.brushStyle);
	painter->setBrush(brush);

}

void AbstractGraphicsShapeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	AbstractGraphicsItem::paint(painter,option,widget);
	setPainter(painter);
}
