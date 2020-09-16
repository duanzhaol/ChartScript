#include "GraphicsSelectBoxProxyItem.h"
#include<QComboBox>
#include<QGraphicsSceneMouseEvent>
#include<QDebug>
#include<QPointF>
#include<QPainter>
#include<QRectF>
#include<QStyleOptionGraphicsItem>
#include<QGraphicsLayout>
#include <QApplication>
#include<QWidget>


void GraphicsSelectBoxProxyItem::setItem(MovableProxyWidget *item)
{
	this->item = item;
    resize(item->boundingRect().width(),item->boundingRect().height());
}

GraphicsSelectBoxProxyItem::GraphicsSelectBoxProxyItem()
{
	setFlags(QGraphicsItem::ItemIsSelectable|
				 QGraphicsItem::ItemIsMovable|
				 QGraphicsItem::ItemSendsGeometryChanges|
				 QGraphicsItem::ItemIsFocusable);//设定选型
	setAcceptHoverEvents(true);//接受hover事件
	m_bIsResizing=0;
	creatCircle();


}

void GraphicsSelectBoxProxyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

	this->item->paint(painter,option,widget);

	prepareGeometryChange();

	QStyleOptionGraphicsItem op;
	if (option->state & QStyle::State_Selected) {//如果被选中的话
		painter->setRenderHint(QPainter::Antialiasing, true);
		if (option->state & QStyle::State_HasFocus)
					painter->setPen(Qt::yellow);//我也不知道这是干啥的
				else{
			if(selectColor==nullptr){
				painter->setPen(Qt::blue);//设置默认选择框颜色
			 }else{
				painter->setPen(selectColor);//设置默认选择框颜色
			}
		}

		double radius=5;//小圆圈的半径
		setCircleVisible(true);
		setCirclePos();
		painter->drawRect(boundingRect().adjusted(radius,radius,0,0));

		painter->setPen(Qt::red);
		painter->setRenderHint(QPainter::Antialiasing, false);  // 重点
	}
	else{
		setCircleVisible(false);
	}
}



void GraphicsSelectBoxProxyItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
		int type=IsInResizeArea(event->pos());
		if(type!=0){
			m_bIsResizing = type;
			event->accept();

		}else if(event->modifiers() == Qt::ControlModifier){
			event->ignore();
			setSelected(true);
			QGraphicsItem::mousePressEvent(event);
		}else{
			setSelected(true);
			QGraphicsItem::mousePressEvent(event);
			event->accept();
		}
	}else if(event->button() == Qt::RightButton){
		event->ignore();
	}
}

void GraphicsSelectBoxProxyItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	if (m_bIsResizing)
	   {
			QRectF newPlace=getNewPlace(m_bIsResizing,pos(),event->pos());
			this->setGeometry(newPlace);
			item->setGeometry(newPlace);
		}
		else
		{
			QGraphicsItem::mouseMoveEvent(event);
		}
}

void GraphicsSelectBoxProxyItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	if (event->button() == Qt::LeftButton && (m_bIsResizing!=0))
			m_bIsResizing = 0;//松开后不再改变大小状态
		else
			QGraphicsItem::mouseReleaseEvent(event);
}

void GraphicsSelectBoxProxyItem::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
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
#include <QMessageBox>

void GraphicsSelectBoxProxyItem::creatCircle()
{


    auto createACircle = [this](CircleType*&circle){
        static QRectF rect=QRectF(0,0,10,10);
        circle = new CircleType(rect,this);
        circle->setVisible(false);
    };

    createACircle(circle11);
    createACircle(circle12);
    createACircle(circle13);
    createACircle(circle21);
    createACircle(circle23);
    createACircle(circle31);
    createACircle(circle32);
    createACircle(circle33);

}

void GraphicsSelectBoxProxyItem::setCircleVisible(bool vis)
{
	if(vis){
		if(circle11->isVisible())
			return;
        circle11->setVisible(true);
                circle12->setVisible(true);
		circle13->setVisible(true);
		circle21->setVisible(true);
		circle23->setVisible(true);
		circle31->setVisible(true);
		circle32->setVisible(true);
		circle33->setVisible(true);
	}else{
		if(!circle11->isVisible())
			return;
		circle11->setVisible(false);
		circle12->setVisible(false);
		circle13->setVisible(false);
		circle21->setVisible(false);
		circle23->setVisible(false);
		circle31->setVisible(false);
		circle32->setVisible(false);
		circle33->setVisible(false);
	}
}

void GraphicsSelectBoxProxyItem::setCirclePos()
{
    int radius=5;//小圆圈的半径
    QRect circleRect=QRect(0,0,2*radius,2*radius);//决定圆形的矩形
	double width=this->boundingRect().right();
	double height=this->boundingRect().bottom();
    circle11->setRect(circleRect.adjusted(0,0,0,0));
    circle12->setRect(circleRect.adjusted(width/2-radius,0,width/2-radius,0));
    circle13->setRect(circleRect.adjusted(width-radius,0,width-radius,0));
    circle21->setRect(circleRect.adjusted(0,height/2-radius,0,height/2-radius));//21
    circle23->setRect(circleRect.adjusted(width-radius,height/2-radius,width-radius,height/2-radius));//23
    circle31->setRect(circleRect.adjusted(0,height-radius,0,height-radius));//31
    circle32->setRect(circleRect.adjusted(width/2-radius,height-radius,width/2-radius,height-radius));//32
    circle33->setRect(circleRect.adjusted(width-radius,height-radius,width-radius,height-radius));//33

}

int GraphicsSelectBoxProxyItem::IsInResizeArea(const QPointF &pos)
{
	int radius=5;
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

QRectF GraphicsSelectBoxProxyItem::getNewPlace(int type, QPointF LT, QPointF RB)
{

	QRectF re=QRectF(0,0,0,0);
	qreal x=LT.x();
	qreal y=LT.y();
	qreal w=RB.x();
	qreal h=RB.y();
	switch (type) {
	case 31:
		re.setRect(x+w,y,boundingRect().width()-w,h);
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

void GraphicsSelectBoxProxyItem::setCircleColor(QColor color)
{


}

QRectF GraphicsSelectBoxProxyItem::boundingRect() const
{
	return item->boundingRect();
}
