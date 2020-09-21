#include "InterpreterController.h"
#include <QDebug>
InterpreterController::InterpreterController()
{

}

InterpreterController::InterpreterController(StartNode*startNode):
	startNode(startNode)
{

}

void InterpreterController::interprete()
{
	this->startNode->process();
}


void InterpreterController::addConnect(AbstractNode *outputNode, AbstractNode *inputNode)
{
	outputNode->addNextNodes(inputNode);
}

void InterpreterController::removeConnect(AbstractNode *outputNode, AbstractNode *inputNode)
{
	outputNode->removeNextNode(inputNode);
}

InterpreterController *InterpreterController::getGlobalInstance()
{
	return InterpreterController::globalController;
}

void InterpreterController::setStartNode(AbstractNode *start)
{
	this->startNode = start;
}

InterpreterController* InterpreterController::globalController = new InterpreterController;
