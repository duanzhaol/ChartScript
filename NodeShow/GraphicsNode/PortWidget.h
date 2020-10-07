#ifndef PORTWIDGET_H
#define PORTWIDGET_H

#include <QWidget>

class PortWidget:public QWidget{
    Q_OBJECT
public:
	PortWidget(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());

protected:
	virtual void mousePressEvent(QMouseEvent *event) override;
};



#endif // PORTWIDGET_H
