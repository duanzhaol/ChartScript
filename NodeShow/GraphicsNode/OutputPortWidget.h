#ifndef OUTPUTPORTINTERFACE_H
#define OUTPUTPORTINTERFACE_H

#include "PortWidget.h"

#include <QPushButton>
#include <QGraphicsItem>

using OutputPort = QWidget;

class OutputPortWidget:virtual public PortWidget{
public:

	OutputPortWidget();

	virtual OutputPort* getOutputPort() = 0;
};
#endif // OUTPUTPORTINTERFACE_H
