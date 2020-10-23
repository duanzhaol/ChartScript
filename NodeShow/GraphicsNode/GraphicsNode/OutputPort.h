#ifndef OUTPUTPORT_H
#define OUTPUTPORT_H

#include "AbstractGraphicsNode.h"
#include <QPushButton>

class Outputable;
/**
 * @brief
 * 各个图节点的输出端口
 */
class OutputPort:public QPushButton
{
    Q_OBJECT
public:
    OutputPort(QWidget*parent=nullptr);
    void ConnectToController();
    Outputable*getNode()const;
    // QWidget interface
//protected:
//    virtual void mousePressEvent(QMouseEvent *event) override;

signals:
    void Outputclicked(OutputPort*,AbstractGraphicsNode::PortType);

    // QWidget interface
protected:
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
};

#endif // OUTPUTPORT_H
