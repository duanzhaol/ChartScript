#ifndef GRAPHICSXYNODEINTERFACE_H
#define GRAPHICSXYNODEINTERFACE_H
#include "../DataModel/AbstractArrayNode.h"
#include <QList>

class GraphicsXYNodeInterface
{
public:
	virtual AbstractArrayNode* getXData()const = 0;
	virtual AbstractArrayNode* getYData()const = 0;

};

#endif // GRAPHICSXYNODEINTERFACE_H
