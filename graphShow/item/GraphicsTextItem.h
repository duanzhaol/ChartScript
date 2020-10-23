#ifndef GRAPHICSTEXTITEM_H
#define GRAPHICSTEXTITEM_H

#include "AbstractGraphicsItem.h"
#include <QGraphicsTextItem>
#include "../AttributeDialog/TextItemDialog.h"

/**
 * @brief The GraphicsTextItem class
 * 文本框对象，用于像设计元素添加文本框
 * @tparam QGraphicsTextItem 选择文本框作为绘制、碰撞检测的基类
 */

class GraphicsTextItem:public AbstractGraphicsItem<QGraphicsTextItem>
{
	Q_OBJECT

	TextItemDialog*dialog = nullptr;
public:
	GraphicsTextItem(int x,int y,QGraphicsItem *parent = nullptr);
private slots :
	void setAttr();
protected:
	virtual void SLOT_openAttributeWidget() override;

	// AbstractGraphicsItem interface
protected:
	virtual void setCoordinate(const QRectF &pos) override;

	// AbstractGraphicsItem interface
protected:
	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};


#endif // GRAPHICSTEXTITEM_H
