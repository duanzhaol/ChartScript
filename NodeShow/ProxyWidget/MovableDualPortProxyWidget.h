#ifndef MOVABLEDUALPORTPROXYWIDGET_H
#define MOVABLEDUALPORTPROXYWIDGET_H

#include "MovableInputPortProxyWidget.h"
#include "OutputPortWidget.h"
#include "MovableOutputPortProxyWidget.h"

class MovableDualPortProxyWidget:public MovableInputPortProxyWidget,public MovableOutputPortProxyWidget
{
public:
	MovableDualPortProxyWidget();
	void setInputPortWidget(InputPortWidget*node) = delete;
	void setOutputPortWidget(InputPortWidget*node) = delete;
	void setDualPortWidget(DualPortWidget*node);
};





#endif // MOVABLEDUALPORTPROXYWIDGET_H
