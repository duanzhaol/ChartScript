#include "ShapeItemDialog.h"
#include "ui_ShapeItemDialog.h"
#include <QColorDialog>

void ShapeItemDialog::setButtonColor(QPushButton *button, const QColor &color)
{
	button->setPalette(QPalette(color));
	button->setFlat(true);
	button->setAutoFillBackground(true);
}

QColor ShapeItemDialog::getButtonColor(QPushButton *button) const
{
	return button->palette().color(QPalette::ColorRole::Button);
}

ShapeItemDialog::ShapeItemDialog(const ShapeAttribute &defaultAttribute, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::ShapeItemDialog)
{
	ui->setupUi(this);
	setButtonColor(ui->penColor,defaultAttribute.penColor);
	setButtonColor(ui->brushColor,defaultAttribute.brushColor);
	ui->penStyle->setCurrentIndex(defaultAttribute.penStyle);
	ui->brushStyle->setCurrentIndex(defaultAttribute.brushStyle);
}

ShapeItemDialog::~ShapeItemDialog()
{
	delete ui;
}

void ShapeItemDialog::on_penColor_clicked()
{
	QColor color = QColorDialog::getColor(getButtonColor(ui->penColor),
										  this,QStringLiteral("选择线条颜色"));
	ui->penColor->setPalette(QPalette(color));
}

void ShapeItemDialog::on_brushColor_clicked()
{
	QColor color = QColorDialog::getColor(getButtonColor(ui->brushColor),
										  this,QStringLiteral("选择填充颜色颜色"));
	ui->brushColor->setPalette(QPalette(color));
}

void ShapeItemDialog::on_ShapeItemDialog_accepted()
{
	struct ShapeAttribute attribute{getButtonColor(ui->penColor),
								   getButtonColor(ui->brushColor),
								   static_cast<Qt::PenStyle>(ui->penStyle->currentIndex()),
								   static_cast<Qt::BrushStyle>(ui->brushStyle->currentIndex())};
	emit confirm(attribute);
}
