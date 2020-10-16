#include "GraphicsAreaSeriesNode.h"
#include "ui_GraphicsAreaSeriesNode.h"

#include <QBitmap>
#include <QPainter>
#include <GraphicsDataArrayNode.h>
#include<QDebug>

GraphicsAreaSeriesNode::GraphicsAreaSeriesNode(QWidget *parent) :
	ui(new Ui::GraphicsAreaSeriesNode)
{
    ui->setupUi(this);

    twoNodesNum=0;
    nodeheight=0;

//    /*标题lineedit文字居中*/
//    ui->AreaSeriesName->setAlignment( Qt::AlignHCenter); //数据节点的名字居中显示


//    insertTwoNodes();
//    insertTwoNodes();

}

GraphicsAreaSeriesNode::~GraphicsAreaSeriesNode()
{
    delete ui;
}

QHBoxLayout *GraphicsAreaSeriesNode::insertTwoNodes()
{



    QHBoxLayout  *twoNodes = new QHBoxLayout();

    GraphicsDataArrayNode *node1=new GraphicsDataArrayNode();
	node1->setTopProxy(this->getTopProxy());
    GraphicsDataArrayNode *node2=new GraphicsDataArrayNode();
	node2->setTopProxy(this->getTopProxy());
//    node1->setFixedSize(280,150);
//    node2->setFixedSize(280,150);

    twoNodes->addSpacerItem(new QSpacerItem(20,130));
    twoNodes->addWidget(node1);
    twoNodes->addWidget(node2);
    twoNodes->addSpacerItem(new QSpacerItem(20,130));

  //  ui->verticalLayout->addLayout(twoNodes);


//    twoNodesNum++;
//    nodeheight+=130;

//   // ui->resetButton->setGeometry(270,430+nodeheight,160,40);
//    this->resize(680,540+nodeheight);

    return twoNodes;
}

NodeName GraphicsAreaSeriesNode::getNodeName() const
{
    return ui->AreaSeriesName->text();
}

void GraphicsAreaSeriesNode::setNodeName(const NodeName &newNodeName)
{
   return ui->AreaSeriesName->setText(newNodeName);
}

AbstractArrayNode *GraphicsAreaSeriesNode::getUpperXData() const
{
    return ui->upperXArray;
}

AbstractArrayNode *GraphicsAreaSeriesNode::getUpperYData() const
{
   return ui->upperYArray;
}

AbstractArrayNode *GraphicsAreaSeriesNode::getBottomXData() const
{
   return ui->bottomXArray;
}

AbstractArrayNode *GraphicsAreaSeriesNode::getBottomYData() const
{
    return ui->bottomYArray;
}

OutputPort *GraphicsAreaSeriesNode::getOutputPort()
{
    return ui->outputPort;
}

InputPort *GraphicsAreaSeriesNode::getInputPort()
{
    return ui->inputPort;
}
