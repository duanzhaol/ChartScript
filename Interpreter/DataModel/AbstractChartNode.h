﻿#ifndef ABSTRACTCHARTNODE_H
#define ABSTRACTCHARTNODE_H

#include "../GraphicsShowInterface/GraphicsShowInterface.h"
#include "AbstractNode.h"
#include "../GraphicsNodeInterface/GraphicsChartNodeInterface.h"




class AbstractChartNode:
		public AbstractNode,
        public GraphicsShowInterface,
		public GraphicsChartNodeInterface
{
	Chart*chart = new Chart;
public:
	AbstractChartNode();

	// GraphicsShowInterface interface
public:
	virtual QString getName() const override;
	virtual Chart *getChart() const override;

	// AbstractNode interface
public:
	virtual void process(AbstractNode *nextNode) override;

	// ModelCodingInterface interface
public:
	virtual CodeText dataTexting() const override;
	virtual CodeText getModelTypeName() const override;

	// AbstractNode interface
public:
	virtual ModelType getDataModelType() const override;
};







#endif // ABSTRACTCHARTNODE_H