#include "InterpreterController.h"
#include <QDebug>
InterpreterController::InterpreterController()
{

}

void InterpreterController::dfsInterprete(AbstractNode *startNode)
{
	for(auto&nextNode:this->graph[startNode->getNodeName()]){
		startNode->process(nextNode);
		this->dfsInterprete(nextNode);
	}
}



InterpreterController::InterpreterController(StartNode*startNode):
	startNode(startNode)
{

}

void InterpreterController::interprete()
{
	this->dfsInterprete(this->startNode);
}


void InterpreterController::addConnect(AbstractNode *outputNode, AbstractNode *inputNode)
{
	outputNode->verifyConnectable(inputNode);
	this->graph[outputNode->getNodeName()].insert(inputNode);
}

void InterpreterController::removeConnect(AbstractNode *outputNode, AbstractNode *inputNode)
{
	this->graph[outputNode->getNodeName()].remove(inputNode);
}

InterpreterController *InterpreterController::getGlobalInstance()
{
	return InterpreterController::globalController;
}

void InterpreterController::setStartNode(AbstractNode *start)
{
	this->startNode = start;
}

bool InterpreterController::hasNodeName(const QString &nodeName) const
{
	return this->graph.contains(nodeName);
}

InterpreterController* InterpreterController::globalController = new InterpreterController;
