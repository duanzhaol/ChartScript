#include "AbstractDataNode.h"
#include <QDebug>

AbstractDataNode::AbstractDataNode()
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
			dynamic_cast<AbstractDataNode*>(node)->setNodeData(this->getNodeData());
		}
	}
}


void AbstractDataNode::verifyConnectable(AbstractNode *node)
{
	AbstractDataNode*dataNode = dynamic_cast<AbstractDataNode*>(node);
	if(dataNode == nullptr) return;
	processTypeCasting(dataNode);
}

void AbstractDataNode::processTypeCasting(AbstractDataNode *node) const
{
	QVariant outputData = this->getNodeData(),
			inputData = node->getNodeData();

	if(!outputData.canConvert(inputData.type())){
		throw TypeUnconvertible(outputData.type(),inputData.type());
	}
}
