#ifndef BACKGROUNDDIALOG_H
#define BACKGROUNDDIALOG_H

#include <QDialog>
#include <optional>

namespace Ui {
class BackgroundDialog;
}

class BackgroundDialog : public QDialog
{
	Q_OBJECT

public:
	struct Result{
		std::optional<QImage>image;
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
