#include "ConnectController.h"
#include "NodeShowWindow.h"
#include <QDebug>
#include <QMessageBox>
#include <Interpreter/Interpreter/InterpreterController.h>
#pragma execution_character_set("utf-8")

ConnectController *ConnectController::getInstance()
{
    return instance;
}

void ConnectController::connectLineWuhu(Inputable *input, Outputable *output)
{

	if(InterpreterController::getGlobalInstance()->hasConncted(
				dynamic_cast<AbstractNode*>(output),
				dynamic_cast<AbstractNode*>(input))
			){
		QMessageBox::warning(nullptr,"警告","已经连接过了");
		clearPort();
		return;
	}

	if(dynamic_cast<AbstractGraphicsNode*>(input)==dynamic_cast<AbstractGraphicsNode*>(output)){
		QMessageBox::warning(nullptr,"警告","不能自己连自己");
		clearPort();
		return;
	}

	try {
		InterpreterController::getGlobalInstance()->addConnect(
			dynamic_cast<AbstractNode*>(output),
			dynamic_cast<AbstractNode*>(input)
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
    LineList.insert(line->LineIndex,line);

    drawLine();
}

void ConnectController::drawLine()
{

    qDebug()<<"ConnectController::drawLine()";
    input =nullptr;
    output=nullptr;
    NodeShowWindow::getInstance()->setLcdNumber(0);
}

ConnectLineItem *ConnectController::getLineItem(int index)
{
    QHash<int, ConnectLineItem*>::iterator i = LineList.find(index);
    if (i != LineList.end()) {
        return i.value();
    }
    else{
        return nullptr;
    }
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
#ifdef QT_DEBUG
	QMessageBox::information(nullptr, "提示", "待连线结点已清空");
#endif
}

void ConnectController::removeLineItem(ConnectLineItem *item)
{
    NodeShowWindow::getInstance()->scene->removeItem(item);
    InterpreterController::getGlobalInstance()->
        removeConnect(dynamic_cast<AbstractNode*>(item->outputNode),
                      dynamic_cast<AbstractNode*>(item->inputNode));
    LineList.remove(item->LineIndex);
	delete item;
}

ConnectController* ConnectController::instance=new ConnectController();
