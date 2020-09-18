#ifndef MOVABLEDUALPORTPROXYWIDGET_H
#define MOVABLEDUALPORTPROXYWIDGET_H

#include "MovableSinglePortProxyWidget.h"
#include "OutputPortInterface.h"

class MovableDualPortProxyWidget:public MovableSinglePortProxyWidget,public OutputPortInterface
{
public:
	MovableDualPortProxyWidget();

	// OutputPortInterface interface
public:
	virtual OutputPortType *getOutputPort() override;
	virtual QPointF getOutputPortCoordinate(const QGraphicsItem *item) override;
};





#endif // MOVABLEDUALPORTPROXYWIDGET_H
