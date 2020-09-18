#ifndef DUALPORTINTERFACE_H
#define DUALPORTINTERFACE_H

#include "InputPortWidget.h"
#include "OutputPortWidget.h"
#include "MovableProxyWidget.h"


class DualPortWidget :public InputPortWidget,public OutputPortWidget{
public:
	DualPortWidget();
};

#endif // DUALPORTINTERFACE_H
