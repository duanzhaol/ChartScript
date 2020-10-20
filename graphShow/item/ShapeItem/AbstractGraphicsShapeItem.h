#ifndef ABSTRACTGRAPHICSSHAPEITEM_H
#define ABSTRACTGRAPHICSSHAPEITEM_H
#include "../AbstractGraphicsItem.h"
#include "../../AttributeDialog/ShapeItemDialog.h"


class AbstractGraphicsShapeItem:public QObject,public AbstractGraphicsItem<QGraphicsRectItem>
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
















#endif // ABSTRACTGRAPHICSSHAPEITEM_H
