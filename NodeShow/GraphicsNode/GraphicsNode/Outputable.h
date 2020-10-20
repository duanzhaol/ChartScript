#ifndef OUTPUTPORTINTERFACE_H
#define OUTPUTPORTINTERFACE_H

#include "AbstractGraphicsNode.h"
#include "OutputPort.h"

#include <QPushButton>
#include <QGraphicsItem>
#include <QGraphicsProxyWidget>

/**
 * @interface
 */

//using OutputPort = QWidget;

class Outputable{
public:

	Outputable();

    virtual QPointF getOutputPortCoordinate(QGraphicsItem* item)=0;
	virtual OutputPort* getOutputPort() = 0;

};
#endif // OUTPUTPORTINTERFACE_H
