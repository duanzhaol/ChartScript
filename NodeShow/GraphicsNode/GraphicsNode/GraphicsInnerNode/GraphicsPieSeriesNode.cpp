#include "GraphicsPieSeriesNode.h"
#include "ui_GraphicsPieSeriesNode.h"
#include <QDebug>


GraphicsPieSeriesNode::GraphicsPieSeriesNode(QWidget *parent) :
      ui(new Ui::GraphicsPieSeriesNode)
{
    ui->setupUi(this);

    /*初始化下拉框列表：Label是String，Number是int long long float double*/
    QComboBox* combox1 =ui->LabelArray->getCombobox();
    combox1->clear();
    combox1->addItem("String");

    QComboBox* combox2 =ui->NumberArray->getCombobox();
    combox2->clear();
    combox2->addItem("int");
    combox2->addItem("long long");
    combox2->addItem("float");
    combox2->addItem("double");

//    /*标题lineedit文字居中*/
//    ui->PieSeriesName->setAlignment( Qt::AlignHCenter);

	ui->LabelArray->setParent(this);
	ui->NumberArray->setParent(this);

    ui->inputPort->setParent(this);
    ui->outputPort->setParent(this);

	this->initName();


}

GraphicsPieSeriesNode::~GraphicsPieSeriesNode()
{
    delete ui;
}


NodeName GraphicsPieSeriesNode::getNodeName() const
{
    return ui->PieSeriesName->text();
}

void GraphicsPieSeriesNode::setNodeName(const NodeName &newNodeName)
{
    ui->PieSeriesName->setText(newNodeName);
}

AbstractArrayNode *GraphicsPieSeriesNode::getLabels() const
{
    return ui->LabelArray;
}

AbstractArrayNode *GraphicsPieSeriesNode::getData() const
{
    return ui->NumberArray;
}

OutputPort *GraphicsPieSeriesNode::getOutputPort()
{
    return ui->outputPort;
}

InputPort *GraphicsPieSeriesNode::getInputPort()
{
    return ui->inputPort;
}


void GraphicsPieSeriesNode::setTopProxy(Proxy *value)
{
	AbstractGraphicsInnerDualputNode::setTopProxy(value);
	ui->NumberArray->setTopProxy(value);
	ui->LabelArray->setTopProxy(value);
}
