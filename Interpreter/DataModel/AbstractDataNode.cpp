#include "AbstractDataNode.h"
#include <QDebug>

AbstractDataNode::AbstractDataNode()
{

}

AbstractDataNode::~AbstractDataNode()
{

}


void AbstractDataNode::process(AbstractNode* nextNode)
{
	AbstractNode::process(nextNode);
	if(dynamic_cast<AbstractDataNode*>(nextNode) != nullptr){
		dynamic_cast<AbstractDataNode*>(nextNode)->setNodeData(this->getNodeData());
	}
}


void AbstractDataNode::verifyConnectable(AbstractNode *node)
{
	AbstractDataNode*dataNode = dynamic_cast<AbstractDataNode*>(node);
	if(dataNode == nullptr) return;
	processTypeCasting(dataNode);
}

void AbstractDataNode::processTypeCasting(AbstractDataNode *node) const
{
	QVariant outputData = this->getNodeData(),
			inputData = node->getNodeData();


	if(!outputData.canConvert(inputData.type())||!isConvertible(inputData.type(),outputData.type())){
		throw TypeUnconvertible(outputData.type(),inputData.type());
	}


}

bool AbstractDataNode::isConvertible(QVariant::Type type1, QVariant::Type type2)const
{
	return
			(type1 == QVariant::String && type2 == QVariant::String)
			||
			(type1 != QVariant::String && type2 != QVariant::String);
}

CodeText AbstractDataNode::dataTexting() const
{
	const QVariant& nodeData = this->getNodeData();

	if(nodeData.type() == QVariant::Type::String){
		return QString("%1 \"%2\"")
				.arg(nodeData.typeName())
				.arg(nodeData.toString());
	}
	else{
		return QString("%1 %2")
				.arg(nodeData.typeName())
				.arg(nodeData.toString());
	}


}

CodeText AbstractDataNode::getModelTypeName() const
{
	return QStringLiteral("Data");
}

ModelType AbstractDataNode::getDataModelType() const
{
	return ModelType::Data;
}
