#ifndef GRAPHICSXYNODEINTERFACE_H
#define GRAPHICSXYNODEINTERFACE_H
#include "../DataModel/AbstractDataNode.h"

class GraphicsXYNodeInterface
{
public:
	virtual AbstractDataNode*getXDataNode() = 0;
	virtual AbstractDataNode* getYDataNode() = 0;

};

#endif // GRAPHICSXYNODEINTERFACE_H
