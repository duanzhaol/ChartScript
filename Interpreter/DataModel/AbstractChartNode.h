#ifndef ABSTRACTCHARTNODE_H
#define ABSTRACTCHARTNODE_H

#include "../GraphicsShowInterface/GraphicsShowInterface.h"
#include "AbstractNode.h"
#include "../GraphicsNodeInterface/GraphicsChartNodeInterface.h"


/**
 * @brief
 * 抽象统计图节点，包括对节点内部序列process顺序的调度以及组装并生成统计图。
 * @note
 * 实现了GraphicsShowInterface，将统计图发往设计部分
 * 实现了GraphicsChartNodeInterface，使之能实例化为统计图节点
 */

class AbstractChartNode:
		public AbstractNode,
        public GraphicsShowInterface,
		public GraphicsChartNodeInterface
{
	Chart*chart = nullptr;
	bool d_isProcess = false;
public:
	AbstractChartNode();

	// GraphicsShowInterface interface
public:
	virtual QString getName() const override;
	virtual Chart *getChart() const override;
	bool isProcess()const;

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
