﻿#ifndef ABSTRACTSCATTERSERIESNODE_H
#define ABSTRACTSCATTERSERIESNODE_H

#include "AbstractSeriesNode.h"
#include "../../GraphicsNodeInterface/GraphicsXYNodeInterface.h"
#include <QtCharts/QScatterSeries>

class AbstractScatterSeriesNode:
		public AbstractSeriesNode,
		public GraphicsXYNodeInterface
{
	QtCharts::QScatterSeries*series = new QtCharts::QScatterSeries;
public:
	AbstractScatterSeriesNode();

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

#endif // ABSTRACTSCATTERSERIESNODE_H