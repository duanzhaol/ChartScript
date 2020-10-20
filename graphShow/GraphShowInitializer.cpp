#include "GraphShowInitializer.h"
#include "mywindow.h"
#include <QtCharts/QChart>

GraphShowInitializer::GraphShowInitializer()
{

}

void GraphShowInitializer::init()
{
	myWindow *myWindows=new myWindow();
	GraphicsScene *sc = new GraphicsScene();
	myWindows->setScene(sc);
	this->widget = myWindows;
}

AbstractInitializer* GraphShowInitializer::getInstance()
{
	return instance;
}

GraphShowInitializer *GraphShowInitializer::instance = new GraphShowInitializer;


QString GraphShowInitializer::getWindowName() const
{
	return QStringLiteral("Chart Design");
}
