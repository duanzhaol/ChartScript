#ifndef ABSTRACTLINESERIESNODE_H
#define ABSTRACTLINESERIESNODE_H

#include "AbstractSeriesNode.h"
#include "../../GraphicsNodeInterface/GraphicsXYNodeInterface.h"
#include <QtCharts/QLineSeries>

class AbstractLineSeriesNode:
		public AbstractSeriesNode,
		public GraphicsXYNodeInterface
{

	QtCharts::QLineSeries*series = new QtCharts::QLineSeries;
public:
	AbstractLineSeriesNode();

	// AbstractNode interface
public:
	virtual void process(AbstractNode *nextNode) override;

	// AbstractSeriesNode interface
public:
	virtual QtCharts::QAbstractSeries *getSeries() const override;

	// ModelCodingInterface interface
public:
	virtual CodeText dataTexting() const override;
	virtual CodeText getModelType() const override;
};

#endif // ABSTRACTLINESERIESNODE_H
