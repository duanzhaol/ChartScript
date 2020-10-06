#include "ResizeTest.h"
#include "ui_ResizeTest.h"

ResizeTest::ResizeTest(QWidget *parent) :
      QWidget(parent),
      ui(new Ui::ResizeTest)
{
    ui->setupUi(this);
}

ResizeTest::~ResizeTest()
{
    delete ui;
}
