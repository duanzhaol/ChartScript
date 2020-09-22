#ifndef ABSTRACTTWODIMENSIONSTATISTICALCHARTNODE_H
#define ABSTRACTTWODIMENSIONSTATISTICALCHARTNODE_H

#include "AbstractNode.h"
#include "../GraphicsNodeInterface/GraphicsTwoDimensionStatisticalChartInterface.h"

class AbstractTwoDimensionStatisticalChartNode:
		public AbstractNode,
		public GraphicsTwoDimensionStatisticalChartInterface
{
public:
	AbstractTwoDimensionStatisticalChartNode();


	// AbstractNode interface
protected:
	virtual void verifyConnectable(AbstractNode *node) override;

public:
	virtual void process(AbstractNode*nextNode) override;
};

#endif // ABSTRACTTWODIMENSIONSTATISTICALCHARTNODE_H
