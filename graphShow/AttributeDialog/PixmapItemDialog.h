#ifndef PIXMAPITEMDIALOG_H
#define PIXMAPITEMDIALOG_H

#include <QDialog>

namespace Ui {
class PixmapItemDialog;
}

/**
 * @brief
 * 添加图片设计元素时弹出的对话框，用于进行图片的选择。
 * @see GraphicsImageItem
 */
class PixmapItemDialog : public QDialog
{
	Q_OBJECT
	QImage image;
public:
	explicit PixmapItemDialog(const QImage&current,QWidget *parent = nullptr);
	~PixmapItemDialog();
	QImage getImage()const;

private slots:
	void on_addImage_clicked();

private:
	Ui::PixmapItemDialog *ui;
};

#endif // PIXMAPITEMDIALOG_H
