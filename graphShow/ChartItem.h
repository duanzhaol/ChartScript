#ifndef CHARTITEM_H
#define CHARTITEM_H
#include<QChart>
#include "item/AbstractGraphicsItem.h"

/**
 * @brief The ChartItem class
 * 继承自QChart，在QChart的基础上增加了拖拽，缩放，选择等功能，使用方法和QChart相同
 */

class ChartItem:public AbstractGraphicsItem<QtCharts::QChart>
{
    Q_OBJECT
public:
    /**
     * @brief
     *构造函数，设置了这个对象是可选择，可移动，可focus?,可改变大小，接受hover事件的
     * 同时设置m_bIsResizing为0，创建了8个缩放用的小圆圈，但是这些圆圈目前是不可见的，被选中后可见
     */
	ChartItem(QGraphicsItem*parent = nullptr);
    /**
     * @brief
     * 返回的结果好像不太对，但是能用，不晓得为什么，这里以后可能会出现问题（碰撞检测等）
     * @return 返回边界的矩形
     */
    //QRectF boundingRect() const;
    /**
     * @brief
     * 画图函数，每次发生改变都会调用这个函数。这里主要实现了被选中后的绘图事件
     * 同时设置了默认的选择框颜色
     * @param painter 不懂
     * @param option 不懂
     * @param widget 不懂
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
     /**
     * @brief ChartItem::SLOT_openAttributeWidget
     * 打开属性窗口的槽函数
     * @bug 会报错，信号发不过来，因此属性窗口无法产生实质性的改变
     */
    void SLOT_openAttributeWidget();


private slots:
    /**
     * @brief 属性窗口点击确定的槽函数
     * 会根据combox的选项，设定对应的属性
     * 选择框颜色的设定方式：改变私有属性selectColor,然后再paint种调用这个属性
     * 圆圈的颜色谁的设定方式:调用setCircleColor函数
     */
    void setAttr();


	// AbstractGraphicsItem interface
protected:
	virtual void setCoordinate(const QRectF &pos) override;
};

template<>
inline void AbstractGraphicsItem<QtCharts::QChart>::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	if (m_bIsResizing)
	{
		QRectF newPlace=getNewPlace(m_bIsResizing,pos(),event->pos());
		setCoordinate(newPlace);//改变大小
	}
	else
	{
		QGraphicsItem::mouseMoveEvent(event);
	}
}


#endif // CHARTITEM_H
