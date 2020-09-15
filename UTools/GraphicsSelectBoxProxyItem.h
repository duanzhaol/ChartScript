#ifndef GRAPHICSSELECTBOXPROXYITEM_H
#define GRAPHICSSELECTBOXPROXYITEM_H

#include<QChart>

/**
 * @brief The GraphicsSelectBoxProxyItem class
 */

class GraphicsSelectBoxProxyItem:public QGraphicsWidget{
	Q_OBJECT
	QGraphicsWidget*item;
public:

	void setItem(QGraphicsWidget*item);

	/**
	 * @brief
	 *构造函数，设置了这个对象是可选择，可移动，可focus?,可改变大小，接受hover事件的
	 * 同时设置m_bIsResizing为0，创建了8个缩放用的小圆圈，但是这些圆圈目前是不可见的，被选中后可见
	 */
	GraphicsSelectBoxProxyItem();
	/**
	 * @brief
	 * 画图函数，每次发生改变都会调用这个函数。这里主要实现了被选中后的绘图事件
	 * 同时设置了默认的选择框颜色
	 * @param painter 不懂
	 * @param option 不懂
	 * @param widget 不懂
	 */
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
			   QWidget *widget) override;

protected:
	/**
	 * @brief
	 * 鼠标点击事件，如果是左键，判断是否在某个item的区域内，如果是改变m_bIsResizing为对应的类型
	 * 如果此时按了ctrl，则设置为选中，并忽略这个事件（然后这个事件会被传播到scene中）
	 * 如果没有键盘事件，则发生单次的选中
	 * 如果是右键，则忽略该事件
	 * @param event
	 */
	void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
	/**
	 * @brief
	 * 鼠标移动事件（点击后才会触发）
	 * 如果正在进行缩放，通过getNewPlace()获取到缩放后的正方形,然后通过setGeometry（）改变item的大小
	 * @param 接受到的鼠标移动事件，调用->pos()可以获得到鼠标移动后的坐标
	 */
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
	/**
	 * @brief
	 * 鼠标释放事件
	 * 如果释放的是左键且正在缩放，释放后退出缩放状态
	 * @param event
	 */
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
	/**
	 * @brief
	 * hover事件
	 * 通过IsInResizeArea(event->pos())获取鼠标位于那个缩放点上，返回对应的type，并根据对应的type设置不同的cursor
	 * @param event
	 * hover事件，可根据pos()获取鼠标位置
	 */
	void hoverMoveEvent(QGraphicsSceneHoverEvent* event) override;
	/**
	 * @brief
	 * 双击事件，弹出窗口
	 * @param event
	 */
	void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) override;
private:
	/**
	 * @brief 缩放用的圆圈
	 */
	QGraphicsEllipseItem* circle11;
	QGraphicsEllipseItem* circle12;
	QGraphicsEllipseItem* circle13;
	QGraphicsEllipseItem* circle21;
	QGraphicsEllipseItem* circle23;
	QGraphicsEllipseItem* circle31;
	QGraphicsEllipseItem* circle32;
	QGraphicsEllipseItem* circle33;
	/**
	 * @brief
	 * 创建缩放用圆圈，初始都创建在左上角，设置不可见
	 */
	void creatCircle();
	/**
	 * @brief C
	 * 设置小圆圈是可见/不可见的
	 * @param vis
	 * 是否可见
	 */
	void setCircleVisible(bool vis);
	/**
	 * @brief
	 * 设置小圆圈的位置
	 */
	void setCirclePos();
	/**
	 * @brief
	 * 判断当前这个点是否在某个小圆圈上
	 * @param pos
	 * 需要判断的点的坐标
	 * @return
	 * 鼠标位于缩放小圆圈的类型
	 * 0---不处于任何一个小圆圈上
	 * 11，12，13---第一行
	 * 21，23---第二行
	 * 31，32，33--第三行
	 */
	int IsInResizeArea(const QPointF& pos); //检测鼠标是否在重设大小的取悦
	/**
	 * @brief 是否在缩放的过程中，不在是0，在则是对应的类型值
	 */
	int m_bIsResizing;//
	/**
	 * @brief
	 * 获得缩放后的矩形，根据输入的三个参数进行计算
	 * @param type
	 * 缩放的类型（点击的哪个小圆圈开始）
	 * @param LT
	 * 矩形原来左上角的坐标
	 * @param RB
	 * 缩放结束后鼠标的坐标
	 * @return
	 * 缩放后的矩形边界
	 */
	QRectF getNewPlace(int type,QPointF LT,QPointF RB);
	/**
	 * @brief 属性窗口ui对象的引用
	 */

	/**
	 * @brief 存储设定的选择框颜色
	 */
	QColor selectColor;
	/**
	 * @brief 存储设定的缩放小圆圈颜色
	 */
	QColor zoomColor;
	/**
	 * @brief 根据传入的颜色，设定所有小圆圈的颜色
	 * @param 改变的颜色
	 */
	void setCircleColor(QColor color);

	// QGraphicsItem interface
public:
	virtual QRectF boundingRect() const override;

};





#endif // GRAPHICSSELECTBOXPROXYITEM_H
