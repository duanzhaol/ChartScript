#ifndef GRAPHICSNODEINTERFACE_H
#define GRAPHICSNODEINTERFACE_H

#include <QString>

using NodeName = QString;

class AbstractNode;

class GraphicsNodeInterface{
public:
	virtual NodeName getNodeName() = 0;
	virtual void setNodeName(const NodeName&newNodeName) = 0;
	virtual AbstractNode*  getInterpreterNode() = 0;
};

#endif // GRAPHICSNODEINTERFACE_H
