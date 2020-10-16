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

	this->initName();
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
	QString chartType;
	chartType=ui->comboBox->currentText();

	if(chartType=="LineSeries"){
		this->insertSeries<GraphicsLineSeriesNode>(QSize(730,150));
    }
	else if(chartType=="PieSeries"){
		this->insertSeries<GraphicsPieSeriesNode>(QSize(730,150));
    }
	else if(chartType=="AreaSeries"){
		this->insertSeries<GraphicsAreaSeriesNode>(QSize(730,290));
    }
	else if(chartType=="ScatterSeries"){
		this->insertSeries<GraphicsScatterSeriesNode>(QSize(730,150));
    }
}
