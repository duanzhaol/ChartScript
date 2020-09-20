#ifndef GRAPHICSNODEINTERFACE_H
#define GRAPHICSNODEINTERFACE_H

#include <QString>
#include "Interpreter/DataModel/AbstractNode.h"

using NodeName = QString;

class AbstractNode;

class GraphicsNodeInterface{
public:
<<<<<<< HEAD
	virtual NodeName getNodeName() = 0;
	virtual void setNodeName(const NodeName&newNodeName) = 0;
	virtual AbstractNode*  getInterpreterNode() = 0;
=======
    virtual NodeName getNodeName() = 0;
    virtual void setNodeName(const NodeName&newNodeName) = 0;
    virtual class AbstractNode*getInterpreterNode() = 0;
>>>>>>> 87457d909012540b5e73e9eb33caab08ead87b99
};

#endif // GRAPHICSNODEINTERFACE_H
