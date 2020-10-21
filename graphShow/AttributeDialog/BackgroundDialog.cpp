#include "BackgroundDialog.h"
#include "ui_BackgroundDialog.h"

#include <QColorDialog>
#include <QFileDialog>
#include <QMessageBox>

BackgroundDialog::BackgroundDialog(const Result &defaultResult, QWidget *parent) :
	QDialog(parent),
	result(defaultResult),
	ui(new Ui::BackgroundDialog)
{
	ui->setupUi(this);
	ui->brushColor->setPalette(QPalette(result.brush.color()));
	ui->brushColor->setFlat(true);
	ui->brushColor->setAutoFillBackground(true);
	if(result.image.has_value()){
		result.image = result.image->scaled(ui->imageShow->size());
		ui->imageShow->setPixmap(QPixmap::fromImage(result.image.value()));
	}
	ui->brushStyle->setCurrentIndex(static_cast<int>(result.brush.style()));
}

BackgroundDialog::~BackgroundDialog()
{
	delete ui;
}

void BackgroundDialog::on_addImage_clicked()
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
	result.image = QImage();
	if(fileName == "")return;
	if(result.image->load(fileName)==false){
		QMessageBox::information(this,QStringLiteral("提示"),QStringLiteral("图片打开失败"));
		return;
	}
	result.image = result.image->scaled(ui->imageShow->size());
	ui->imageShow->setPixmap(QPixmap::fromImage(result.image.value()));
	ui->fileNameShow->setText(fileName);
}

void BackgroundDialog::on_deleteImage_clicked()
{
	ui->fileNameShow->setText("");
	result.image.reset();
	ui->imageShow->setPixmap(QPixmap());
}

void BackgroundDialog::on_brushColor_clicked()
{
	QColor color = QColorDialog::getColor(Qt::GlobalColor::white,this,QStringLiteral("设置背景"),
										  QColorDialog::ColorDialogOption::ShowAlphaChannel);
	result.brush.setColor(color);
	ui->brushColor->setPalette(QPalette(color));
}

void BackgroundDialog::on_buttonBox_accepted()
{
	result.brush.setStyle(static_cast<Qt::BrushStyle>(ui->brushStyle->currentIndex()));
	emit confirm(result);
	this->deleteLater();
}
