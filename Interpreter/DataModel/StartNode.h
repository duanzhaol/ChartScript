#ifndef STARTNODE_H
#define STARTNODE_H

#include "AbstractNode.h"

class StartNode:public AbstractNode{
public:
	StartNode(GraphicsNodeInterface*node);
	~StartNode()override;
};

#endif // STARTNODE_H
