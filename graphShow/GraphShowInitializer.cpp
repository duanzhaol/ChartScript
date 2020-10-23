#include "GraphShowInitializer.h"
#include "GraphShowWindow.h"
#include <QtCharts/QChart>

GraphShowInitializer::GraphShowInitializer()
{

}

void GraphShowInitializer::init()
{
	GraphShowWindow *myWindows=new GraphShowWindow();
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
