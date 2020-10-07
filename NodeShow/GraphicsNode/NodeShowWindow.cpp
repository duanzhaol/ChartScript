#include "NodeShowWindow.h"
#include "ui_NodeShowWindow.h"

NodeShowWindow::NodeShowWindow(QWidget *parent) :
      QMainWindow(parent),
      ui(new Ui::NodeShowWindow)
{
    ui->setupUi(this);
}

NodeShowWindow::~NodeShowWindow()
{
    delete ui;
}
