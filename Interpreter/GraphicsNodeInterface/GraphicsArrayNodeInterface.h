#ifndef GRAPHICSARRAYNODEINTERFACE_H
#define GRAPHICSARRAYNODEINTERFACE_H

#include <QVariant>

/**
 * @interface GraphicsArrayNodeInterface
 * 数列节点接口，实现该接口的子类能够成为数列节点的编译单元
 */

class GraphicsArrayNodeInterface{
public:
    virtual QVariant::Type getElementType()const = 0;
    virtual void setElementType(QVariant::Type type) = 0;
};

#endif // GRAPHICSARRAYNODEINTERFACE_H
