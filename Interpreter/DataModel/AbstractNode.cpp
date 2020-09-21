#include "AbstractNode.h"
#include <QDebug>




void AbstractNode::verifyConnectable(AbstractNode *node)
{
	Q_UNUSED(node);
	//do nothing
}

AbstractNode::AbstractNode()
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
	this->nextNodes.insert(node->getNodeName(),node);
}

void AbstractNode::removeNextNode(AbstractNode *node)
{
	this->nextNodes.remove(node->getNodeName());
}


