#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QHBoxLayout>


MainWindow::MainWindow(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	this->setWindowTitle("Chart Script");
	this->setWindowIcon(QIcon(R"(:/image/img/windowIcon)"));
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::addSubWindow(AbstractInitializer *windowInitializer)
{
	auto index = ui->tabWidget->addTab(windowInitializer->getWidget(),windowInitializer->getWindowName());
}
