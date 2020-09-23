#include "Port.h"
#include "ui_Port.h"

Port::Port(QWidget *parent) :
      QWidget(parent),
      ui(new Ui::Port)
{
    ui->setupUi(this);
}

Port::~Port()
{
    delete ui;
}
