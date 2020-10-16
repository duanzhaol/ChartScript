#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::addSubWindow(AbstractInitializer *windowInitializer)
{
	ui->tabWidget->addTab(windowInitializer->getWidget(),windowInitializer->getWindowName());
}
