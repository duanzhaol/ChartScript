#ifndef GRAPHICSPIXMAPITEM_H
#define GRAPHICSPIXMAPITEM_H

#include "AbstractGraphicsItem.h"
#include <QGraphicsPixmapItem>
#include <QImage>
#include "../AttributeDialog/PixmapItemDialog.h"

class GraphicsImageItem:public QObject,public AbstractGraphicsItem<QGraphicsRectItem>
{
	Q_OBJECT

	QImage originImage,scaledImage;
	PixmapItemDialog*dialog = nullptr;
public:
	GraphicsImageItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr);

	// AbstractGraphicsItem interface
protected:
	virtual void SLOT_openAttributeWidget() override;
	virtual void setCoordinate(const QRectF &pos) override;
	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
protected slots:
	void setAttr();
};

#endif // GRAPHICSPIXMAPITEM_H
