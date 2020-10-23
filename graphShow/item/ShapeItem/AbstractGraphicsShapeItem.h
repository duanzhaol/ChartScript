#ifndef ABSTRACTGRAPHICSSHAPEITEM_H
#define ABSTRACTGRAPHICSSHAPEITEM_H
#include "../AbstractGraphicsItem.h"
#include "../../AttributeDialog/ShapeItemDialog.h"

/**
 * @brief The AbstractGraphicsShapeItem class
 * 所有基本形状设计元素的父类，如矩形、三角形、椭圆等。
 * @tparam QGraphicsRectItem 选择矩形作为碰撞检测的基类，在通过重绘制方法实现绘制不同形状
 */

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
