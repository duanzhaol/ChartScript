#ifndef ABSTRACTNODE_H
#define ABSTRACTNODE_H
#include <QHash>
#include <QMultiHash>
#include "../Interpreter/ModelCodingInterface.h"
#include "../GraphicsNodeInterface/GraphicsNodeInterface.h"

/**
 * @brief The AbstractNode class,the base class of all DataModel which also called node
 */

using NodeName = QString;

class AbstractNode:
		public GraphicsNodeInterface,
		public ModelCodingInterface
{
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
};

#endif // ABSTRACTNODE_H
