#include "PixmapItemDialog.h"
#include "ui_PixmapItemDialog.h"
#include <QFileDialog>

PixmapItemDialog::PixmapItemDialog(const QImage &current, QWidget *parent) :
	QDialog(parent),
	image(current),
	ui(new Ui::PixmapItemDialog)
{
	ui->setupUi(this);
	image = image.scaled(ui->imageShow->size());
	ui->imageShow->setPixmap(QPixmap::fromImage(image));
}

PixmapItemDialog::~PixmapItemDialog()
{
	delete ui;
}

QImage PixmapItemDialog::getImage() const
{
	return image;
}

void PixmapItemDialog::on_addImage_clicked()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open image"),
													R"(C:\)",
													tr("Images (*.png)"));
	image.load(fileName);
	image = image.scaled(ui->imageShow->size());
	ui->imageShow->setPixmap(QPixmap::fromImage(image));
	ui->fileNameShow->setText(fileName);
}


