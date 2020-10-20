#ifndef ABSTRACTGRAPHICSSHAPEITEM_H
#define ABSTRACTGRAPHICSSHAPEITEM_H
#include "../AbstractGraphicsItem.h"
#include "../../AttributeDialog/ShapeItemDialog.h"

template<class GraphicsItem>
class AbstractGraphicsShapeItem:public QObject,public AbstractGraphicsItem<GraphicsItem>
{
public:
	AbstractGraphicsShapeItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent);
protected:
	ShapeAttribute attribute;
protected slots:
	void setAttr(const ShapeAttribute&attribute);
protected:
	virtual void SLOT_openAttributeWidget() override;

	// AbstractGraphicsItem interface
protected:
	virtual void setCoordinate(const QRectF &pos) override;
	void setPainter(QPainter*painter)const;

	// AbstractGraphicsItem interface
protected:
	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

template<class GraphicsItem>
AbstractGraphicsShapeItem<GraphicsItem>::AbstractGraphicsShapeItem
(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent):
	AbstractGraphicsItem<GraphicsItem>(x,y,width,height,parent)
{
	attribute.penColor = QColor(Qt::GlobalColor::black);
	attribute.brushColor = QColor(Qt::GlobalColor::white);
	attribute.penStyle = Qt::PenStyle::SolidLine;
	attribute.brushStyle = Qt::BrushStyle::NoBrush;
}

template<class GraphicsItem>
void AbstractGraphicsShapeItem<GraphicsItem>::setAttr(const ShapeAttribute &attribute)
{
	this->attribute = attribute;
}

template<class GraphicsItem>
void AbstractGraphicsShapeItem<GraphicsItem>::SLOT_openAttributeWidget()
{
	auto attrDialog = new ShapeItemDialog(attribute);
	attrDialog->show();
	connect(attrDialog,&ShapeItemDialog::confirm,this,&AbstractGraphicsShapeItem::setAttr);
}

template<class GraphicsItem>
void AbstractGraphicsShapeItem<GraphicsItem>::setCoordinate(const QRectF &pos)
{
	setRect(pos);
}

template<class GraphicsItem>
void AbstractGraphicsShapeItem<GraphicsItem>::setPainter(QPainter *painter) const
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

template<class GraphicsItem>
void AbstractGraphicsShapeItem<GraphicsItem>::paint
(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	AbstractGraphicsItem<GraphicsItem>::paint(painter,option,widget);
	setPainter(painter);
}

#endif // ABSTRACTGRAPHICSSHAPEITEM_H
