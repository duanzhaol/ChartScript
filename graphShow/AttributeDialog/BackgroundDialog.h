#ifndef BACKGROUNDDIALOG_H
#define BACKGROUNDDIALOG_H

#include <QDialog>
#include <optional>

namespace Ui {
class BackgroundDialog;
}

/**
 * @brief
 * 用于在图表设计时添加背景图片或设置背景颜色的对话框。
 */

class BackgroundDialog : public QDialog
{
	Q_OBJECT

public:
	/**
	 * @brief
	 * 对话框获取到用户设置的背景后，用这个结构体来返回设置结果
	 */
	struct Result{
		//! 用户设置的图片。如果optional中未空，则表示清除图片
		std::optional<QImage>image;
		//! 用户设置的背景填充，包括颜色和样式
		QBrush brush;
	}result;

	explicit BackgroundDialog(const Result&defaultResult,QWidget *parent = nullptr);
	~BackgroundDialog();

private slots:

	void on_addImage_clicked();

	void on_deleteImage_clicked();

	void on_brushColor_clicked();

	void on_buttonBox_accepted();

private:
	Ui::BackgroundDialog *ui;

signals:
	void confirm(const Result&);
};

#endif // BACKGROUNDDIALOG_H
