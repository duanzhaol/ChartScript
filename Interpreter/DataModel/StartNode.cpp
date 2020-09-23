#include "StartNode.h"

StartNode::StartNode()
{

}

StartNode::~StartNode()
{

}


CodeText StartNode::dataTexting() const
{
	return "";
}



CodeText StartNode::getModelTypeName() const
{
	return QStringLiteral("Start");
}


ModelType StartNode::getDataModelType() const
{
	return ModelType::Start;
}
