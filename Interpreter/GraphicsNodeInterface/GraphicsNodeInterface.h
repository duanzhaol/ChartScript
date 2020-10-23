#ifndef GRAPHICSNODEINTERFACE_H
#define GRAPHICSNODEINTERFACE_H

#include <QString>
using NodeName = QString;

/**
 * @interface GraphicsNodeInterface
 * @brief 抽象节点接口，所有编译单元接口的父类
 */

class GraphicsNodeInterface{
public:

    virtual NodeName getNodeName()const = 0;
    virtual void setNodeName(const NodeName&newNodeName) = 0;

};

#endif // GRAPHICSNODEINTERFACE_H
