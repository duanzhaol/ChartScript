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

    NodeShowWindow* nsw=new NodeShowWindow();


    nsw->show();
//    splash.finish();

}

NodeShowInitializer* NodeShowInitializer::instance = new NodeShowInitializer;
