#ifndef GRAPHICSSTARTNODE_H
#define GRAPHICSSTARTNODE_H

#include <QWidget>
#include <Interpreter/DataModel/StartNode.h>
#include "../Outputable.h"
#include "AbstractGraphicsTopNode.h"

#pragma execution_character_set("utf-8")

namespace Ui {
class GraphicsStartNode;
}
/**
 * @brief
 * 起点图节点
 * @implements Outputable
 */
class GraphicsStartNode :
		public AbstractGraphicsTopNode,
		public Outputable,
		public StartNode
{
    Q_OBJECT

public:
	explicit GraphicsStartNode(Proxy*proxy,QWidget *parent = nullptr);
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


	// Outputable interface
public:
	virtual QPointF getOutputPortCoordinate(QGraphicsItem *item) override;

public slots:
	void start();
};



#endif // GRAPHICSSTARTNODE_H
