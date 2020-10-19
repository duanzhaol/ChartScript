#ifndef GRAPHICSTOPARRAYNODE_H
#define GRAPHICSTOPARRAYNODE_H

#include "../GraphicsInnerNode/GraphicsDataArrayNode.h"
#include "AbstractGraphicsTopDualoutNode.h"
#include "MovableProxyWidget.h"

class GraphicsTopArrayNode:public AbstractGraphicsTopDualoutNode
{
	GraphicsDataArrayNode*innerNode = nullptr;
public:
	GraphicsTopArrayNode(GraphicsDataArrayNode*innerDataArrayNode,MovableProxyWidget*proxy);

	// Outputable interface
public:
	virtual OutputPort *getOutputPort() override;

	// Inputable interface
public:
	virtual InputPort *getInputPort() override;
	GraphicsDataArrayNode *getInnerNode() const;
	void setInnerNode(GraphicsDataArrayNode *value);
};

#endif // GRAPHICSTOPARRAYNODE_H
