#include "AbstractDataNode.h"

QVariant AbstractDataNode::getNodeData() const
{
	return nodeData;
}

void AbstractDataNode::setNodeData(const QVariant &value)
{
	nodeData = value;
}

AbstractDataNode::AbstractDataNode(const QString&name)
	:AbstractNode (name)
{

}


void AbstractDataNode::process()
{
	AbstractNode::process();
	for(AbstractNode*node:this->nextNodes){
		if(dynamic_cast<AbstractDataNode*>(node) != nullptr){
			reinterpret_cast<AbstractDataNode*>(node)->setNodeData(this->nodeData);
		}
	}
}
