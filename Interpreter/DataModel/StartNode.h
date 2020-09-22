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
	virtual CodeText getModelType() const override;
};

#endif // STARTNODE_H
