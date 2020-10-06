#ifndef GRAPHICSCHARTNODEINTERFACE_H
#define GRAPHICSCHARTNODEINTERFACE_H

#include "../DataModel/SeriesModel/AbstractSeriesNode.h"

class GraphicsChartNodeInterface{
public:
	virtual QList<AbstractSeriesNode*> getAllSeries()const = 0;
};

#endif // GRAPHICSCHARTNODEINTERFACE_H

