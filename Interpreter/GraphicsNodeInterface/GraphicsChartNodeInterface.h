#ifndef GRAPHICSCHARTNODEINTERFACE_H
#define GRAPHICSCHARTNODEINTERFACE_H

#include "../DataModel/SeriesModel/AbstractSeriesNode.h"

/**
 * @interface GraphicsChartNodeInterface
 * 统计图节点接口，实现该接口的子类能够成为统计图节点的编译单元
 */

class GraphicsChartNodeInterface{
public:
	virtual QList<AbstractSeriesNode*> getAllSeries()const = 0;
};

#endif // GRAPHICSCHARTNODEINTERFACE_H

