#ifndef GRAPHICSNODEINTERFACE_H
#define GRAPHICSNODEINTERFACE_H

#include <QString>
#include "Interpreter/DataModel/AbstractNode.h"

using NodeName = QString;

class GraphicsNodeInterface{
public:
    virtual NodeName getNodeName() = 0;
    virtual void setNodeName(const NodeName&newNodeName) = 0;
    virtual class AbstractNode*getInterpreterNode() = 0;
};

#endif // GRAPHICSNODEINTERFACE_H
