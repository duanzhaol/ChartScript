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
	QString fileName = QFileDialog::getOpenFileName(this,
													QStringLiteral("打开图片"),
													R"(C:\)",
													tr("All image(*.bmp *.jpg *.jpeg *.png *.ppm *.xbm *.xpm *.gif *.pbm *.pgm)"
													   ";;Windows Bitmap(*.bmp)"
													   ";;Joint Photographic Experts Group(*.jpg)"
													   ";;Joint Photographic Experts Group(*.jpeg)"
													   ";;Portable Network Graphics(*.png)"
													   ";;Portable Pixmap(*.ppm)"
													   ";;X11 Bitmap(*.xbm)"
													   ";;X11 Pixmap(*.xpm)"
													   ";;Graphic Interchange Format(*.gif)"
													   ";;Portable Bitmap(*.pbm)"
													   ";;Portable Graymap(*.pgm)"));
	image.load(fileName);
	image = image.scaled(ui->imageShow->size());
	ui->imageShow->setPixmap(QPixmap::fromImage(image));
	ui->fileNameShow->setText(fileName);
}


