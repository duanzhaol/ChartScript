#include "OutputPort.h"

#include <ConnectController.h>
#include <QMouseEvent>
#include <QDebug>
#include <NodeShowWindow.h>

OutputPort::OutputPort(QWidget*parent):QPushButton(parent)
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
//                        })");

    ConnectToController();
}

void OutputPort::ConnectToController()
{
    connect(this,&OutputPort::Outputclicked,ConnectController::getInstance(),
            &ConnectController::ConnectLine);//代替SINGAL和SLOT，会提示是否匹配，不需要参数
}

Outputable *OutputPort::getNode() const
{

    Outputable* node = dynamic_cast<Outputable*>(this->parent());

    Q_ASSERT_X(node != nullptr,__FILE__ + __LINE__,"do not forget to set parent");
    return node;
}



//void OutputPort::mousePressEvent(QMouseEvent *event)
//{
//    QPushButton::mouseReleaseEvent(event);
//    if(NodeShowWindow::getInstance()->mouseType==NodeShowWindow::NodeShowMouseType::Connect)
//    {
//        emit Outputclicked(this,AbstractGraphicsNode::PortType::OutputPort);
//    }
//}


void OutputPort::mouseReleaseEvent(QMouseEvent *event)
{
    QPushButton::mouseReleaseEvent(event);
    if(NodeShowWindow::getInstance()->mouseType==NodeShowWindow::NodeShowMouseType::Connect)
    {
        emit Outputclicked(this,AbstractGraphicsNode::PortType::OutputPort);
    }
}
