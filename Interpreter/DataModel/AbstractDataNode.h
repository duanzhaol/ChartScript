#ifndef ABSTRACTDATANODE_H
#define ABSTRACTDATANODE_H
#include "AbstractNode.h"
#include "../Exception/TypeUnconvertible.h"
#include "../GraphicsNodeInterface/GraphicsDataNodeInterface.h"
#include <QVariant>

/**
 * @brief The AbstractDataNode class
 *
 */


class AbstractDataNode:public AbstractNode,public GraphicsDataNodeInterface
{
public:
	AbstractDataNode();
	~AbstractDataNode();

	// AbstractNode interface
public:
	virtual void process(AbstractNode*nextNode) override;


	// AbstractNode interface
public:
	virtual void verifyConnectable(AbstractNode *node) override;
private:
	void processTypeCasting(AbstractDataNode*node)const;
};

#endif // ABSTRACTDATANODE_H
