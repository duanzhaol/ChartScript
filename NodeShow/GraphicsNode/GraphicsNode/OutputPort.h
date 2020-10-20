#ifndef OUTPUTPORT_H
#define OUTPUTPORT_H

#include "AbstractGraphicsNode.h"
#include <QPushButton>

class Outputable;

class OutputPort:public QPushButton
{
    Q_OBJECT
public:
    OutputPort(QWidget*parent=nullptr);
    void ConnectToController();
    Outputable*getNode()const;
    // QWidget interface
protected:
    virtual void mousePressEvent(QMouseEvent *event) override;

signals:
    void Outputclicked(OutputPort*,AbstractGraphicsNode::PortType);
};

#endif // OUTPUTPORT_H
