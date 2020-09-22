#ifndef GRAPHICSSTARTNODE_H
#define GRAPHICSSTARTNODE_H

#include <QWidget>
#include <Interpreter/DataModel/StartNode.h>
#include "OutputPortWidget.h"

#pragma execution_character_set("utf-8")

namespace Ui {
class GraphicsStartNode;
}

class GraphicsStartNode : public OutputPortWidget,public StartNode
{
    Q_OBJECT

public:
    explicit GraphicsStartNode(QWidget *parent = nullptr);
    ~GraphicsStartNode();

private:
    Ui::GraphicsStartNode *ui;

	// InputPortWidget interface
public:
	virtual OutputPort *getOutputPort() override;

	// GraphicsNodeInterface interface
public:
	virtual NodeName getNodeName()const override;
	virtual void setNodeName(const NodeName &newNodeName) override;

	// QWidget interface
public:
	virtual void mousePressEvent(QMouseEvent *event) override;


};



#endif // GRAPHICSSTARTNODE_H
