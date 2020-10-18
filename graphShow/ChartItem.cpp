
#include "ChartItem.h"
#include<QComboBox>
#include<QGraphicsSceneMouseEvent>
#include<QDebug>
#include<QPointF>
#include<QPainter>
#include<QRectF>
#include<QStyleOptionGraphicsItem>
#include<QGraphicsLayout>
#include<QWidget>
#include "ui_chartattribute.h"


ChartItem::ChartItem(QGraphicsItem *parent):
	AbstractGraphicsItem(parent)
{   


}

//QRectF ChartItem::boundingRect() const
//{
//     auto a=QGraphicsWidget::boundingRect();
//     qDebug()<<a;
//     return a;
//   // qDebug()<<plotArea();
//   // qDebug()<<this->layout()->geometry();
//   // return this->layout()->geometry();
//}

void ChartItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	//QChart::paint(0,0,widget);
	prepareGeometryChange();
	//qDebug("调用MyChartItem::paint");
	QStyleOptionGraphicsItem op;
	if (option->state & QStyle::State_Selected) {//如果被选中的话
		//qDebug("画边框");
		//qDebug()<<geometry();
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

		//painter->setPen(QPen(Qt::black,1,Qt::SolidLine));//在这里调整边框的颜色及线条粗细
		double radius=5;//小圆圈的半径
		setCircleVisible(true);
		setCirclePos();
		painter->drawRect(boundingRect().adjusted(radius,radius,0,0));

		//        qreal w = boundingRect().width();
		//        qreal h =boundingRect().height();
		painter->setPen(Qt::red);
		//        for (int i = 0; i < 3; ++i)
		//            painter->drawLine(w - g_cResizePos[i], h, w, h - g_cResizePos[i]);   //画右下角的小三角形
		painter->setRenderHint(QPainter::Antialiasing, false);  // 重点
	}else{
		setCircleVisible(false);
	}
}



void ChartItem::setAttr()
{
	AbstractGraphicsItem::setAttr();
	this->setTitle("abc");
	//this->setDropShadowEnabled(true);//背景阴影
	this->setBackgroundVisible(true);
	//ca->close();
}

void ChartItem::SLOT_openAttributeWidget()
{
	AbstractGraphicsItem::SLOT_openAttributeWidget();
	this->connect(attr,&ChartAttribute::confirm,
				  this,& ChartItem ::setAttr);
}




void ChartItem::setCoordinate(const QRectF &pos)
{
	setGeometry(pos);
}
