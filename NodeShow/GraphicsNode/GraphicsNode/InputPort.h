#ifndef INPUTPORT_H
#define INPUTPORT_H

#include "AbstractGraphicsNode.h"
#include <QObject>
#include <QPushButton>


class Inputable;

/**
 * @brief
 * 各个图节点的输入端口
 */

class InputPort:public QPushButton
{
    Q_OBJECT
public:
    InputPort(QWidget*parent=nullptr);
    void ConnectToController();
    Inputable*getNode()const;

    // QWidget interface
//protected:
//    virtual void mousePressEvent(QMouseEvent *event) override;


signals:
    void Inputclicked(InputPort*,AbstractGraphicsNode::PortType);

    // QWidget interface
protected:
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
};

#endif // INPUTPORT_H
