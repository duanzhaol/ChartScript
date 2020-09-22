#include "AbstractLineSeriesNode.h"
#include <QList>

AbstractLineSeriesNode::AbstractLineSeriesNode()
{

}



void AbstractLineSeriesNode::process(AbstractNode *nextNode)
{
	AbstractSeriesNode::process(nextNode);
	auto
			x = this->getXData()->getNodeData().toList(),
			y = this->getYData()->getNodeData().toList();

	int size = qMin(x.size(),y.size());

	for(int index = 0;index < size; ++size){
		this->series->append(x[index].toDouble(),y[index].toDouble());
	}

}

QtCharts::QAbstractSeries *AbstractLineSeriesNode::getSeries() const
{
	return this->series;
}


CodeText AbstractLineSeriesNode::dataTexting() const
{

	return QString(R"(
				   \tX=%1
				   \tY=%2
				   )")
			.arg(this->getXData()->dataTexting())
			.arg(this->getYData()->dataTexting());
}

CodeText AbstractLineSeriesNode::getModelType() const
{
	return QStringLiteral("LineSeries");
}
