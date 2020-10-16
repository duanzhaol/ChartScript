#include "ModelCodingInterpreter.h"
#include <QSet>
#include <functional>

void ModelCodingInterpreter::initNodes(AbstractNode *start)
{
	for(auto nextNode:controller->graph[start->getNodeName()]){
		this->nodes.insert(nextNode);
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
