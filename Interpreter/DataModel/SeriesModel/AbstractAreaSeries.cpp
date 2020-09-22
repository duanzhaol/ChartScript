#include "AbstractAreaSeries.h"

AbstractAreaSeries::AbstractAreaSeries()
{

}


void AbstractAreaSeries::process(AbstractNode *nextNode)
{
	AbstractSeriesNode::process(nextNode);

	auto getLine = [](QList<qreal>&x,QList<qreal>&y)->QtCharts::QLineSeries*{
		auto line = new QtCharts::QLineSeries;
		int size = qMin(x.size(),y.size());
		for(int index = 0;index < size; ++index){
			line->append(x[index],y[index]);
		}
		return line;
	};

	auto upperLine = getLine(this->getUpperXData(),this->getBottomXData());
	auto lowerLine = getLine(this->getBottomXData(),this->getBottomYData());

	this->series->setUpperSeries(upperLine);
	this->series->setLowerSeries(lowerLine);
}

QtCharts::QAbstractSeries *AbstractAreaSeries::getSeries() const
{
	return this->series;
}
