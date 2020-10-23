#ifndef ABSTRACTNODE_H
#define ABSTRACTNODE_H
#include <QHash>
#include <QMultiHash>
#include "../Interpreter/ModelCodingInterface.h"
#include "../GraphicsNodeInterface/GraphicsNodeInterface.h"

//! 每一个节点的名称
using NodeName = QString;

/**
 * @brief
 * 每一个节点的类型
 */
enum class ModelType:char{
	Invalid,Start,Data,Array,Chart,AreaSeries,LineSeries,PieSeries,ScatterSeries
};

/**
 * @brief
 * 所有抽象节点的父类，所有编译数据结构的基本单元。
 * 包括每种节点内部处理方式的方法：
 * @codeline virtual void process(AbstractNode*nextNode);
 */

class AbstractNode:
		public GraphicsNodeInterface,
		public ModelCodingInterface
{
protected:

	void initName();

public:
	/** @brief throw corresponding exception if this node can not connect to given node.
	 * @throw InterpreterException
	*/
	virtual void verifyConnectable(AbstractNode*node);

	AbstractNode();
	/** start interpret from this(make this to root node) */
	virtual void process(AbstractNode*nextNode);
	virtual ~AbstractNode();

	/**
	 * @brief testNodeNameIfDuplicate
	 * @warning call this function before you modify node name at everywhere and everytime to
	 * ensure that every node have unique node name,or previous node which have same name
	 * as this node will be covered.
	 */
	void testNodeNameIfDuplicate(const NodeName&nodeName)const;

	// ModelCodingInterface interface
public:
	virtual CodeText getModelName() const override;

	virtual ModelType getDataModelType() const = 0;

	static ModelType nameToType(const QString&typeName);
	static QString typeToName(const ModelType type);

};

#endif // ABSTRACTNODE_H
