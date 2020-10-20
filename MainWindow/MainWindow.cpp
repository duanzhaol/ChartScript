#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QHBoxLayout>


MainWindow::MainWindow(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	this->setWindowTitle("Chart Script");
	this->setWindowIcon(QIcon(R"(:/image/img/ChartScript_Logo.jpg)"));
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::addSubWindow(AbstractInitializer *windowInitializer)
{
	ui->tabWidget->addTab(windowInitializer->getWidget(),windowInitializer->getWindowName());
}
