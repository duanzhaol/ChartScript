#ifndef ABSTRACTAREASERIES_H
#define ABSTRACTAREASERIES_H

#include "../../GraphicsNodeInterface/GraphicsAreaNodeInterface.h"
#include "AbstractSeriesNode.h"
#include <QtCharts/QLineSeries>
#include <QtCharts/QAreaSeries>

class AbstractAreaSeries:
		public AbstractSeriesNode,
		public GraphicsAreaNodeInterface
{
	QtCharts::QAreaSeries *series = new QtCharts::QAreaSeries;
public:
	AbstractAreaSeries();

	// AbstractNode interface
public:
	virtual void process(AbstractNode *nextNode) override;

	// AbstractSeriesNode interface
public:
	virtual QtCharts::QAbstractSeries *getSeries() const override;
};

#endif // ABSTRACTAREASERIES_H
