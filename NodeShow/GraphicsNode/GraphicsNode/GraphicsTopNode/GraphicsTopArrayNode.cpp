#include "GraphicsTopArrayNode.h"
#include <QDebug>

GraphicsTopArrayNode::GraphicsTopArrayNode
(TableArrayInterface *dataSource, MovableProxyWidget *proxy):
		AbstractGraphicsTopDualoutNode (proxy),
		innerNode(new GraphicsInnerDataArrayNode(dataSource))
{
	innerNode->setTopProxy(proxy);
	proxy->setWidget(innerNode);
}

OutputPort *GraphicsTopArrayNode::getOutputPort()
{
	return innerNode->getOutputPort();
}

InputPort *GraphicsTopArrayNode::getInputPort()
{
	return innerNode->getInputPort();
}


GraphicsTopArrayNode::GraphicsInnerDataArrayNode::GraphicsInnerDataArrayNode
(TableArrayInterface *dataSource):
	dataSource(dataSource)
{
	Q_ASSERT(dataSource != nullptr);
	connect(dataSource,&TableArrayInterface::arrayNameChanged,this,[=](){
		GraphicsDataArrayNode::setNodeName(dataSource->getArrayName());
	});

	connect(dataSource,&TableArrayInterface::arrayDataChanged,this,[=](){
		GraphicsDataArrayNode::setNodeData(dataSource->getArrayData());
	});

	connect(dataSource,&TableArrayInterface::arrayTypeChanged,this,[=](){
		GraphicsDataArrayNode::setElementType(dataSource->getArrayType());
	});

	connect(dataSource,&TableArrayInterface::arrayDelete,this,[=](){
		this->deleteLater();
	});
}

NodeName GraphicsTopArrayNode::GraphicsInnerDataArrayNode::getNodeName() const
{
	return dataSource->getArrayName();
}

void GraphicsTopArrayNode::GraphicsInnerDataArrayNode::setNodeName(const NodeName &newNodeName)
{
	return dataSource->setArrayName(newNodeName);
}

QVariant GraphicsTopArrayNode::GraphicsInnerDataArrayNode::getNodeData() const
{
	return dataSource->getArrayData();
}

void GraphicsTopArrayNode::GraphicsInnerDataArrayNode::setNodeData(const QVariant &newData)
{
	Q_ASSERT(newData.type() == QVariant::Type::List);
	dataSource->setArrayData(newData.toList());
}

QVariant::Type GraphicsTopArrayNode::GraphicsInnerDataArrayNode::getElementType() const
{
	return dataSource->getArrayType();
}

void GraphicsTopArrayNode::GraphicsInnerDataArrayNode::setElementType(QVariant::Type type)
{
	dataSource->setArrayType(type);
}
