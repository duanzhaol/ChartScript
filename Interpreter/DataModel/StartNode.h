#ifndef STARTNODE_H
#define STARTNODE_H

#include "AbstractNode.h"

class StartNode:public AbstractNode{
public:
	StartNode();
	~StartNode()override;

	// ModelCodingInterface interface
public:
	virtual CodeText dataTexting() const override;
	virtual CodeText getModelTypeName() const override;

	// AbstractNode interface
public:
	virtual ModelType getDataModelType() const override;

	// ModelCodingInterface interface
public:
	virtual CodeText getModelName() const override;
};

#endif // STARTNODE_H
