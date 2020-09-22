#ifndef GRAPHICSTWODIMENSIONSTATISTICALCHARTINTERFACE_H
#define GRAPHICSTWODIMENSIONSTATISTICALCHARTINTERFACE_H

#include "../DataModel/AbstractDataNode.h"

enum class StatisticalChartType:char{
	LineChart
};

class GraphicsTwoDimensionStatisticalChartInterface{
public:
	virtual AbstractDataNode*getXNode() = 0;
	virtual AbstractDataNode*getYNode() = 0;
	virtual StatisticalChartType getChartType() = 0;
};

#endif // GRAPHICSTWODIMENSIONSTATISTICALCHARTINTERFACE_H
