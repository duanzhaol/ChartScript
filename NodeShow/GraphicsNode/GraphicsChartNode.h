#ifndef GRAPHICSCHARTNODE_H
#define GRAPHICSCHARTNODE_H

#include "DualPortWidget.h"
#include <QWidget>
#include <Interpreter/DataModel/AbstractChartNode.h>
#include <QLineEdit>
#include <qboxlayout.h>
#pragma execution_character_set("utf-8")

namespace Ui {
class GraphicsChartNode;
}

class GraphicsChartNode : public DualPortWidget,public AbstractChartNode
{
    Q_OBJECT

public:
    explicit GraphicsChartNode(QWidget *parent = nullptr);
    ~GraphicsChartNode();
	QHBoxLayout *GraphicsChartNode::insertAreaSeries();
    QHBoxLayout *GraphicsChartNode::insertLineSeries();
    QHBoxLayout *GraphicsChartNode::insertPieSeries();
    QHBoxLayout *GraphicsChartNode::insertScatterSeries();

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

#endif // GRAPHICSCHARTNODE_H
