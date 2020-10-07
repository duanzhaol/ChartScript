#include "PortWidget.h"
#include <QMouseEvent>
#include <QDebug>


PortWidget::PortWidget(QWidget *parent, Qt::WindowFlags f):
	QWidget(parent,f)
{

}


void PortWidget::mousePressEvent(QMouseEvent *event)
{
	QWidget::mousePressEvent(event);
	event->accept();
}

