#ifndef INPUTPORTINTERFACE_H
#define INPUTPORTINTERFACE_H

#include <QPushButton>
#include <QGraphicsItem>
#include <QGraphicsProxyWidget>
#include "PortWidget.h"

using InputPort = QWidget;

class InputPortWidget{
public:

	InputPortWidget();

    virtual QPointF getInputPortCoordinate(QGraphicsItem* item)=0;
	virtual InputPort* getInputPort() = 0;



};

#endif // INPUTPORTINTERFACE_H
