#include "AbstractNode.h"

AbstractNode::NodeName_t AbstractNode::getNodeName() const
{
	return nodeName;
}

void AbstractNode::setNodeName(const NodeName_t &value)
{
	nodeName = value;
}

void AbstractNode::process()
{
	for(AbstractNode*node:nextNodes){
		node->process();
	}
}

void AbstractNode::addNextNodes(AbstractNode *node)
{
	this->nextNodes.insert(node->getNodeName(),node);
}


