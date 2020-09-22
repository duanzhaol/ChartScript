#ifndef GRAPHICSAREANODEINTERFACE_H
#define GRAPHICSAREANODEINTERFACE_H
#include <QList>

class GraphicsAreaNodeInterface{
public:
	virtual QList<qreal>& getUpperXData() = 0;
	virtual QList<qreal>& getUpperYData() = 0;
	virtual QList<qreal>& getBottomXData() = 0;
	virtual QList<qreal>& getBottomYData() = 0;
};

#endif // GRAPHICSAREANODEINTERFACE_H
