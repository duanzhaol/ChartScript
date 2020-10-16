#include "MainWindowInitializer.h"
#include "MainWindow.h"
#include "graphShow/GraphShowInitializer.h"
#include "NodeShow/NodeShowInitializer.h"


MainWindowInitializer::MainWindowInitializer()
{

}

MainWindowInitializer *MainWindowInitializer::getInstance()
{
	return instace;
}


void MainWindowInitializer::init()
{

	MainWindow * mainWindow = new MainWindow;

	NodeShowInitializer::getInstance()->init();
	mainWindow->addSubWindow(NodeShowInitializer::getInstance());

	GraphShowInitializer::getInstance()->init();
	mainWindow->addSubWindow(GraphShowInitializer::getInstance());

	mainWindow->showMaximized();
}

MainWindowInitializer* MainWindowInitializer::instace = new MainWindowInitializer;


QString MainWindowInitializer::getWindowName() const
{
	return QStringLiteral("Main Window");
}
