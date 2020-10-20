#ifndef ABSTRACTSERIESNODE_H
#define ABSTRACTSERIESNODE_H

#include "../AbstractNode.h"
#include <QtCharts/QAbstractSeries>

class AbstractSeriesNode:public AbstractNode
{
public:
	AbstractSeriesNode();
	virtual QtCharts::QAbstractSeries*getSeries()const = 0;

	// AbstractNode interface
public:
	virtual void process(AbstractNode *nextNode) override;
};

#endif // ABSTRACTSERIESNODE_H
