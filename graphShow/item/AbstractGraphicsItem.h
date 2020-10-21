#ifndef ABSTRACTGRAPHICSITEM_H
#define ABSTRACTGRAPHICSITEM_H

#include <QGraphicsSceneMouseEvent>
#include <QObject>
#include <QDebug>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include "../ChartAttribute.h"
#include <QGraphicsEllipseItem>
#include <QAbstractGraphicsShapeItem>
#include <QChart>
#include <QGraphicsScene>



template <class GraphicsItem>
class AbstractGraphicsItem:public GraphicsItem
{
public:

public:
	/**
	 *构造函数，设置了这个对象是可选择，可移动，可focus?,可改变大小，接受hover事件的
	 * 同时设置m_bIsResizing为0，创建了8个缩放用的小圆圈，但是这些圆圈目前是不可见的，被选中后可见
	 */
	AbstractGraphicsItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr);

	AbstractGraphicsItem(QGraphicsItem*parent);


	//! 设置图形位置
	virtual void setCoordinate(const QRectF&pos) = 0;

protected:

	/**
	* 打开属性窗口的槽函数
	* @bug 会报错，信号发不过来，因此属性窗口无法产生实质性的改变
	*/
	virtual void SLOT_openAttributeWidget() = 0;

	/**
	 * @brief
	 * 鼠标点击事件，如果是左键，判断是否在某个item的区域内，如果是改变m_bIsResizing为对应的类型
	 * 如果此时按了ctrl，则设置为选中，并忽略这个事件（然后这个事件会被传播到scene中）
	 * 如果没有键盘事件，则发生单次的选中
	 * 如果是右键，则忽略该事件
	 * @param event
	 */
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	/**
	 * @brief
	 * 鼠标移动事件（点击后才会触发）
	 * 如果正在进行缩放，通过getNewPlace()获取到缩放后的正方形,然后通过setGeometry（）改变item的大小
	 * @param 接受到的鼠标移动事件，调用->pos()可以获得到鼠标移动后的坐标
	 */
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	/**
	 * @brief
	 * 鼠标释放事件
	 * 如果释放的是左键且正在缩放，释放后退出缩放状态
	 * @param event
	 */
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
	/**
	 * @brief
	 * hover事件
	 * 通过IsInResizeArea(event->pos())获取鼠标位于那个缩放点上，返回对应的type，并根据对应的type设置不同的cursor
	 * @param event
	 * hover事件，可根据pos()获取鼠标位置
	 */
	void hoverMoveEvent(QGraphicsSceneHoverEvent* event);
	/**
	 * @brief
	 * 双击事件，弹出窗口
	 * @param event
	 */
	void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event);

protected:
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
	* @brief 存储设定的选择框颜色
	*/
   void setCircleColor(QColor color);



	// QGraphicsItem interface
public:
   /**
	* @brief
	* 返回的结果好像不太对，但是能用，不晓得为什么，这里以后可能会出现问题（碰撞检测等）
	* @return 返回边界的矩形
	*/
	QRectF boundingRect() const;
protected:

	/**
	 * @brief
	 * 画图函数，每次发生改变都会调用这个函数。这里主要实现了被选中后的绘图事件
	 * 同时设置了默认的选择框颜色
	 * @param painter 不懂
	 * @param option 不懂
	 * @param widget 不懂
	 */
	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
			   QWidget *widget);


	QVariant itemChange(typename GraphicsItem::GraphicsItemChange change, const QVariant &value)override;
};


template<class GraphicsItem>
AbstractGraphicsItem<GraphicsItem>::AbstractGraphicsItem
(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent):
	GraphicsItem (x,y,width,height,parent)
{
	setFlags(QGraphicsItem::ItemIsSelectable|
			 QGraphicsItem::ItemIsMovable|
			 QGraphicsItem::ItemSendsGeometryChanges|
			 QGraphicsItem::ItemIsFocusable);//设定选型

	setAcceptHoverEvents(true);//接受hover事件
	m_bIsResizing=0;
	creatCircle();
}

template<class GraphicsItem>
AbstractGraphicsItem<GraphicsItem>::AbstractGraphicsItem(QGraphicsItem *parent):
	GraphicsItem (parent)
{
	setFlags(QGraphicsItem::ItemIsSelectable|
			 QGraphicsItem::ItemIsMovable|
			 QGraphicsItem::ItemSendsGeometryChanges|
			 QGraphicsItem::ItemIsFocusable);//设定选型

	setAcceptHoverEvents(true);//接受hover事件
	m_bIsResizing=0;
	creatCircle();
}

template<class GraphicsItem>
void AbstractGraphicsItem<GraphicsItem>::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	qDebug()<<event;
	if(event->button() == Qt::LeftButton){
		int type=IsInResizeArea(event->pos());
		if(type!=0){
			m_bIsResizing = type;//在区域中按了左键，进入改变大小的状态
			qDebug() <<"调整大小中";
			event->accept();

		}else if(event->modifiers() == Qt::ControlModifier){
			event->ignore();
			setSelected(true);
			qDebug() <<"左键点击选中了一个chart！";
			QGraphicsItem::mousePressEvent(event);
		}else{
			setSelected(true);
			//setGeometry(geometry().adjusted(30,5,0,0));

			qDebug() <<"左键点击选中了一个chart！";
			QGraphicsItem::mousePressEvent(event);
			event->accept();
		}
	}else if(event->button() == Qt::RightButton){
		//显示属性窗口
		qDebug() << "右键了一个chart";
		event->ignore();
	}
}



template<class GraphicsItem>
void AbstractGraphicsItem<GraphicsItem>::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	if (m_bIsResizing)
	{
		QRectF newPlace=getNewPlace(m_bIsResizing,pos(),event->pos());
		newPlace=mapFromScene(newPlace).boundingRect();
		setCoordinate(newPlace);//改变大小
	}
	else
	{
		QGraphicsItem::mouseMoveEvent(event);
	}
}

template<class GraphicsItem>
void AbstractGraphicsItem<GraphicsItem>::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	if (event->button() == Qt::LeftButton && (m_bIsResizing!=0))
		m_bIsResizing = 0;//松开后不再改变大小状态
	else
		QGraphicsItem::mouseReleaseEvent(event);
}

template<class GraphicsItem>
void AbstractGraphicsItem<GraphicsItem>::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
	int type=IsInResizeArea(event->pos());
	//qDebug()<<type;
	if (m_bIsResizing || (type!=0) && isSelected()){
		switch (type) {
		case 31:
			setCursor(Qt::SizeBDiagCursor);
			break;
		case 32:
			setCursor(Qt::SizeVerCursor);
			break;
		case 33:
			setCursor(Qt::SizeFDiagCursor);//如果在对应的区域里且是选中状态，则改变指针样式
			break;
		case 21:
			setCursor(Qt::SizeHorCursor);
			break;
		case 23:
			setCursor(Qt::SizeHorCursor);
			break;
		case 11:
			setCursor(Qt::SizeFDiagCursor);
			break;
		case 12:
			setCursor(Qt::SizeVerCursor);
			break;
		case 13:
			setCursor(Qt::SizeBDiagCursor);
			break;
		default:
			setCursor(Qt::ArrowCursor);
			break;
		}
	}
	else{
		setCursor(Qt::ArrowCursor);

	}
	QGraphicsItem::hoverMoveEvent(event);
}

template <class GraphicsItem>
void AbstractGraphicsItem<GraphicsItem>::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
	qDebug()<<"双击";
	SLOT_openAttributeWidget();
}

template <class GraphicsItem>
void AbstractGraphicsItem<GraphicsItem>::creatCircle()
{
	QRectF rect=QRectF(0,0,10,10);
	circle11=new QGraphicsEllipseItem(rect,this);
	circle11->setVisible(false);
	circle12=new QGraphicsEllipseItem(rect,this);
	circle12->setVisible(false);
	circle13=new QGraphicsEllipseItem(rect,this);
	circle13->setVisible(false);
	circle21=new QGraphicsEllipseItem(rect,this);
	circle21->setVisible(false);
	circle23=new QGraphicsEllipseItem(rect,this);
	circle23->setVisible(false);
	circle31=new QGraphicsEllipseItem(rect,this);
	circle31->setVisible(false);
	circle32=new QGraphicsEllipseItem(rect,this);
	circle32->setVisible(false);
	circle33=new QGraphicsEllipseItem(rect,this);
	circle33->setVisible(false);
}

template <class GraphicsItem>
void AbstractGraphicsItem<GraphicsItem>::setCircleVisible(bool vis)
{
	if(circle11->isVisible() == vis){
		return;
	}

	circle11->setVisible(vis);
	circle12->setVisible(vis);
	circle13->setVisible(vis);
	circle21->setVisible(vis);
	circle23->setVisible(vis);
	circle31->setVisible(vis);
	circle32->setVisible(vis);
	circle33->setVisible(vis);

}

template <class GraphicsItem>
void AbstractGraphicsItem<GraphicsItem>::setCirclePos()
{
	double radius=5;//小圆圈的半径
	QRectF circleRect=QRectF(0,0,2*radius,2*radius);//决定圆形的矩形
	double width=boundingRect().width();
	double height=boundingRect().height();
	circle11->setRect(circleRect.adjusted(-radius,-radius,-radius,-radius));
	circle12->setRect(circleRect.adjusted(width/2-radius,-radius,width/2-radius,-radius));
	circle13->setRect(circleRect.adjusted(width-radius,-radius,width-radius,-radius));
	circle21->setRect(circleRect.adjusted(-radius,height/2-radius,-radius,height/2-radius));//21
	circle23->setRect(circleRect.adjusted(width-radius,height/2-radius,width-radius,height/2-radius));//23
	circle31->setRect(circleRect.adjusted(-radius,height-radius,-radius,height-radius));//31
	circle32->setRect(circleRect.adjusted(width/2-radius,height-radius,width/2-radius,height-radius));//32
	circle33->setRect(circleRect.adjusted(width-radius,height-radius,width-radius,height-radius));//33
}

template <class GraphicsItem>
int AbstractGraphicsItem<GraphicsItem>::IsInResizeArea(const QPointF &pos)
{
	int radius=10;
	if(abs(pos.x()-boundingRect().width())<=radius){
		if(abs(pos.y()-boundingRect().height())<=radius){
			return 33;
		}else if(abs(pos.y()-boundingRect().height()/2)<=radius){
			return 23;
		}else if(abs(pos.y())<=radius){
			return 13;
		}
	}else if(abs(pos.x()-boundingRect().width()/2)<=radius){
		if(abs(pos.y()-boundingRect().height())<=radius){
			return 32;
		}else if(abs(pos.y())<=radius){
			return 12;
		}
	}else if(abs(pos.x())<=radius){
		if(abs(pos.y()-boundingRect().height())<=radius){
			return 31;
		}else if(abs(pos.y()-boundingRect().height()/2)<=radius){
			return 21;
		}else if(abs(pos.y())<=radius){
			return 11;
		}
	}
	return 0;
}

template <class GraphicsItem>
QRectF AbstractGraphicsItem<GraphicsItem>::getNewPlace(int type, QPointF LT, QPointF RB)
{
	QRectF re=*new QRectF(0,0,0,0);
	qreal x=LT.x();
	qreal y=LT.y();
	qreal w=RB.x();
	qreal h=RB.y();
	switch (type) {
	case 31:
		re.setRect(x+w,y,boundingRect().width()-w,h);
		//qDebug()<<boundingRect().width()<<" "<<w<<" "<<x;
		break;
	case 32:
		re.setRect(x,y,boundingRect().width(),h);
		break;
	case 33:
		re.setRect(x,y,w,h);
		break;
	case 21:
		re.setRect(x+w,y,boundingRect().width()-w,boundingRect().height());
		break;
	case 23:
		re.setRect(x,y,w,boundingRect().height());
		break;
	case 11:
		re.setRect(x+w,y+h,boundingRect().width()-w,boundingRect().height()-h);
		break;
	case 12:
		re.setRect(x,y+h,boundingRect().width(),boundingRect().height()-h);
		break;
	case 13:
		re.setRect(x,y+h,w,boundingRect().height()-h);
		break;
	default:
		break;
	}
	return re;
}

template <class GraphicsItem>
void AbstractGraphicsItem<GraphicsItem>::setCircleColor(QColor color)
{
	circle11->setBrush(color);
	circle12->setBrush(color);
	circle13->setBrush(color);
	circle21->setBrush(color);
	circle23->setBrush(color);
	circle31->setBrush(color);
	circle32->setBrush(color);
	circle33->setBrush(color);
}

template <class GraphicsItem>
QRectF AbstractGraphicsItem<GraphicsItem>::boundingRect() const
{
	return GraphicsItem::boundingRect();
}


template <class GraphicsItem>
void AbstractGraphicsItem<GraphicsItem>::paint
(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	//GraphicsItem::paint(painter,option,widget);

	prepareGeometryChange();
	QStyleOptionGraphicsItem op;
	if (option->state & QStyle::State_Selected) {//如果被选中的话
		setCircleVisible(true);
		setCirclePos();
	}else{
		setCircleVisible(false);
	}
}

template <class GraphicsItem>
QVariant AbstractGraphicsItem<GraphicsItem>::itemChange
(typename GraphicsItem::GraphicsItemChange change, const QVariant &value)
{
	if (change == ItemPositionChange && scene()) {
		// value is the new position.
		QPointF newPos = value.toPointF();
		QRectF rect = scene()->sceneRect();
		if (!rect.contains(newPos)) {
			// Keep the item inside the scene rect.
			newPos.setX(qMin(rect.right(), qMax(newPos.x(), rect.left())));
			newPos.setY(qMin(rect.bottom(), qMax(newPos.y(), rect.top())));
			return newPos;
		}
	}
	return GraphicsItem::itemChange(change, value);
}

#endif // ABSTRACTGRAPHICSITEM_H
