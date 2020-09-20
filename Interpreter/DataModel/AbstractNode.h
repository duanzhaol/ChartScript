#ifndef ABSTRACTNODE_H
#define ABSTRACTNODE_H
#include <QHash>
#include "../GraphicsNodeInterface/GraphicsNodeInterface.h"


/**
 * @brief The AbstractNode class,the base class of all DataModel which also called node
 */

using NodeName = QString;

class AbstractNode{
protected:
	/** storge inputNodes` pointers which connected by this node*/
	QHash<NodeName,AbstractNode*> nextNodes;
    /** this node`data interface of GraphicsShow Model */
    class GraphicsNodeInterface*node = nullptr;
	/** @brief throw corresponding exception if this node can not connect to given node.
	 * @throw InterpreterException
	*/
	virtual void verifyConnectable(AbstractNode*node);

public:
    AbstractNode(class GraphicsNodeInterface*node);
	/** start interpret from this(make this to root node) */
	virtual void process();
	virtual ~AbstractNode();
	/** add node after call @see virtual void verifyConnectable(AbstractNode*node).
	 *  call this function to connect from this(as output) to node(as input).
	*/
	void addNextNodes(AbstractNode*node);
	/** call this function to dis connect from this (as output) to node(as input).
	 *  nothing will happen if this has not been connected with node before.
	*/
	void removeNextNode(AbstractNode*node);
	/** getter for GraphicsNodeInterface*/
    virtual class GraphicsNodeInterface *getNode() const;
	/** setter for GraphicsNodeInterface*/
    void setNode(class GraphicsNodeInterface *value);
};

#endif // ABSTRACTNODE_H
