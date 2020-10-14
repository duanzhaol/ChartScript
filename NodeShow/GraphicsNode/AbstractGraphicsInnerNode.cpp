#include "AbstractGraphicsInnerNode.h"


Proxy *AbstractGraphicsInnerNode::getTopProxy() const
{
	Q_ASSERT_X(topProxy != nullptr,__FILE__ + __LINE__,"do not forget to set top proxy before you use this");
	return topProxy;
}

void AbstractGraphicsInnerNode::setTopProxy(Proxy *value)
{
	topProxy = value;
}

AbstractGraphicsInnerNode::AbstractGraphicsInnerNode()
{
}
