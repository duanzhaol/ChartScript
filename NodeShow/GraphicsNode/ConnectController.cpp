#include "ConnectController.h"
#include "NodeShowWindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QMessageBox>
#include <Interpreter/Interpreter/InterpreterController.h>
#pragma execution_character_set("utf-8")

ConnectController *ConnectController::getInstance()
{
    return instance;
}

void ConnectController::connectLineWuhu(Inputable *input, Outputable *output)
{


	try {
		InterpreterController::getGlobalInstance()->addConnect(
			dynamic_cast<AbstractNode*>(input),
			dynamic_cast<AbstractNode*>(output)
			);
	} catch (ImplicitTypeConversion &e) {
		QMessageBox::warning(nullptr,"错误",e.getWhy());
		clearPort();
		return;
	} catch(TypeUnconvertible &e){
		QMessageBox::information(nullptr,"警告",e.getWhy());
	}

    ConnectLineItem *line =new ConnectLineItem(input,output);
	NodeShowWindow::getInstance()->scene->addItem(line);
    LineList.append(line);

    drawLine();
}

void ConnectController::drawLine()
{

//    qDebug()<<input;
//    qDebug()<<output;
    qDebug()<<"ConnectController::drawLine()";
    input =nullptr;
    output=nullptr;
    NodeShowWindow::getInstance()->setLcdNumber(0);
    //    inputOrigin=nullptr;
//    outputOrigin=nullptr;


//        qDebug()<<input;
//        qDebug()<<output;
}



ConnectController::ConnectController()
{

}


void ConnectController::ConnectLine(QPushButton* port, AbstractGraphicsNode::PortType type)
{
    if(type==AbstractGraphicsNode::PortType::InputPort)
    {

        input=dynamic_cast<InputPort*>(port)->getNode();
        NodeShowWindow::getInstance()->setLcdNumber(1);
    }
    else if(type==AbstractGraphicsNode::PortType::OutputPort)
    {

        output=dynamic_cast<OutputPort*>(port)->getNode();
        NodeShowWindow::getInstance()->setLcdNumber(1);
    }

//    qDebug()<<port;
//    qDebug()<<input<<output;
//    qDebug()<<(void*)input<<(void*)output;

    if((void*)input==(void*)output){
		QMessageBox::information(nullptr,"提示", "不能自己连自己哦！");

        input =nullptr;
        output=nullptr;
//        inputOrigin=nullptr;
//        outputOrigin=nullptr;

        return;
    }

//    if(input!=nullptr&&output!=nullptr&&inputOrigin!=nullptr&&outputOrigin!=nullptr)
//    {

    if(input!=nullptr&&output!=nullptr)
    {
        connectLineWuhu(input,output);
    }


}

void ConnectController::clearPort()
{
    input=nullptr;
    output=nullptr;
    NodeShowWindow::getInstance()->setLcdNumber(0);
	QMessageBox::information(nullptr, "提示", "待连线结点已清空");
}





ConnectController* ConnectController::instance=new ConnectController();
