#include "AbstractChartNode.h"
#include "../Transmitter/GraphShowTransmitter.h"

AbstractChartNode::AbstractChartNode()
{

}


QString AbstractChartNode::getName() const
{
	return this->getNodeName();
}

Chart *AbstractChartNode::getChart() const
{
	return this->chart;
}

bool AbstractChartNode::isProcess() const
{
	return d_isProcess;
}

#include <QLineSeries>
#include <QDebug>

void AbstractChartNode::process(AbstractNode *nextNode)
{
	this->chart = new Chart;
	auto seriesList = this->getAllSeries();
	for(auto&series:seriesList){
		series->process(nextNode);
		this->chart->addSeries(series->getSeries());
	}

	emit GraphShowTransmitter::getInstance().sendChart(this);

	d_isProcess = true;

}

CodeText AbstractChartNode::dataTexting() const
{
	return "undefined";
}

CodeText AbstractChartNode::getModelTypeName() const
{
	return "Chart";
}

ModelType AbstractChartNode::getDataModelType() const
{
	return ModelType::Chart;
}
