#include "DataModel/StartNode.h"
#include "DataModel/AbstractDataNode.h"
#include <QDebug>
#include <QVariant>
#include <QColor>
#include "Interpreter/InterpreterController.h"

class Start:public GraphicsNodeInterface{


	// GraphicsNodeInterface interface
public:
	virtual NodeName* getNodeName() override{
		return new QString("fuck");
	}
	virtual void setNodeName(NodeName *newNodeName) override{

	}
};

class Data:public GraphicsDataNodeInterface{

	QVariant *data;

	// GraphicsNodeInterface interface
public:
	Data(QVariant* data):data(data){
	}
	virtual NodeName* getNodeName() override{
		return new QString("mother");
	}
	virtual void setNodeName(NodeName *newNodeName) override{}

	// GraphicsDataNodeInterface interface
public:
	virtual QVariant *getNodeData() override{
		return data;
	}
	virtual void setNodeData(QVariant *newData) override{
		data = newData;
	}
};

int main(){
	try{
		auto start = new StartNode(new Start);
		auto controller = new InterpreterController(start);

		auto node1 = new AbstractDataNode(new Data(new QVariant(10)));

		auto v = new QVariant(QColor(Qt::GlobalColor::red));

		QVariant vv((QColor(Qt::GlobalColor::red)));

		auto node2 = new AbstractDataNode(new Data(v));
		controller->addConnect(node1,node2);
		controller->addConnect(start,node1);
		qDebug()<<*node2->getNode()->getNodeData()<<endl;
		controller->interprete();
		qDebug()<<*node2->getNode()->getNodeData();
	}
	catch (InterpreterException &e) {
		qDebug()<<e.getWhy()<<endl;
	}

	return 0;
}
