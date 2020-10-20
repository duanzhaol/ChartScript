#include "BackgroundDialog.h"
#include "ui_BackgroundDialog.h"

BackgroundDialog::BackgroundDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::BackgroundDialog)
{
	ui->setupUi(this);
}

BackgroundDialog::~BackgroundDialog()
{
	delete ui;
}
