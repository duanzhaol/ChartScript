#ifndef ABSTRACTSERIESNODE_H
#define ABSTRACTSERIESNODE_H

#include "AbstractNode.h"
#include <QtCharts/QAbstractSeries>

class AbstractSeriesNode:public AbstractNode
{
public:
	AbstractSeriesNode();
	virtual QtCharts::QAbstractSeries*getSeries()const = 0;
};

#endif // ABSTRACTSERIESNODE_H
