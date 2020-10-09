#include "PortWidget.h"
#include <QMouseEvent>
#include <QDebug>
#include <ConnectController.h>

PortWidget::PortWidget(QWidget *parent, Qt::WindowFlags f):
	QWidget(parent,f)
{
    connect(this,&PortWidget::PortClicked,
            ConnectController::getInstance(),&ConnectController::ConnectLine);//代替SINGAL和SLOT，会提示是否匹配，不需要参数
}


void PortWidget::mousePressEvent(QMouseEvent *event)
{
	QWidget::mousePressEvent(event);
	event->accept();
}

