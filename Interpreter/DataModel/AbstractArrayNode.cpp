#include "AbstractArrayNode.h"

AbstractArrayNode::AbstractArrayNode()
{

}


void AbstractArrayNode::verifyConnectable(AbstractNode *node)
{
	AbstractDataNode::verifyConnectable(node);

	auto nextNode = dynamic_cast<AbstractArrayNode*>(node);
	if(nextNode != nullptr){
		auto outputDataTypee = this->getElementType(),inputDataTypee = nextNode->getElementType();
		if(!isConvertible(outputDataTypee,inputDataTypee)){
			throw TypeUnconvertible(outputDataTypee,inputDataTypee);
		}
	}

}


CodeText AbstractArrayNode::dataTexting() const
{
	auto nodeData = this->getNodeData().toList();

	if(nodeData.isEmpty()){
		return QString("%1 []").arg(QVariant::typeToName(this->getElementType()));
	}
	else {
		QString code = QString("%1 [").arg(QVariant::typeToName(this->getElementType()));
		for(auto&element:nodeData){
			if(element.type() == QVariant::String){
				code += "\"" + element.toString() + "\",";
			}
			else{
				code += element.toString() + ",";
			}
		}
		code.chop(1);
		return code + "]";
	}

}


CodeText AbstractArrayNode::getModelTypeName() const
{
	return QStringLiteral("Array");
}

ModelType AbstractArrayNode::getDataModelType() const
{
	return ModelType::Array;
}
