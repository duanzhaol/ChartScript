#ifndef GRAPHICSAREASERIESNODE_H
#define GRAPHICSAREASERIESNODE_H

#include "../Dualputable.h"
#include <QWidget>
#include <Interpreter/DataModel/SeriesModel/AbstractAreaSeries.h>
#include "GraphicsDataArrayNode.h"
#include <QLayout>
#include "AbstractGraphicsInnerDualputNode.h"

namespace Ui {
class GraphicsAreaSeriesNode;
}
/**
 * @brief
 * 序列图节点
 */
class GraphicsAreaSeriesNode :
		public AbstractGraphicsInnerDualputNode,
		public AbstractAreaSeries
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


	// AbstractGraphicsInnerNode interface
public:
	virtual void setTopProxy(Proxy *value) override;
};

#endif // GRAPHICSAREASERIESNODE_H
