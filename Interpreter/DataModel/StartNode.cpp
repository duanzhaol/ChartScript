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



CodeText StartNode::getModelType() const
{
	return QStringLiteral("Start");
}
