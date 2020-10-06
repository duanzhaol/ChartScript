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
protected:
	void processTypeCasting(AbstractDataNode*node)const;
	bool isConvertible (QVariant::Type type1,QVariant::Type type2)const;

	// ModelCodingInterface interface
public:
	virtual CodeText dataTexting() const override;
	virtual CodeText getModelTypeName() const override;

	// AbstractNode interface
public:
	virtual ModelType getDataModelType() const override;
};



#endif // ABSTRACTDATANODE_H
