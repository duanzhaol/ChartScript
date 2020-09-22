#include "AbstractNode.h"
#include <QDebug>
#include "../Interpreter/InterpreterController.h"
#include "../Exception/NodeNameConflictException.h"



void AbstractNode::verifyConnectable(AbstractNode *node)
{
	Q_UNUSED(node);
	//do nothing
}

AbstractNode::AbstractNode()
{

}

void AbstractNode::process(AbstractNode* nextNode)
{
	Q_UNUSED(nextNode);
}

AbstractNode::~AbstractNode()
{

}


void AbstractNode::testNodeNameIfDuplicate(const NodeName &nodeName) const
{
	if(InterpreterController::getGlobalInstance()->hasNodeName(nodeName)){
		throw NodeNameConflictException(nodeName);
	}
}


CodeText AbstractNode::getModelName() const
{
	return this->getNodeName();
}
