#ifndef ABSTRACTARRAYNODE_H
#define ABSTRACTARRAYNODE_H

#include "AbstractDataNode.h"
#include "../GraphicsNodeInterface/GraphicsArrayNodeInterface.h"

/**
 * @brief
 * 抽象数列节点，数列数据类型的编译单元
 * process方法实现了数列间数据转移
 */

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

	// AbstractNode interface
public:
	virtual ModelType getDataModelType() const override;
};

#endif // ABSTRACTARRAYNODE_H
