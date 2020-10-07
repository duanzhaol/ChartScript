#ifndef MOVABLEOUTPUTPORTPROXYWIDGET_H
#define MOVABLEOUTPUTPORTPROXYWIDGET_H
#include "OutputPortWidget.h"
#include "MovableProxyWidget.h"

class MovableOutputPortProxyWidget:virtual public MovableProxyWidget{
	QWidget* widget()const;
public:
	MovableOutputPortProxyWidget();
	void setOutputPortWidget(OutputPortWidget*node);
	void setWidget(QWidget*node) = delete;


	OutputPortWidget* getOutputPortWidget();

	OutputPort*getOutputPort();


	// InputPortInterface interface
public:
	QPointF getOutputPortCoordinate(const QGraphicsItem *item);
};

#endif // MOVABLEOUTPUTPORTPROXYWIDGET_H
