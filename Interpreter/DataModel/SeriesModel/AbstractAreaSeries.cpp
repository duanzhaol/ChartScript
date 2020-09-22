#include "AbstractAreaSeries.h"

AbstractAreaSeries::AbstractAreaSeries()
{

}


void AbstractAreaSeries::process(AbstractNode *nextNode)
{
	AbstractSeriesNode::process(nextNode);

	auto getLine = [](AbstractArrayNode*xNode,AbstractArrayNode*yNode)->QtCharts::QLineSeries*{
		auto line = new QtCharts::QLineSeries;

		auto x = xNode->getNodeData().toList();
		auto y = yNode->getNodeData().toList();

		int size = qMin(x.size(),y.size());
		for(int index = 0;index < size; ++index){
			line->append(x[index].toDouble(),y[index].toDouble());
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


CodeText AbstractAreaSeries::dataTexting() const
{
	return QString(R"(
				   \tUpperX=%1
				   \tUpperY=%2
				   \tLowerX=%3
				   \tLowerY=%4
				   )")
			.arg(this->getUpperXData()->dataTexting())
			.arg(this->getUpperYData()->dataTexting())
			.arg(this->getBottomXData()->dataTexting())
			.arg(this->getBottomYData()->dataTexting())
			;
}

CodeText AbstractAreaSeries::getModelType() const
{
	return QStringLiteral("AreaSeries");
}
