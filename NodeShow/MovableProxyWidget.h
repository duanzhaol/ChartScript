#ifndef MOVABLEPROXYWIDGET_H
#define MOVABLEPROXYWIDGET_H
#include <QGraphicsProxyWidget>

class MovableProxyWidget:public QGraphicsProxyWidget
{
	Q_OBJECT
public:
	MovableProxyWidget();


    // QGraphicsItem interface
protected:
	virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
	virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

private:
	QPointF coordinateDifference;

};



#endif // MOVABLEPROXYWIDGET_H
