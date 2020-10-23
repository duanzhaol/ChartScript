#ifndef GRAPHICSLINESERIESNODE_H
#define GRAPHICSLINESERIESNODE_H

#include "AbstractGraphicsInnerDualputNode.h"
#include "../Dualputable.h"
#include <QWidget>
#include <Interpreter/DataModel/SeriesModel/AbstractLineSeriesNode.h>

namespace Ui {
class GraphicsLineSeriesNode;
}
/**
 * @brief
 * 折线图序列节点
 * @implements GraphicsXYNodeInterface
 * @implements GraphicsNodeInterface
 */
class GraphicsLineSeriesNode :
		public AbstractGraphicsInnerDualputNode,
		public AbstractLineSeriesNode
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

	// AbstractGraphicsInnerNode interface
public:
	virtual void setTopProxy(Proxy *value) override;
};

#endif // GRAPHICSLINESERIESNODE_H
