#ifndef PIXMAPITEMDIALOG_H
#define PIXMAPITEMDIALOG_H

#include <QDialog>

namespace Ui {
class PixmapItemDialog;
}

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
