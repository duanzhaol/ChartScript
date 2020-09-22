﻿#include "AbstractLineSeriesNode.h"
#include <QList>

AbstractLineSeriesNode::AbstractLineSeriesNode()
{

}



void AbstractLineSeriesNode::process(AbstractNode *nextNode)
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

QtCharts::QAbstractSeries *AbstractLineSeriesNode::getSeries() const
{
	return this->series;
}
