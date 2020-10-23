#ifndef GRAPHICSCHARTNODE_H
#define GRAPHICSCHARTNODE_H

#include "../Dualputable.h"
#include <QWidget>
#include <Interpreter/DataModel/AbstractChartNode.h>
#include <QLineEdit>
#include <qboxlayout.h>
#include "AbstractGraphicsTopDualoutNode.h"
#pragma execution_character_set("utf-8")

namespace Ui {
class GraphicsChartNode;
}

/**
 * @brief
 * 统计图图节点
 * @implements GraphicsShowInterface
 * @implements GraphicsChartNodeInterface
 * @implements GraphicsNodeInterface
 */

class GraphicsChartNode :
		public AbstractGraphicsTopDualoutNode,
		public AbstractChartNode
{
    Q_OBJECT

	template<class GraphicsSeries>
	void insertSeries(const QSize&&nodeSize);

public:
	explicit GraphicsChartNode(Proxy*proxy,QWidget *parent = nullptr);
    ~GraphicsChartNode();

private:
    Ui::GraphicsChartNode *ui;
    QList<AbstractSeriesNode *> seriesList;

    // GraphicsNodeInterface interface
public:
    virtual NodeName getNodeName() const override;
    virtual void setNodeName(const NodeName &newNodeName) override;

    // GraphicsChartNodeInterface interface
public:
    virtual QList<AbstractSeriesNode *> getAllSeries() const override;

    // OutputPortWidget interface
public:
    virtual OutputPort *getOutputPort() override;

    // InputPortWidget interface
public:
    virtual InputPort *getInputPort() override;


private slots:
    void on_addSeriesButton_clicked();

};

#define START_TEMPLATE

#ifdef START_TEMPLATE
#include "ui_GraphicsChartNode.h"
#include <type_traits>
#include<QMessageBox>

template<class GraphicsSeries>
void GraphicsChartNode::insertSeries(const QSize&&nodeSize)
{
    QHBoxLayout  *series = new QHBoxLayout();
    GraphicsSeries *node1=new GraphicsSeries(this);
    node1->setTopProxy(this->getProxy());
    seriesList.append(static_cast<AbstractSeriesNode*>(node1)); //添加到序列list里用于罗获取到图结点的所有序列
    node1->setFixedSize(nodeSize);
    series->addWidget(node1);
    this->ui->verticalLayout->addLayout(series);
}

#endif

#undef START_TEMPLATE

#endif // GRAPHICSCHARTNODE_H
