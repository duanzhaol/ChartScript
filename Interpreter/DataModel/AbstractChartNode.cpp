#include "AbstractChartNode.h"

AbstractChartNode::AbstractChartNode()
{

}


QString AbstractChartNode::getName() const
{
	return this->getNodeName();
}

QtCharts::QChart *AbstractChartNode::getChart() const
{
	return this->chart;
}

void AbstractChartNode::process(AbstractNode *nextNode)
{
	auto seriesList = this->getAllSeries();
	for(auto&series:seriesList){
		series->process(nextNode);
		this->chart->addSeries(series->getSeries());
	}

}
