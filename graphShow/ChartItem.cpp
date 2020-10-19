
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
	prepareGeometryChange();
	QStyleOptionGraphicsItem op;
	if (option->state & QStyle::State_Selected) {//如果被选中的话
		painter->setRenderHint(QPainter::Antialiasing, true);

		double radius=5;//小圆圈的半径
		setCircleVisible(true);
		setCirclePos();
		painter->drawRect(boundingRect().adjusted(radius,radius,0,0));

		painter->setRenderHint(QPainter::Antialiasing, false);  // 重点
	}else{
		setCircleVisible(false);
	}
}



void ChartItem::setAttr()
{
	this->setTitle("abc");
	//this->setDropShadowEnabled(true);//背景阴影
	this->setBackgroundVisible(true);
	//ca->close();
}

void ChartItem::SLOT_openAttributeWidget()
{
}




void ChartItem::setCoordinate(const QRectF &pos)
{
	setGeometry(pos);
}
