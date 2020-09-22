#ifndef GRAPHICSAREANODEINTERFACE_H
#define GRAPHICSAREANODEINTERFACE_H
#include <QList>
#include "../DataModel/AbstractArrayNode.h"

class GraphicsAreaNodeInterface{
public:
	virtual AbstractArrayNode* getUpperXData()const = 0;
	virtual AbstractArrayNode* getUpperYData()const = 0;
	virtual AbstractArrayNode* getBottomXData()const = 0;
	virtual AbstractArrayNode* getBottomYData()const = 0;
};

#endif // GRAPHICSAREANODEINTERFACE_H
