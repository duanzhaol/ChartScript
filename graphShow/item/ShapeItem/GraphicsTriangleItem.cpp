#include "GraphicsTriangleItem.h"
#include <QPolygon>



GraphicsTriangleItem::GraphicsTriangleItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent):
	AbstractGraphicsShapeItem(x,y,width,height,parent)
{

}

void GraphicsTriangleItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	AbstractGraphicsShapeItem::paint(painter,option,widget);
	QRectF rect = boundingRect();
	QVector<QPointF> points;
	points<<rect.bottomLeft()<<rect.bottomRight()<<(rect.topLeft()+rect.topRight())/2;
	painter->drawPolygon(QPolygonF(points));
}
