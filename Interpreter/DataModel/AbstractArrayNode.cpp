#include "AbstractArrayNode.h"

AbstractArrayNode::AbstractArrayNode()
{

}


void AbstractArrayNode::verifyConnectable(AbstractNode *node)
{
	AbstractDataNode::verifyConnectable(node);

	auto nextNode = dynamic_cast<AbstractArrayNode*>(node);
	if(nextNode != nullptr){
		auto outputDataTypee = this->getElementType(),inputDataTypee = nextNode->getElementType();
		if(!isConvertible(outputDataTypee,inputDataTypee)){
			throw TypeUnconvertible(outputDataTypee,inputDataTypee);
		}
	}

}
