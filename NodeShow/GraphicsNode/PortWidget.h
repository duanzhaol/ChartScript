#ifndef PORTWIDGET_H
#define PORTWIDGET_H

#include <QWidget>

class PortWidget:public QWidget{
    Q_OBJECT
public:
    //PortWidget()=default;
    PortWidget(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    enum class PortType{InputPort,OutputPort};

protected:
	virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void connectToLineController();

signals:
    void PortClicked(PortWidget*,PortType);
};



#endif // PORTWIDGET_H
