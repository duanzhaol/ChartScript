#ifndef ABSTRACTLINESERIESNODE_H
#define ABSTRACTLINESERIESNODE_H

#include "AbstractSeriesNode.h"
#include "../../GraphicsNodeInterface/GraphicsXYNodeInterface.h"
#include <QtCharts/QLineSeries>

/**
 * @brief
 * 抽象折线图序列节点。
 * process方法收集折线图内部数据生成散点序列
 */

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
	virtual CodeText getModelTypeName() const override;

	// AbstractNode interface
public:
	virtual ModelType getDataModelType() const override;
};

#endif // ABSTRACTLINESERIESNODE_H
