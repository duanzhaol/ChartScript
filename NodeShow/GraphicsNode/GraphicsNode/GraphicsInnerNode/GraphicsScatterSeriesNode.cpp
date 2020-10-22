#include "GraphicsScatterSeriesNode.h"
#include "ui_GraphicsScatterSeriesNode.h"

GraphicsScatterSeriesNode::GraphicsScatterSeriesNode(QWidget *parent) :
      ui(new Ui::GraphicsScatterSeriesNode)
{
    ui->setupUi(this);

//    /*标题lineedit文字居中*/
//    ui->ScatterSeriesName->setAlignment( Qt::AlignHCenter);
	ui->XDataArray->setParent(this);
	ui->YDataArray->setParent(this);

    ui->inputPort->setParent(this);
    ui->outputPort->setParent(this);

    /*初始化下拉框列表：dataArray是int long long float double*/
    QComboBox* combox1 =ui->XDataArray->getCombobox();
    combox1->clear();
    combox1->addItem("int");
    combox1->addItem("long long");
    combox1->addItem("float");
    combox1->addItem("double");

    QComboBox* combox2 =ui->YDataArray->getCombobox();
    combox2->clear();
    combox2->addItem("int");
    combox2->addItem("long long");
    combox2->addItem("float");
    combox2->addItem("double");





	this->initName();

}

GraphicsScatterSeriesNode::~GraphicsScatterSeriesNode()
{
    delete ui;
}

NodeName GraphicsScatterSeriesNode::getNodeName() const
{
    return ui->ScatterSeriesName->text();
}

void GraphicsScatterSeriesNode::setNodeName(const NodeName &newNodeName)
{
    ui->ScatterSeriesName->setText(newNodeName);
}

AbstractArrayNode *GraphicsScatterSeriesNode::getXData() const
{
    return ui->XDataArray;
}

AbstractArrayNode *GraphicsScatterSeriesNode::getYData() const
{
    return ui->YDataArray;
}

OutputPort *GraphicsScatterSeriesNode::getOutputPort()
{
    return ui->outputPort;
}

InputPort *GraphicsScatterSeriesNode::getInputPort()
{
    return ui->inputPort;
}


void GraphicsScatterSeriesNode::setTopProxy(Proxy *value)
{
	AbstractGraphicsInnerDualputNode::setTopProxy(value);
	ui->XDataArray->setTopProxy(value);
	ui->YDataArray->setTopProxy(value);
}
