#ifndef INTERPRETERCONTROLLER_H
#define INTERPRETERCONTROLLER_H

#include "../DataModel/StartNode.h"

/**
 * @brief The InterpreterController class
 * use to Handle a Interprete`s Process.
 *
 * @example
 *
 *
 */

class InterpreterController{
	StartNode* startNode = nullptr;
public:
	/** the unique start node of this process */
	InterpreterController(StartNode*startNode);
	/** call this function to start a compile process*/
	void interprete();
	/**
	 * call this function to establish a connection.
	 * this function call AbstractNode::void addNextNodes(AbstractNode*node) inside,
	 * so it will throw some exceptions.
	 * @see AbstractNode::void addNextNodes(AbstractNode*node)
	 */
	void addConnect(AbstractNode*outputNode,AbstractNode*inputNode);
	/** call this function to destroy a connection.
	 *  this function will do nothing if two nodes are not connected yet.
	*/
	void removeConnect(AbstractNode*outputNode,AbstractNode*inputNode);
};

#endif // INTERPRETERCONTROLLER_H
