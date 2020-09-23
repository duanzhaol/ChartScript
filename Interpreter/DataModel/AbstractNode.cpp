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
	return "\"" + this->getNodeName() + "\"";
}

ModelType AbstractNode::nameToType(const QString &typeName)
{
#define RETURN_TYPE(NAME) if(typeName == QStringLiteral(#NAME))return ModelType::NAME
	RETURN_TYPE(Start);
	RETURN_TYPE(Data);
	RETURN_TYPE(Array);
	RETURN_TYPE(PieSeries);
	RETURN_TYPE(AreaSeries);
	RETURN_TYPE(LineSeries);
	RETURN_TYPE(ScatterSeries);
	return ModelType::Invalid;
#undef RETURN_TYPE
}

QString AbstractNode::typeToName(const ModelType type)
{
#define RETURN_NAME(TYPE) if(type == ModelType::TYPE)return QStringLiteral(#TYPE);
	RETURN_NAME(Start);
	RETURN_NAME(Data);
	RETURN_NAME(Array);
	RETURN_NAME(PieSeries);
	RETURN_NAME(AreaSeries);
	RETURN_NAME(LineSeries);
	RETURN_NAME(ScatterSeries);
	return QStringLiteral("Invalid");
#undef RETURN_NAME
}






