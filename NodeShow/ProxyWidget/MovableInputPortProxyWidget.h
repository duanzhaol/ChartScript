#ifndef MovableSinglePortProxyWidget_H
#define MovableSinglePortProxyWidget_H

#include "MovableProxyWidget.h"
#include "GraphicsDataNode.h"
#include "InputPortWidget.h"

class MovableInputPortProxyWidget :virtual public MovableProxyWidget{
    QWidget* widget()const;
public:
	MovableInputPortProxyWidget();
	void setInputPortWidget(InputPortWidget*node);
	void setWidget(QWidget*node) = delete;


	InputPortWidget* getInputPortWidget();

    InputPort*getInputPort();


	// InputPortInterface interface
public:
	QPointF getInputPortCoordinate(const QGraphicsItem *item);
};

#endif // MovableSinglePortProxyWidget_H
