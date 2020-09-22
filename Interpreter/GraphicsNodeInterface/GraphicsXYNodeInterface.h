#ifndef GRAPHICSXYNODEINTERFACE_H
#define GRAPHICSXYNODEINTERFACE_H
#include "../DataModel/AbstractDataNode.h"
#include <QList>

class GraphicsXYNodeInterface
{
public:
	virtual QList<qreal>& getXData() = 0;
	virtual QList<qreal>& getYData() = 0;

};

#endif // GRAPHICSXYNODEINTERFACE_H
