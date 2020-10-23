#ifndef MOVABLEPROXYWIDGET_H
#define MOVABLEPROXYWIDGET_H
#include <QGraphicsProxyWidget>
/**
 * @brief
 * 图节点模块的移动代理类。
 * 通过代理各个图节点，使其能够在编程模块中移动
 */
class MovableProxyWidget:public QGraphicsProxyWidget
{
	Q_OBJECT
public:
	MovableProxyWidget();


    // QGraphicsItem interface
protected:
	virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
	virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
public:
	void setWidget(QWidget*widget);
private:
	QPointF coordinateDifference;

};



#endif // MOVABLEPROXYWIDGET_H
