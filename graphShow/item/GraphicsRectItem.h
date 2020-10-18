#ifndef GRAPHICSRECTITEM_H
#define GRAPHICSRECTITEM_H
#include "GraphicsShapeDefine.h"
#include <QGraphicsRectItem>

class GraphicsRectItem :public QObject,public AbstractGraphicsItem<QGraphicsRectItem>
{
	Q_OBJECT
public:
	GraphicsRectItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr);
private slots :
	void setAttr();
protected:
	virtual void SLOT_openAttributeWidget() override;

	// AbstractGraphicsItem interface
protected:
	virtual void setCoordinate(const QRectF &pos) override;
};



#endif // GRAPHICSRECTITEM_H
