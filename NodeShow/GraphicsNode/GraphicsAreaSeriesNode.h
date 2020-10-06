#ifndef GRAPHICSAREASERIESNODE_H
#define GRAPHICSAREASERIESNODE_H

#include "DualPortWidget.h"
#include <QWidget>
#include <Interpreter/DataModel/SeriesModel/AbstractAreaSeries.h>
#include <GraphicsDataArrayNode.h>
#include <QLayout>

namespace Ui {
class GraphicsAreaSeriesNode;
}

class GraphicsAreaSeriesNode : public DualPortWidget,public AbstractAreaSeries
{
    Q_OBJECT



public:
    explicit GraphicsAreaSeriesNode(QWidget *parent = nullptr);
    ~GraphicsAreaSeriesNode();

private:
    Ui::GraphicsAreaSeriesNode *ui;
    QHBoxLayout* insertTwoNodes();
    int twoNodesNum;//记录延长的次数，每插入一行加一
    double nodeheight;

    // GraphicsNodeInterface interface
public:
    virtual NodeName getNodeName() const override;
    virtual void setNodeName(const NodeName &newNodeName) override;

    // GraphicsAreaNodeInterface interface
public:
    virtual AbstractArrayNode *getUpperXData() const override;
    virtual AbstractArrayNode *getUpperYData() const override;
    virtual AbstractArrayNode *getBottomXData() const override;
    virtual AbstractArrayNode *getBottomYData() const override;

    // OutputPortWidget interface
public:
    virtual OutputPort *getOutputPort() override;

    // InputPortWidget interface
public:
    virtual InputPort *getInputPort() override;

};

#endif // GRAPHICSAREASERIESNODE_H
