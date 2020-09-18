﻿#include "GraphicsDataNode.h"
#include "ui_GraphicsDataNode.h"
#include <QBitmap>
#include <QListView>
#include <QPainter>
#include  <QDebug>
#include <QMessageBox>

GraphicsDataNode::GraphicsDataNode(QWidget *parent) :
	PortWidget(parent),
	ui(new Ui::GraphicsDataNode)
{

  ui->setupUi(this);
  ui->comboBox->setView(new QListView());
  ui->lineEdit->setEnabled(true);

  QWidget::setWindowFlags(Qt::FramelessWindowHint);//设置窗口无边框

  //设置关于窗体为圆角：构造一个QBitmap类对象，再用QPainter类对象在bmp上绘制一个半径为20像素的圆角矩形

  QBitmap bmp(this->QWidget::size());

  bmp.fill();

  QPainter p(&bmp);

  p.setPen(Qt::NoPen);

  p.setBrush(Qt::blue);

  p.drawRoundedRect(bmp.rect(),30,30);

  setMask(bmp);


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

