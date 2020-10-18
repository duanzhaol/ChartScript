#ifndef GRAPHICSELLIPSEITEM_H
#define GRAPHICSELLIPSEITEM_H
#include "GraphicsShapeDefine.h"
#include <QGraphicsEllipseItem>


class GraphicsEllipseItem :public QObject,public AbstractGraphicsItem<QGraphicsEllipseItem>
{
	Q_OBJECT
public:
	GraphicsEllipseItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr);
private slots :
	void setAttr();
protected:
	virtual void SLOT_openAttributeWidget() override;

	// AbstractGraphicsItem interface
protected:
	virtual void setCoordinate(const QRectF &pos) override;
};

#endif // GRAPHICSRECTITEM_H


