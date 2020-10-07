#ifndef GRAPHICSARRAYNODEINTERFACE_H
#define GRAPHICSARRAYNODEINTERFACE_H

#include <QVariant>

class GraphicsArrayNodeInterface{
public:
    virtual QVariant::Type getElementType()const = 0;
    virtual void setElementType(QVariant::Type type) = 0;
};

#endif // GRAPHICSARRAYNODEINTERFACE_H
