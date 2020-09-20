#ifndef ABSTRACTDATANODE_H
#define ABSTRACTDATANODE_H
#include "AbstractNode.h"
#include "../GraphicsNodeInterface/GraphicsDataNodeInterface.h"
#include "../Exception/TypeUnconvertible.h"
#include <QVariant>

/**
 * @brief The AbstractDataNode class
 *
 */

class AbstractDataNode : public AbstractNode
{
public:
	AbstractDataNode(GraphicsDataNodeInterface*node);
	~AbstractDataNode()override;

	// AbstractNode interface
public:
	virtual void process() override;

	// AbstractNode interface
public:
	virtual GraphicsDataNodeInterface *getNode() const override;

	// AbstractNode interface
protected:
	virtual void verifyConnectable(AbstractNode *node) override;
private:
	void processTypeCasting(AbstractDataNode*node)const;
};

#endif // ABSTRACTDATANODE_H
