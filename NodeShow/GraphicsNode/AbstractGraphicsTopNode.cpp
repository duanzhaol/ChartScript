#include "AbstractGraphicsTopNode.h"

Proxy *AbstractGraphicsTopNode::getProxy() const
{
	return proxy;
}

AbstractGraphicsTopNode::AbstractGraphicsTopNode(MovableProxyWidget*proxy):
	proxy(proxy)
{

}
