#include "GraphShowInitializer.h"
#include "mywindow.h"

GraphShowInitializer::GraphShowInitializer()
{

}

void GraphShowInitializer::init()
{
	myWindow *myWindows=new myWindow();
	GraphicsScene *sc = new GraphicsScene();
	myWindows->setScene(sc);
	myWindows->show();
}

InitInterface* GraphShowInitializer::getInstance()
{
	return instance;
}

GraphShowInitializer *GraphShowInitializer::instance = new GraphShowInitializer;
