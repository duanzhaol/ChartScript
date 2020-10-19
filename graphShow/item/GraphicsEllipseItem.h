#ifndef GRAPHICSELLIPSEITEM_H
#define GRAPHICSELLIPSEITEM_H
#include "GraphicsShapeDefine.h"
#include <QGraphicsEllipseItem>
#include "../AttributeDialog/ShapeItemDialog.h"


class GraphicsEllipseItem :public QObject,public AbstractGraphicsItem<QGraphicsEllipseItem>
{
	Q_OBJECT
	ShapeAttribute attribute;
public:
	GraphicsEllipseItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr);
private slots :
	void setAttr(const ShapeAttribute&attribute);
protected:
	virtual void SLOT_openAttributeWidget() override;

	// AbstractGraphicsItem interface
protected:
	virtual void setCoordinate(const QRectF &pos) override;

	// AbstractGraphicsItem interface
protected:
	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // GRAPHICSRECTITEM_H


