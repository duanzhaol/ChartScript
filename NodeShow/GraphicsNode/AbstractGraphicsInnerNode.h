#ifndef ABSTRACTGRAPHICSINNERNODE_H
#define ABSTRACTGRAPHICSINNERNODE_H

#include "Dualputable.h"
#include "AbstractGraphicsNode.h"

#include "MovableProxyWidget.h"

using Proxy = MovableProxyWidget;


class AbstractGraphicsInnerNode:public AbstractGraphicsNode
{
	Proxy*topProxy = nullptr;
public:
	AbstractGraphicsInnerNode();

	Proxy *getTopProxy() const;
	virtual void setTopProxy(Proxy *value);
};

#endif // ABSTRACTGRAPHICSINNERNODE_H
