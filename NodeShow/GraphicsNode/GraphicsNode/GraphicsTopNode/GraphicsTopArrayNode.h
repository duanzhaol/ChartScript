#ifndef GRAPHICSTOPARRAYNODE_H
#define GRAPHICSTOPARRAYNODE_H

#include "../GraphicsInnerNode/GraphicsDataArrayNode.h"
#include "AbstractGraphicsTopDualoutNode.h"
#include "MovableProxyWidget.h"

#include <TableView/GraphicsShowInterface/TableArrayInterface.h>
/**
 * @brief
 * 顶层数组节点。
 * 通过控制GraphicsInnerDataArrayNode实现对数组数据的图节点化
 */

class GraphicsTopArrayNode:public AbstractGraphicsTopDualoutNode
{
	/**
	 * @brief
	 * 顶层数组节点的内部数据节点。
	 * 重写了GraphicsDataArrayNode的数据操作方式，将数据源改为TableArrayInterface，
	 * 实现与表格模块的通信
	 */
	class GraphicsInnerDataArrayNode:public GraphicsDataArrayNode{

		TableArrayInterface*dataSource = nullptr;

		// GraphicsNodeInterface interface
	public:
		GraphicsInnerDataArrayNode(TableArrayInterface*dataSource);
		virtual NodeName getNodeName() const override;
		virtual void setNodeName(const NodeName &newNodeName) override;

		// GraphicsDataNodeInterface interface
	public:
		virtual QVariant getNodeData() const override;
		virtual void setNodeData(const QVariant &newData) override;

		// GraphicsArrayNodeInterface interface
	public:
		virtual QVariant::Type getElementType() const override;
		virtual void setElementType(QVariant::Type type) override;
	};
	GraphicsInnerDataArrayNode*innerNode = nullptr;
public:
	GraphicsTopArrayNode(TableArrayInterface*dataSource,MovableProxyWidget*proxy);

	// Outputable interface
public:
	virtual OutputPort *getOutputPort() override;

	// Inputable interface
public:
	virtual InputPort *getInputPort() override;

};

#endif // GRAPHICSTOPARRAYNODE_H
