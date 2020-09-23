#ifndef ABSTRACTARRAYNODE_H
#define ABSTRACTARRAYNODE_H

#include "AbstractDataNode.h"
#include "../GraphicsNodeInterface/GraphicsArrayNodeInterface.h"

class AbstractArrayNode:
		public AbstractDataNode,
		public GraphicsArrayNodeInterface
{
public:
	AbstractArrayNode();

	// AbstractNode interface
public:
	virtual void verifyConnectable(AbstractNode *node) override;

	// ModelCodingInterface interface
public:
	virtual CodeText dataTexting() const override;
	virtual CodeText getModelTypeName() const override;

	// GraphicsArrayNodeInterface interface
public:
	virtual QVariant::Type getElementType() const override;

	// GraphicsNodeInterface interface
public:
	virtual NodeName getNodeName() const override;
	virtual void setNodeName(const NodeName &newNodeName) override;

	// GraphicsDataNodeInterface interface
public:
	virtual QVariant getNodeData() const override;
	virtual void setNodeData(const QVariant &newData) override;

	// AbstractNode interface
public:
	virtual ModelType getDataModelType() const override;
};

#endif // ABSTRACTARRAYNODE_H
