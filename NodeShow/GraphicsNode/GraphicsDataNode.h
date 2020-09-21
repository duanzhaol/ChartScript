﻿#ifndef GraphicsDataNode_H
#define GraphicsDataNode_H

#include <QPushButton>
#include <QWidget>
#include "DualPortWidget.h"
#include "Interpreter/DataModel/AbstractDataNode.h"

namespace Ui {
class GraphicsDataNode;
}

using InputPort = QWidget;
using OutputPort = QWidget;

class GraphicsDataNode : public DualPortWidget,public AbstractDataNode{
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
	virtual NodeName getNodeName()const override;
    virtual void setNodeName(const NodeName&newNodeName) override;

    // GraphicsDataNodeInterface interface
public:
	virtual QVariant getNodeData()const override;
    virtual void setNodeData(const QVariant&newData) override;

};








#endif // GraphicsDataNode_H
