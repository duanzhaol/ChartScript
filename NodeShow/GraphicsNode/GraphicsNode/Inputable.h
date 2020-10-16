#ifndef INPUTPORTINTERFACE_H
#define INPUTPORTINTERFACE_H

#include <QPushButton>
#include <QGraphicsItem>
#include <QGraphicsProxyWidget>
#include "AbstractGraphicsNode.h"

/**
 * @interface
 */

using InputPort = QWidget;

class Inputable{
public:

	Inputable();

    virtual QPointF getInputPortCoordinate(QGraphicsItem* item)=0;
	virtual InputPort* getInputPort() = 0;



};

#endif // INPUTPORTINTERFACE_H
