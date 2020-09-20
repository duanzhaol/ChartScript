#include "AbstractNode.h"


GraphicsNodeInterface *AbstractNode::getNode() const
{
	return node;
}

void AbstractNode::setNode(GraphicsNodeInterface *value)
{
	node = value;
}

void AbstractNode::verifyConnectable(AbstractNode *node)
{
	//do nothing
}

AbstractNode::AbstractNode(GraphicsNodeInterface*node)
	:node(node)
{

}

void AbstractNode::process()
{
	for(AbstractNode*node:nextNodes){
		node->process();
	}
}

AbstractNode::~AbstractNode()
{

}

void AbstractNode::addNextNodes(AbstractNode *node)
{
	this->verifyConnectable(node);
	this->nextNodes.insert(node->getNode()->getNodeName(),node);
}

void AbstractNode::removeNextNode(AbstractNode *node)
{
	this->nextNodes.remove(node->getNode()->getNodeName());
}


