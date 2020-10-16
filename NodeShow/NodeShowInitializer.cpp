#include "NodeShowInitializer.h"

#include <ConnectController.h>
#include <NodeShowWindow.h>

NodeShowInitializer::NodeShowInitializer()
{

}

NodeShowInitializer *NodeShowInitializer::getInstance()
{
	return instance;
}




void NodeShowInitializer::init()
{


	NodeShowWindow::createWindow();
	this->widget = NodeShowWindow::getInstance();
//    splash.finish();

}

NodeShowInitializer* NodeShowInitializer::instance = new NodeShowInitializer;


QString NodeShowInitializer::getWindowName() const
{
	return QStringLiteral("Visual Programe");
}
