#ifndef GRAPHICSSCATTERSERIESNODE_H
#define GRAPHICSSCATTERSERIESNODE_H

#include "AbstractGraphicsInnerDualputNode.h"
#include "../Dualputable.h"
#include <QWidget>
#include <Interpreter/DataModel/SeriesModel/AbstractScatterSeriesNode.h>
#include <QComboBox>

namespace Ui {
class GraphicsScatterSeriesNode;
}

class GraphicsScatterSeriesNode :
		public AbstractGraphicsInnerDualputNode,
		public AbstractScatterSeriesNode
{
    Q_OBJECT

public:
    explicit GraphicsScatterSeriesNode(QWidget *parent = nullptr);
    ~GraphicsScatterSeriesNode();

private:
    Ui::GraphicsScatterSeriesNode *ui;

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

#endif // GRAPHICSSCATTERSERIESNODE_H
