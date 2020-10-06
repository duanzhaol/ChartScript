#include "GraphicsPieSeries.h"
#include "ui_GraphicsPieSeries.h"

GraphicsPieSeries::GraphicsPieSeries(QWidget *parent) :
      QWidget(parent),
      ui(new Ui::GraphicsPieSeries)
{
    ui->setupUi(this);
}

GraphicsPieSeries::~GraphicsPieSeries()
{
    delete ui;
}
