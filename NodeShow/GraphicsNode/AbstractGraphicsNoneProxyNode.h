#ifndef ABSTRACTGRAPHICSNONEPROXYNODE_H
#define ABSTRACTGRAPHICSNONEPROXYNODE_H

#include "DualPortWidget.h"
#include "PortWidget.h"



class AbstractGraphicsNoneProxyNode:public PortWidget,public DualPortWidget
{
public:
    AbstractGraphicsNoneProxyNode();

    // OutputPortWidget interface
public:
    virtual QPointF getOutputPortCoordinate(QGraphicsItem *item) override;
    virtual OutputPort *getOutputPort() override;

    // InputPortWidget interface
public:
    virtual QPointF getInputPortCoordinate(QGraphicsItem *item) override;
    virtual InputPort *getInputPort() override;
};

#endif // ABSTRACTGRAPHICSNONEPROXYNODE_H
