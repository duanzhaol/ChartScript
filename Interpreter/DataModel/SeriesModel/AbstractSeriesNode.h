#ifndef ABSTRACTSERIESNODE_H
#define ABSTRACTSERIESNODE_H

#include "../AbstractNode.h"
#include <QtCharts/QAbstractSeries>

/**
 * @brief
 * 抽象序列节点。
 * process方法收集序列内部的数据生成一个序列
 */

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
