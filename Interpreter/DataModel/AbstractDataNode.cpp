#include "AbstractDataNode.h"


AbstractDataNode::AbstractDataNode(GraphicsDataNodeInterface*node)
	:AbstractNode (node)
{

}

AbstractDataNode::~AbstractDataNode()
{

}


void AbstractDataNode::process()
{
	AbstractNode::process();
	for(AbstractNode*node:this->nextNodes){
		if(dynamic_cast<AbstractDataNode*>(node) != nullptr){
			dynamic_cast<AbstractDataNode*>(node)->getNode()->setNodeData(this->getNode()->getNodeData());
		}
	}
}


GraphicsDataNodeInterface *AbstractDataNode::getNode() const
{
	return static_cast<GraphicsDataNodeInterface*>(AbstractNode::getNode());
}


void AbstractDataNode::verifyConnectable(AbstractNode *node)
{
	AbstractDataNode*dataNode = dynamic_cast<AbstractDataNode*>(node);
	if(dataNode == nullptr) return;
	processTypeCasting(dataNode);
}

void AbstractDataNode::processTypeCasting(AbstractDataNode *node) const
{
	QVariant* outputData = this->getNode()->getNodeData(),
			*inputData = node->getNode()->getNodeData();
	if(!outputData->canConvert(inputData->type())){
		throw new TypeUnconvertible(outputData->type(),inputData->type());
	}
}
