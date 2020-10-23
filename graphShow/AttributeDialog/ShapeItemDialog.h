#ifndef SHAPEITEMDIALOG_H
#define SHAPEITEMDIALOG_H

#include <QDialog>

namespace Ui {
class ShapeItemDialog;
}

/**
 * @brief
 * 基本形状元素对话框的返回结果，包括用户对基本设计元素的边框和填充设置的颜色和样式
 * @see ShapeItemDialog
 * @see AbstractGraphicsShapeItem
 */
struct ShapeAttribute{
	QColor penColor,brushColor;
	Qt::PenStyle penStyle;
	Qt::BrushStyle brushStyle;
	ShapeAttribute operator=(const ShapeAttribute&other){
		this->penColor = other.penColor;
		this->brushColor = other.brushColor;
		this->penStyle = other.penStyle;
		this->brushStyle = other.brushStyle;
		return *this;
	}
};

/**
 * @brief
 * 用于设置基本设计元素的边框和填充
 * @see AbstractGraphicsShapeItem
 */
class ShapeItemDialog : public QDialog
{
	Q_OBJECT

	void setButtonColor(QPushButton*button,const QColor&color);
	QColor getButtonColor(QPushButton*button)const;

public:
	explicit ShapeItemDialog(const ShapeAttribute&defaultAttribute,QWidget *parent = nullptr);
	~ShapeItemDialog();


signals:
	void confirm(const ShapeAttribute&attribute);

private slots:
	void on_penColor_clicked();

	void on_brushColor_clicked();

	void on_ShapeItemDialog_accepted();

private:
	Ui::ShapeItemDialog *ui;
};

#endif // SHAPEITEMDIALOG_H
