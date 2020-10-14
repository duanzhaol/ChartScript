#ifndef GRAPHICSCHARTNODE_H
#define GRAPHICSCHARTNODE_H

#include "Dualputable.h"
#include <QWidget>
#include <Interpreter/DataModel/AbstractChartNode.h>
#include <QLineEdit>
#include <qboxlayout.h>
#include "AbstractGraphicsTopDualoutNode.h"
#pragma execution_character_set("utf-8")

namespace Ui {
class GraphicsChartNode;
}

class GraphicsChartNode :
		public AbstractGraphicsTopDualoutNode,
		public AbstractChartNode
{
    Q_OBJECT

public:
	explicit GraphicsChartNode(Proxy*proxy,QWidget *parent = nullptr);
    ~GraphicsChartNode();
    QHBoxLayout *insertAreaSeries();
    QHBoxLayout *insertLineSeries();
    QHBoxLayout *insertPieSeries();
    QHBoxLayout *insertScatterSeries();

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
