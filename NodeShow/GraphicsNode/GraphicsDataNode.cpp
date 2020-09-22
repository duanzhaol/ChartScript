#include "GraphicsDataNode.h"
#include "ui_GraphicsDataNode.h"
#include <QBitmap>
#include <QListView>
#include <QPainter>
#include  <QDebug>
#include <QMessageBox>
#include "Interpreter/DataModel/AbstractDataNode.h"
#include "../../UTools/UniqueNamer.h"

GraphicsDataNode::GraphicsDataNode(QWidget *parent) :
	PortWidget(parent),
	ui(new Ui::GraphicsDataNode)
{

  ui->setupUi(this);
  ui->comboBox->setView(new QListView());


  QWidget::setWindowFlags(Qt::FramelessWindowHint);//设置窗口无边框

  //设置关于窗体为圆角：构造一个QBitmap类对象，再用QPainter类对象在bmp上绘制一个半径为20像素的圆角矩形

  QBitmap bmp(this->QWidget::size());

  bmp.fill();

  QPainter p(&bmp);

  p.setPen(Qt::NoPen);

  p.setBrush(Qt::blue);

  p.drawRoundedRect(bmp.rect(),30,30);

  setMask(bmp);

  ui->dataNodeName->setText(UniqueNamerPool::getNamer(NamerSeed::GraphShow).getUniqueName());

}

GraphicsDataNode::~GraphicsDataNode()
{
    delete ui;
}

InputPort *GraphicsDataNode::getInputPort()
{
    return ui->inputPort;
}

OutputPort *GraphicsDataNode::getOutputPort()
{
    return ui->outputPort;
}



NodeName GraphicsDataNode::getNodeName()const
{
    return ui->dataNodeName->text();
}

void GraphicsDataNode::setNodeName(const NodeName&newNodeName)
{
    ui->dataNodeName->setText(newNodeName);
}



QVariant GraphicsDataNode::getNodeData()const
{
    return QVariant::fromValue(ui->dataNodeData->text());
}

void GraphicsDataNode::setNodeData(const QVariant&newData)
{
    ui->dataNodeData->setText(newData.toString());
}
