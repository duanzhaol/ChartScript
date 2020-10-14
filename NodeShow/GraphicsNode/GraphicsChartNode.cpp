#include "GraphicsAreaSeriesNode.h"
#include "GraphicsChartNode.h"
#include "GraphicsLineSeriesNode.h"
#include "GraphicsPieSeriesNode.h"
#include "GraphicsScatterSeriesNode.h"
#include "ui_GraphicsChartNode.h"
#include <QDebug>
#include <NodeShowWindow.h>

#pragma execution_character_set("utf-8")

GraphicsChartNode::GraphicsChartNode(Proxy *proxy, QWidget *parent) :
	AbstractGraphicsTopDualoutNode (proxy),
	ui(new Ui::GraphicsChartNode)
{
    ui->setupUi(this);

    /*设置qcombox文字居中显示，放一个lineedit进去 哈哈（设置lineedit文字居中）*/
    QLineEdit *lineEdit = new QLineEdit;
    lineEdit->setReadOnly(true);
    lineEdit->setAlignment(Qt::AlignCenter);
    ui->comboBox->setLineEdit(lineEdit);

	proxy->setWidget(this);
}

QHBoxLayout *GraphicsChartNode::insertAreaSeries()
{
	QHBoxLayout  *Series = new QHBoxLayout();

	GraphicsAreaSeriesNode *node1=new GraphicsAreaSeriesNode();

	node1->setTopProxy(this->getProxy());

	seriesList.append(static_cast<AbstractSeriesNode*>(node1)); //添加到序列list里用于罗获取到图结点的所有序列

	node1->setFixedSize(730,290);

    //twoNodes->addSpacerItem(new QSpacerItem(20,130));
	Series->addWidget(node1);

	ui->verticalLayout->addLayout(Series);

    //qDebug()<<seriesList;

    return Series;

}

QHBoxLayout *GraphicsChartNode::GraphicsChartNode::insertLineSeries()
{
    QHBoxLayout  *Series = new QHBoxLayout();

    GraphicsLineSeriesNode *node1=new GraphicsLineSeriesNode();

	node1->setTopProxy(this->getProxy());

	node1->setParent(this);

    seriesList.append(static_cast<AbstractSeriesNode*>(node1)); //添加到序列list里用于罗获取到图结点的所有序列

    node1->setFixedSize(730,150);

    //twoNodes->addSpacerItem(new QSpacerItem(20,130));
    Series->addWidget(node1);

	ui->verticalLayout->addLayout(Series);
    return Series;
}

QHBoxLayout *GraphicsChartNode::GraphicsChartNode::insertPieSeries()
{
    QHBoxLayout  *Series = new QHBoxLayout();

    GraphicsPieSeriesNode *node1=new GraphicsPieSeriesNode();

	node1->setTopProxy(this->getProxy());

    seriesList.append(static_cast<AbstractSeriesNode*>(node1)); //添加到序列list里用于罗获取到图结点的所有序列

    node1->setFixedSize(730,150);

    //twoNodes->addSpacerItem(new QSpacerItem(20,130));
    Series->addWidget(node1);

    ui->verticalLayout->addLayout(Series);
    return Series;
}

QHBoxLayout *GraphicsChartNode::GraphicsChartNode::insertScatterSeries()
{
    QHBoxLayout  *Series = new QHBoxLayout();

	GraphicsScatterSeriesNode *node1=new GraphicsScatterSeriesNode();

	node1->setTopProxy(this->getProxy());

    seriesList.append(static_cast<AbstractSeriesNode*>(node1)); //添加到序列list里用于罗获取到图结点的所有序列

    node1->setFixedSize(730,150);

    //twoNodes->addSpacerItem(new QSpacerItem(20,130));
    Series->addWidget(node1);

    ui->verticalLayout->addLayout(Series);
    return Series;
}


GraphicsChartNode::~GraphicsChartNode()
{
    delete ui;
}


NodeName GraphicsChartNode::getNodeName() const
{
    return ui->chartNodeName->text();
}

void GraphicsChartNode::setNodeName(const NodeName &newNodeName)
{
    ui->chartNodeName->setText(newNodeName);
}

QList<AbstractSeriesNode *> GraphicsChartNode::getAllSeries() const
{
    return seriesList;
}


OutputPort *GraphicsChartNode::getOutputPort()
{
    return ui->outputPort;
}

InputPort *GraphicsChartNode::getInputPort()
{
    return ui->inputPort;
}

void GraphicsChartNode::on_addSeriesButton_clicked()
{
    QString ChartType;
    ChartType=ui->comboBox->currentText();

    if(ChartType=="LineSeries"){
        qDebug()<<"LineSeries";
        insertLineSeries();
    }
    else if(ChartType=="PieSeries"){
        qDebug()<<"PieSeries";
        insertPieSeries();
    }
    else if(ChartType=="AreaSeries"){
        qDebug()<<"AreaSeries";
        insertAreaSeries();
    }
    else if(ChartType=="ScatterSeries"){
        qDebug()<<"ScatterSeries";
        insertScatterSeries();
    }
}
