#include "InterpreterController.h"
#include <QDebug>
#include "../Exception/NodeNameConflictException.h"
#include "../DataModel/AbstractChartNode.h"
InterpreterController::InterpreterController()
{

}

void InterpreterController::dfsInterprete(AbstractNode *startNode)
{
	startNode->process(nullptr);
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
	//! @note process all chart node after dfsInterprete which has not been processed.
	for(AbstractNode*node:nodes.values()){
		AbstractChartNode*chartNode = dynamic_cast<AbstractChartNode*>(node);
		if(chartNode && !chartNode->isProcess()){
			chartNode->process(nullptr);
		}
	}
}


void InterpreterController::addConnect(AbstractNode *outputNode, AbstractNode *inputNode)
{
	inputNode->verifyConnectable(outputNode);
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

bool InterpreterController::hasNodeName(const NodeName &nodeName) const
{
	return this->nodes.contains(nodeName);
}

void InterpreterController::addNode(AbstractNode *newNode)
{
	if(nodes.contains(newNode->getNodeName())){
		throw NodeNameConflictException(newNode->getNodeName());
	}
	this->nodes.insert(newNode->getNodeName(),newNode);
}



AbstractNode *InterpreterController::getStartNode()
{
	return this->startNode;
}

void InterpreterController::setGlobal(InterpreterController *controller)
{
	InterpreterController::globalController = controller;
}

InterpreterController* InterpreterController::globalController = new InterpreterController;
