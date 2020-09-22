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
};

#endif // ABSTRACTARRAYNODE_H
