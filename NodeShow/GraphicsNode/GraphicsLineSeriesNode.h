#ifndef GRAPHICSLINESERIESNODE_H
#define GRAPHICSLINESERIESNODE_H

#include "DualPortWidget.h"
#include <QWidget>
#include <Interpreter/DataModel/SeriesModel/AbstractLineSeriesNode.h>

namespace Ui {
class GraphicsLineSeriesNode;
}

class GraphicsLineSeriesNode : public DualPortWidget,public AbstractLineSeriesNode
{
    Q_OBJECT

public:
    explicit GraphicsLineSeriesNode(QWidget *parent = nullptr);
    ~GraphicsLineSeriesNode();

private:
    Ui::GraphicsLineSeriesNode *ui;

    // GraphicsNodeInterface interface
public:
    virtual NodeName getNodeName() const override;
    virtual void setNodeName(const NodeName &newNodeName) override;

    // GraphicsXYNodeInterface interface
public:
    virtual AbstractArrayNode *getXData() const override;
    virtual AbstractArrayNode *getYData() const override;

    // OutputPortWidget interface
public:
    virtual OutputPort *getOutputPort() override;

    // InputPortWidget interface
public:
    virtual InputPort *getInputPort() override;
};

#endif // GRAPHICSLINESERIESNODE_H
