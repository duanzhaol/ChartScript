#include<QApplication>
#include <QDebug>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <GraphicsDataArrayNode.h>
#include "ConnectLineItem.h"
#include "MovableDualPortProxyWidget.h"
#include "GraphicsStartNode.h"
#include "Interpreter/Interpreter/InterpreterController.h"
#include "Interpreter/Interpreter/ModelCodingInterpreter.h"
#include "GraphicsDataArrayNode.h"
#include "Interpreter/Interpreter/CodeModeling/CodeModelingInterpreter.h"

auto getProxy1(){
	auto node = new GraphicsDataNode;
	auto proxy = new MovableDualPortProxyWidget;
	proxy->setDualPortWidget(node);
	return proxy;
}

auto getProxy2(){
	auto node = new GraphicsDataArrayNode;
	auto proxy = new MovableDualPortProxyWidget;
	proxy->setDualPortWidget(node);
	return proxy;
}

auto getStart(){
	auto proxy = new MovableOutputPortProxyWidget;
	proxy->setOutputPortWidget(new GraphicsStartNode);
	return proxy;
}


int main(int argc,char*argv[]){
	QApplication app(argc,argv);

	try {
		auto view = new QGraphicsView;
		auto scene = new QGraphicsScene;
		view->setScene(scene);

		auto p1 = getProxy1(),p2 = getProxy1();
		auto p3=getProxy2();
		auto s = getStart();

		scene->addItem(p1);
		scene->addItem(p2);
		scene->addItem(p3);
		scene->addItem(s);

		auto line = new ConnectLineItem(p2,p1);
		auto line2 = new ConnectLineItem(p1,s);
		auto line3 = new ConnectLineItem(p3,s);

		InterpreterController::getGlobalInstance()->setStartNode(
					dynamic_cast<AbstractNode*>(s->getOutputPortWidget()));

		scene->addItem(line);
		scene->addItem(line2);

		view->setStyleSheet(R"(QGraphicsView{ background-image:url(:/img/img/beijing.jpg);})");//设置scene背景
		view->showMaximized();
		view->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);


		ModelCodingInterpreter *coding = new ModelCodingInterpreter(InterpreterController::getGlobalInstance());

		qDebug().noquote()<<coding->coding();

		CodeText code(R"(Init:{
Data "Digit Node2" QString "起飞"
Array " 数列节点" QString ["233","344"]
Data "Digit Node1" QString "起飞"
}
Connection:{
[*] -> " 数列节点"
"Digit Node1" -> "Digit Node2"
[*] -> "Digit Node1"
})");

		auto result = CodeModelingInterpreter::interprete(code);

		for(auto&ele:result.allNodes){
			qDebug().noquote()<<ele->getModelTypeName()<<" "<<ele->getNodeName()<<endl;
		}

	} catch (InterpreterException&e) {
		qDebug()<<e.getWhy()<<endl;
	}

	return app.exec();
}
