#ifndef GRAPHICSTEXTITEM_H
#define GRAPHICSTEXTITEM_H

#include "AbstractGraphicsItem.h"
#include <QGraphicsTextItem>



class GraphicsTextItem:public AbstractGraphicsItem<QGraphicsTextItem>
{
	Q_OBJECT
public:
	GraphicsTextItem(QGraphicsItem *parent = nullptr);
private slots :
	void setAttr();
protected:
	virtual void SLOT_openAttributeWidget() override;

	// AbstractGraphicsItem interface
protected:
	virtual void setCoordinate(const QRectF &pos) override;
};


#endif // GRAPHICSTEXTITEM_H
