#include "PortWidget.h"
#include <QMouseEvent>
#include <QDebug>
#include <ConnectController.h>

PortWidget::PortWidget(QWidget *parent, Qt::WindowFlags f):
	QWidget(parent,f)
{
    connectToLineController();
}


void PortWidget::mousePressEvent(QMouseEvent *event)
{
	QWidget::mousePressEvent(event);
    event->accept();
}

void PortWidget::connectToLineController()
{
    connect(this,&PortWidget::PortClicked,
            ConnectController::getInstance(),&ConnectController::ConnectLine);//代替SINGAL和SLOT，会提示是否匹配，不需要参数
}

MovableProxyWidget *PortWidget::getProxywidget() const
{
    Q_ASSERT(proxywidget!=nullptr);
    return proxywidget;
}

void PortWidget::setProxywidget(MovableProxyWidget *value)
{
    proxywidget = value;
}





