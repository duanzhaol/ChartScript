#ifndef ABSTRACTPIESERIES_H
#define ABSTRACTPIESERIES_H

#include "AbstractSeriesNode.h"
#include "../../GraphicsNodeInterface/GraphicsXYNodeInterface.h"
#include "../../GraphicsNodeInterface/GraphicsPieNodeInterface.h"
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

class AbstractPieSeries:
		public AbstractSeriesNode,
		public GraphicsPieNodeInterface
{
	QtCharts::QPieSeries*series = new QtCharts::QPieSeries;
public:
	AbstractPieSeries();

	// AbstractNode interface
public:
	virtual void process(AbstractNode *nextNode) override;

	// AbstractSeriesNode interface
public:
	virtual QtCharts::QAbstractSeries *getSeries() const override;

	// ModelCodingInterface interface
public:
	virtual CodeText dataTexting() const override;
	virtual CodeText getModelTypeName() const override;

	// AbstractNode interface
public:
	virtual ModelType getDataModelType() const override;
};

#endif // ABSTRACTPIESERIES_H
