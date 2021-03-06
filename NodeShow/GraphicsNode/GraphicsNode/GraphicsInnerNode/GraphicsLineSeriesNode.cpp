#include "GraphicsLineSeriesNode.h"
#include "ui_GraphicsLineSeriesNode.h"
#include <QDebug>

GraphicsLineSeriesNode::GraphicsLineSeriesNode(QWidget *parent) :
      ui(new Ui::GraphicsLineSeriesNode)
{
    ui->setupUi(this);

    ui->XDataArray->setParent(this);
    ui->YDataArray->setParent(this);

    ui->inputPort->setParent(this);
    ui->outputPort->setParent(this);

	auto initCombox = [](QComboBox*combox)->void{
		combox->clear();
		combox->addItem("int");
		combox->addItem("long long");
		combox->addItem("float");
		combox->addItem("double");
	};

	initCombox(ui->XDataArray->getCombobox());
	initCombox(ui->YDataArray->getCombobox());

    this->initName();


//    qDebug()<<ui->XDataArray->mapToGlobal(this->pos());
//    qDebug()<<ui->YDataArray->mapToGlobal(this->pos());


//    /*标题lineedit文字居中*/
//    ui->lineSeriesName->setAlignment( Qt::AlignHCenter);
}

GraphicsLineSeriesNode::~GraphicsLineSeriesNode()
{
    delete ui;
}

NodeName GraphicsLineSeriesNode::getNodeName() const
{
	return ui->LineSeriesName->text();
}

void GraphicsLineSeriesNode::setNodeName(const NodeName &newNodeName)
{
	ui->LineSeriesName->setText(newNodeName);
}

AbstractArrayNode *GraphicsLineSeriesNode::getXData() const
{
    return ui->XDataArray;
}

AbstractArrayNode *GraphicsLineSeriesNode::getYData() const
{
    return ui->YDataArray;
}

OutputPort *GraphicsLineSeriesNode::getOutputPort()
{
    return ui->outputPort;
}



InputPort *GraphicsLineSeriesNode::getInputPort()
{
    return ui->inputPort;
}


void GraphicsLineSeriesNode::setTopProxy(Proxy *value)
{
	AbstractGraphicsInnerDualputNode::setTopProxy(value);
	ui->XDataArray->setTopProxy(value);
	ui->YDataArray->setTopProxy(value);
}
