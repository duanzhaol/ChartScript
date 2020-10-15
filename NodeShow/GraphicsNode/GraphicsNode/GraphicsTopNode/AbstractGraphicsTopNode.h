#ifndef ABSTRACTGRAPHICSTOPNODE_H
#define ABSTRACTGRAPHICSTOPNODE_H

#include "MovableProxyWidget.h"
#include "../AbstractGraphicsNode.h"

using Proxy = MovableProxyWidget;

class AbstractGraphicsTopNode:public AbstractGraphicsNode
{
	Proxy*proxy = nullptr;
public:
	AbstractGraphicsTopNode(MovableProxyWidget*proxy);
	Proxy *getProxy() const;
};

#endif // ABSTRACTGRAPHICSTOPNODE_H
