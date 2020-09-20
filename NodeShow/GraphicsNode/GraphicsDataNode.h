#ifndef GraphicsDataNode_H
#define GraphicsDataNode_H

#include <QPushButton>
#include <QWidget>
#include "DualPortWidget.h"
#include "Interpreter/GraphicsNodeInterface/GraphicsDataNodeInterface.h"

namespace Ui {
class GraphicsDataNode;
}

using InputPort = QWidget;
using OutputPort = QWidget;

class GraphicsDataNode : public DualPortWidget,public GraphicsDataNodeInterface{
	Q_OBJECT

public:
    explicit GraphicsDataNode(QWidget *parent = nullptr);
	~GraphicsDataNode()override;

	// OutputPortWidget interface
public:
	virtual OutputPort *getOutputPort() override;

	// InputPortWidget interface
public:
	virtual InputPort *getInputPort() override;

private:
	Ui::GraphicsDataNode *ui;

    // GraphicsNodeInterface interface
public:
    virtual NodeName getNodeName() override;
    virtual void setNodeName(const NodeName&newNodeName) override;
    virtual AbstractNode *getInterpreterNode() override;

    // GraphicsDataNodeInterface interface
public:
    virtual QVariant getNodeData() override;
    virtual void setNodeData(const QVariant&newData) override;

};








#endif // GraphicsDataNode_H
