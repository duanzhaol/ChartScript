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
    NodeShowWindow::getInstance()->show();
//    splash.finish();

}

NodeShowInitializer* NodeShowInitializer::instance = new NodeShowInitializer;
