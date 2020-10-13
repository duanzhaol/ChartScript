#ifndef OUTPUTPORTINTERFACE_H
#define OUTPUTPORTINTERFACE_H

#include "PortWidget.h"

#include <QPushButton>
#include <QGraphicsItem>
#include <QGraphicsProxyWidget>

using OutputPort = QWidget;

class OutputPortWidget{
public:

	OutputPortWidget();

    virtual QPointF getOutputPortCoordinate(QGraphicsItem* item)=0;
	virtual OutputPort* getOutputPort() = 0;

};
#endif // OUTPUTPORTINTERFACE_H
