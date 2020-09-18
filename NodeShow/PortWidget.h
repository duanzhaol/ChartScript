#ifndef PORTWIDGET_H
#define PORTWIDGET_H

#include <QWidget>

class PortWidget:public QWidget{
public:
	PortWidget(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());

	// QWidget interface
protected:
	virtual void mousePressEvent(QMouseEvent *event) override;
};



#endif // PORTWIDGET_H
