#include "AbstractScatterSeriesNode.h"

AbstractScatterSeriesNode::AbstractScatterSeriesNode()
{

}


void AbstractScatterSeriesNode::process(AbstractNode *nextNode)
{
	AbstractSeriesNode::process(nextNode);
	auto
			x = this->getXData(),
			y = this->getYData();

	int size = qMin(x.size(),y.size());

	for(int index = 0;index < size; ++size){
		this->series->append(x[index],y[index]);
	}
}

QtCharts::QAbstractSeries *AbstractScatterSeriesNode::getSeries() const
{
	return this->series;
}
