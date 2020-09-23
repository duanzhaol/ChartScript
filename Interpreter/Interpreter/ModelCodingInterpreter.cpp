#include "ModelCodingInterpreter.h"
#include <QSet>
#include <functional>

void ModelCodingInterpreter::initNodes(AbstractNode *start)
{
	this->nodes.insert(start);
	for(auto nextNode:controller->graph[start->getNodeName()]){
		initNodes(nextNode);
	}
}

ModelCodingInterpreter::ModelCodingInterpreter(InterpreterController *controller):
	controller(controller)
{
	initNodes(controller->getGlobalInstance()->startNode);
}

CodeText ModelCodingInterpreter::coding() const
{
	CodeText code = "Init:{\n";
	for(ModelCodingInterface* node:nodes){
		code += node->getModelTypeName() + " " + node->getModelName() + " " + node->dataTexting() + "\n";
	}

	code+="}\nConnection:{\n";

	std::function<void(AbstractNode*)> dfs = [&](AbstractNode*start){
		for(AbstractNode* nextNode:this->controller->graph[start->getNodeName()]){
			dfs(nextNode);
			code += start->getModelName() + " -> " + nextNode->getModelName() + "\n";
		}
	};

	dfs(controller->startNode);

	return code + "}";

}
