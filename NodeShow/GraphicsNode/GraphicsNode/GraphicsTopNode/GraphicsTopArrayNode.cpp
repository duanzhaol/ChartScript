#include "GraphicsTopArrayNode.h"


GraphicsDataArrayNode *GraphicsTopArrayNode::getInnerNode() const
{
	Q_ASSERT(innerNode != nullptr);
	return innerNode;
}

void GraphicsTopArrayNode::setInnerNode(GraphicsDataArrayNode *value)
{
	innerNode = value;
}

GraphicsTopArrayNode::GraphicsTopArrayNode
(GraphicsDataArrayNode *innerDataArrayNode, MovableProxyWidget *proxy):
	AbstractGraphicsTopDualoutNode (proxy),
	innerNode(innerDataArrayNode)
{
	innerDataArrayNode->setTopProxy(proxy);
	proxy->setWidget(innerDataArrayNode);
}

OutputPort *GraphicsTopArrayNode::getOutputPort()
{
	return innerNode->getOutputPort();
}

InputPort *GraphicsTopArrayNode::getInputPort()
{
	return innerNode->getInputPort();
}
