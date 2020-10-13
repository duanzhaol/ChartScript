#ifndef PORTWIDGET_H
#define PORTWIDGET_H

#include <QWidget>
#include <MovableProxyWidget.h>

class PortWidget:public QWidget{
    Q_OBJECT
public:
    //PortWidget()=default;
    PortWidget(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    enum class PortType{InputPort,OutputPort};

    MovableProxyWidget *getProxywidget() const;
    void setProxywidget(MovableProxyWidget *value);

protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
    void connectToLineController();


private:
    MovableProxyWidget* proxywidget =nullptr;

signals:
    void PortClicked(PortWidget*,PortType);
};



#endif // PORTWIDGET_H
