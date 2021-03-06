#include "ConnectLineItem.h"
#include"Interpreter/Interpreter/InterpreterController.h"
#include "Interpreter/GraphicsNodeInterface/GraphicsNodeInterface.h"
#include "../GraphicsNode/ConnectController.h"
#include <QDebug>
#include <QPainter>


ConnectLineItem::ConnectLineItem(Inputable *inputNode,
                                 Outputable *outputNode)
    :inputNode(inputNode),
      outputNode(outputNode)
{

	setFlags(QGraphicsItem::ItemIsSelectable|
			 QGraphicsItem::ItemIsMovable|
			 QGraphicsItem::ItemSendsGeometryChanges|
			 QGraphicsItem::ItemIsFocusable);//设定选型

}

QRectF ConnectLineItem::boundingRect() const
{
	return shape().controlPointRect();
}


QPainterPath ConnectLineItem::shape() const
{
	QPainterPath path = QGraphicsPolygonItem::shape();
	path.addPolygon(mArrow);
	return path;
}

#include <NodeShowWindow.h>
#include <QDebug>
#include <QMessageBox>


void ConnectLineItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(option)
	Q_UNUSED(widget)

	//  painter->setPen(QPen(Qt::blue,5));



	QPointF left = outputNode->getOutputPortCoordinate(this);
	QPointF right = inputNode->getInputPortCoordinate(this);

	//qDebug()<<left<<right;

	mArrow.clear();
    double par = 25;//箭头部分三角形的腰长12
	double slopy = atan2((right.y() - left.y()), (right.x() - left.x()));
	double cosy = cos(slopy);
	double siny = sin(slopy);
    QPointF point1 = QPointF(right.x() + int(-par*cosy - (par / 2.0*siny)),
							right.y() + int(-par*siny + (par / 2.0*cosy)));

    QPointF point2 = QPointF(right.x() + int(-par*cosy + (par / 2.0*siny)),
							right.y() - int(par / 2.0*cosy + par*siny));

	QPointF points[3] = { right, point1, point2 };
	painter->setRenderHint(QPainter::Antialiasing, true);//消锯齿
	painter->setBrush(QBrush(QColor(94,167,255,255)));
	painter->setPen(QPen(QColor(94,167,255,255)));

	int offsetX = int(par*siny / 3);
	int offsetY = int(par*cosy / 3);

    QPointF point3, point4;
    point3 = QPointF(right.x() + int(-par*cosy - (par / 2.0*siny)) + offsetX,
					right.y() + int(-par*siny + (par / 2.0*cosy)) - offsetY);

    point4 = QPointF(right.x() + int(-par*cosy + (par / 2.0*siny) - offsetX),
					right.y() - int(par / 2.0*cosy + par*siny) + offsetY);

	mArrow<<right<<point1<<point3<<left<<point4<<point2;
	QPointF arrowBodyPoints[3]= { left, point3, point4 };
	painter->drawPolygon(points, 3);//绘制箭头部分
	painter->drawPolygon(arrowBodyPoints, 3);//绘制箭身部分
	QGraphicsPolygonItem::paint(painter,option,widget);
}




void ConnectLineItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug()<<"aha";
    if(NodeShowWindow::getInstance()->mouseType==NodeShowWindow::NodeShowMouseType::Delete){
        emit LineClickedWithDele(this);
    }

}






