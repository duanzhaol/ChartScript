#include "InputPort.h"

#include <ConnectController.h>
#include <QMouseEvent>
#include "Inputable.h"
#include <QDebug>

InputPort::InputPort(QWidget*parent):QPushButton(parent)
{
//    this->setStyleSheet(R"(QPushButton {
//                             border: 1px solid #333333;
//                             padding: 4px;
//                             border-radius:8px;

//                             background-color: rgb(255, 255, 255);
//                         }

//                         QPushButton:hover {
//                             background-color: rgb(52, 167, 255);
//                             border-color: #444444;
//                         }

//                         QPushButton:pressed {
//                             background-color: rgb(46, 39, 239);
//                             border-color: #333333;
//                             color: yellow;
//                         }

//                         QPushButton:disabled {
//                             color: #333333;
//                         })");

    ConnectToController();


}

void InputPort::ConnectToController()
{
    connect(this,&InputPort::Inputclicked,ConnectController::getInstance(),
            &ConnectController::ConnectLine);//代替SINGAL和SLOT，会提示是否匹配，不需要参数
}

Inputable *InputPort::getNode() const
{
    auto node = dynamic_cast<Inputable*>(this->parent());
    Q_ASSERT_X(node != nullptr,__FILE__ + __LINE__,"do not forget to set parent");
    return node;
}

void InputPort::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<1;
    QPushButton::mouseReleaseEvent(event);
    qDebug()<<2;

    qDebug()<<3;
    emit Inputclicked(this,AbstractGraphicsNode::PortType::InputPort);
    qDebug()<<4;


}

