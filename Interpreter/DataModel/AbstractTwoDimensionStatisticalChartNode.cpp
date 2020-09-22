#include "AbstractTwoDimensionStatisticalChartNode.h"
#include "AbstractDataNode.h"

QAbstractSeries *AbstractTwoDimensionStatisticalChartNode::getSeries()
{
	switch (this->getChartType()) {
	case StatisticalChartType::LineChart: return new QLineSeries;
	}
}

AbstractTwoDimensionStatisticalChartNode::AbstractTwoDimensionStatisticalChartNode()
{

}


QString AbstractTwoDimensionStatisticalChartNode::getName() const
{
	return this->getNodeName();
}

QtCharts::QChart *AbstractTwoDimensionStatisticalChartNode::getChart() const
{
	return this->chart;
}

void AbstractTwoDimensionStatisticalChartNode::verifyConnectable(AbstractNode *node)
{
	AbstractNode::verifyConnectable(node);
}

void AbstractTwoDimensionStatisticalChartNode::process(AbstractNode *nextNode)
{
	AbstractDataNode
			*X = this->getXNode(),
			*y = this->getYNode();

	QAbstractSeries*series = getSeries();
	this->chart = new QtCharts::QChart;
	chart->addSeries(series);
	chart->createDefaultAxes();
	QXYSeries *s;

}











