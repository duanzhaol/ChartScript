#ifndef GRAPHICSTWODIMENSIONSTATISTICALCHARTINTERFACE_H
#define GRAPHICSTWODIMENSIONSTATISTICALCHARTINTERFACE_H

#include "../DataModel/AbstractNode.h"

class GraphicsTwoDimensionStatisticalChartInterface{
	virtual AbstractNode*getXNode() = 0;
	virtual AbstractNode*getYNode() = 0;
};

#endif // GRAPHICSTWODIMENSIONSTATISTICALCHARTINTERFACE_H
