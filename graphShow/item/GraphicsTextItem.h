#ifndef GRAPHICSTEXTITEM_H
#define GRAPHICSTEXTITEM_H

#include "AbstractGraphicsItem.h"
#include <QGraphicsTextItem>
#include "../AttributeDialog/TextItemDialog.h"



class GraphicsTextItem:public AbstractGraphicsItem<QGraphicsTextItem>
{
	Q_OBJECT

	TextItemDialog*dialog = nullptr;
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
