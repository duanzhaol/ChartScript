#include "ConnectController.h"
#include "NodeShowWindow.h"
#include <QDebug>

ConnectController *ConnectController::getInstance()
{
    return instance;
}

void ConnectController::connectLineWuhu(Inputable *input, Outputable *output)
{
    ConnectLineItem *line =new ConnectLineItem(input,output);
    LineList.append(line);

    drawLine();
}

void ConnectController::drawLine()
{

    qDebug()<<"linelist";
    input =nullptr;
    output=nullptr;

    if(LineList.length()!=0){
        foreach(auto item,LineList)
        {
            NodeShowWindow::getInstance()->scene->addItem(item);
        }

        qDebug()<<input;
        qDebug()<<output;
    }
}



ConnectController::ConnectController()
{

}


void ConnectController::ConnectLine(AbstractGraphicsNode* port, AbstractGraphicsNode::PortType type)
{
    qDebug()<<"wuhuqifei";

    if(type==AbstractGraphicsNode::PortType::InputPort)
    {
        input=dynamic_cast<Inputable*>(port);
        qDebug()<<"inputPortSetted";

    }
    else if(type==AbstractGraphicsNode::PortType::OutputPort)
    {
        output=dynamic_cast<Outputable*>(port);
        qDebug()<<"outputPortSetted";
    }

    qDebug()<<"readytoConnect";

    if(input!=nullptr&&output!=nullptr)
    {

        qDebug()<<"readytoConnect";
        connectLineWuhu(input,output);
        qDebug()<<"Connected";
    }


}





ConnectController* ConnectController::instance=new ConnectController();
