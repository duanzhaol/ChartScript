#include "ConnectController.h"
#include "NodeShowWindow.h"
#include <QDebug>
#include <QMessageBox>
#pragma execution_character_set("utf-8")

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

    qDebug()<<input;
    qDebug()<<output;
    qDebug()<<"linelist";
    input =nullptr;
    output=nullptr;
    inputOrigin=nullptr;
    outputOrigin=nullptr;

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
        inputOrigin= port;
        input=dynamic_cast<Inputable*>(port);
        qDebug()<<"inputPortSetted";

    }
    else if(type==AbstractGraphicsNode::PortType::OutputPort)
    {
        outputOrigin= port;
        output=dynamic_cast<Outputable*>(port);
        qDebug()<<"outputPortSetted";
    }

    if(inputOrigin==outputOrigin){
        QMessageBox::information(NULL, "提示", "不能自己连自己哦！");

        input =nullptr;
        output=nullptr;
        inputOrigin=nullptr;
        outputOrigin=nullptr;

        return;
    }

    if(input!=nullptr&&output!=nullptr&&inputOrigin!=nullptr&&outputOrigin!=nullptr)
    {

        qDebug()<<"readytoConnect";
        connectLineWuhu(input,output);
        qDebug()<<"Connected";
    }


}





ConnectController* ConnectController::instance=new ConnectController();
