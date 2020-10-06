#ifndef ABSTRACTCHARTNODE_H
#define ABSTRACTCHARTNODE_H

#include "../GraphicsShowInterface/GraphicsShowInterface.h"
#include "AbstractNode.h"
#include "../GraphicsNodeInterface/GraphicsChartNodeInterface.h"

class AbstractChartNode:
		public AbstractNode,
        public GraphicsShowInterface,
		public GraphicsChartNodeInterface
{
	QtCharts::QChart*chart = new QtCharts::QChart;
public:
	AbstractChartNode();

	// GraphicsShowInterface interface
public:
	virtual QString getName() const override;
	virtual QtCharts::QChart *getChart() const override;

	// AbstractNode interface
public:
	virtual void process(AbstractNode *nextNode) override;
};

#endif // ABSTRACTCHARTNODE_H
