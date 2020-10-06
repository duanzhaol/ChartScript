#ifndef GraphicsPieSeriesNode_H
#define GraphicsPieSeriesNode_H

#include "DualPortWidget.h"
#include <QWidget>
#include <Interpreter/DataModel/SeriesModel/AbstractPieSeries.h>
#pragma execution_character_set("utf-8")

namespace Ui {
class GraphicsPieSeriesNode;
}

class GraphicsPieSeriesNode : public DualPortWidget,public AbstractPieSeries
{
    Q_OBJECT

public:
    explicit GraphicsPieSeriesNode(QWidget *parent = nullptr);
    ~GraphicsPieSeriesNode();

private:
    Ui::GraphicsPieSeriesNode *ui;

    // GraphicsNodeInterface interface
public:
    virtual NodeName getNodeName() const override;
    virtual void setNodeName(const NodeName &newNodeName) override;

    // GraphicsPieNodeInterface interface
public:
    virtual AbstractArrayNode *getLabels() const override;
    virtual AbstractArrayNode *getData() const override;

    // OutputPortWidget interface
public:
    virtual OutputPort *getOutputPort() override;

    // InputPortWidget interface
public:
    virtual InputPort *getInputPort() override;
};

#endif // GraphicsPieSeriesNode_H
