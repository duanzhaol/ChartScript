#include "GraphicsDataNode.h"
#include "ui_GraphicsDataNode.h"
#include <QBitmap>
#include <QListView>
#include <QPainter>
#include  <QDebug>
#include <QMessageBox>
#include "Interpreter/DataModel/AbstractDataNode.h"

GraphicsDataNode::GraphicsDataNode(QWidget *parent) :
	PortWidget(parent),
	ui(new Ui::GraphicsDataNode)
{

  ui->setupUi(this);
  ui->comboBox->setView(new QListView());

  /*设置qcombox文字居中显示，放一个lineedit进去（设置lineedit文字居中）*/
  QLineEdit *lineEdit = new QLineEdit;
  lineEdit->setReadOnly(true);
  lineEdit->setAlignment(Qt::AlignCenter);
  ui->comboBox->setLineEdit(lineEdit);

  /*两个单独lineedit文字居中*/
  ui->dataNodeName->setAlignment( Qt::AlignHCenter); //数据节点的名字居中显示
  ui->dataNodeData->setAlignment( Qt::AlignHCenter); //数据节点的数据居中显示

  /*
  QWidget::setWindowFlags(Qt::FramelessWindowHint);//设置窗口无边框
  //设置关于窗体为圆角：构造一个QBitmap类对象，再用QPainter类对象在bmp上绘制一个半径为20像素的圆角矩形
  QBitmap bmp(this->QWidget::size());
  bmp.fill();
  QPainter p(&bmp);
  p.setPen(Qt::NoPen);
  p.setBrush(Qt::blue);
  p.drawRoundedRect(bmp.rect(),30,30);
  setMask(bmp);
  */

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
