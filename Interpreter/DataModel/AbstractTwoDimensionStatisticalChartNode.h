#ifndef ABSTRACTTWODIMENSIONSTATISTICALCHARTNODE_H
#define ABSTRACTTWODIMENSIONSTATISTICALCHARTNODE_H

#include "AbstractNode.h"
#include "../GraphicsNodeInterface/GraphicsTwoDimensionStatisticalChartInterface.h"
#include "../GraphicsShowInterface/GraphicsShowInterface.h"
#include <QChart>
#include <QtCharts>

class AbstractTwoDimensionStatisticalChartNode:
		public AbstractNode,
		public GraphicsTwoDimensionStatisticalChartInterface,
		public GraphicsShowInterface
{
	QtCharts::QChart* chart;
	QtCharts::QAbstractSeries* getSeries();
public:
	AbstractTwoDimensionStatisticalChartNode();

	// GraphicsShowInterface interface
public:
	virtual QString getName() const override;
	virtual QtCharts::QChart *getChart() const override;

	// AbstractNode interface
public:
	virtual void verifyConnectable(AbstractNode *node) override;
	virtual void process(AbstractNode *nextNode) override;
};

#endif // ABSTRACTTWODIMENSIONSTATISTICALCHARTNODE_H
