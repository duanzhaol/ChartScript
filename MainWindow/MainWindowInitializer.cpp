#include "MainWindowInitializer.h"
#include "MainWindow.h"
#include "graphShow/GraphShowInitializer.h"
#include "NodeShow/NodeShowInitializer.h"
#include "TableView/TableViewInitialer.h"
#include "TableView/TableView.h"
#include "NodeShow/GraphicsNode/NodeShowWindow.h"


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

    TableViewInitialer::getInstance()->init();
    mainWindow->addSubWindow(TableViewInitialer::getInstance());

    widget->connect(
			  dynamic_cast<TableView*>(TableViewInitialer::getInstance()->getWidget()),
              &TableView::newArray,
			  dynamic_cast<NodeShowWindow*>(NodeShowInitializer::getInstance()->getWidget()),
              &NodeShowWindow::newArray
        );

	mainWindow->showMaximized();
}

MainWindowInitializer* MainWindowInitializer::instace = new MainWindowInitializer;


QString MainWindowInitializer::getWindowName() const
{
	return QStringLiteral("Main Window");
}
