#ifndef ABSTRACTARRAYNODE_H
#define ABSTRACTARRAYNODE_H

#include "AbstractDataNode.h"
#include "../GraphicsNodeInterface/GraphicsArrayNodeInterface.h"

class AbstractArrayNode:
		public AbstractDataNode,
		GraphicsArrayNodeInterface
{
public:
	AbstractArrayNode();

	// AbstractNode interface
public:
	virtual void verifyConnectable(AbstractNode *node) override;

	// ModelCodingInterface interface
public:
	virtual CodeText dataTexting() const override;
	virtual CodeText getModelType() const override;
};

#endif // ABSTRACTARRAYNODE_H
