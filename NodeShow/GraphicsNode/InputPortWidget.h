#ifndef INPUTPORTINTERFACE_H
#define INPUTPORTINTERFACE_H

#include <QPushButton>
#include <QGraphicsItem>
#include "PortWidget.h"

using InputPort = QWidget;

class InputPortWidget:virtual public PortWidget{
public:

	InputPortWidget();

	virtual InputPort* getInputPort() = 0;
};

#endif // INPUTPORTINTERFACE_H
