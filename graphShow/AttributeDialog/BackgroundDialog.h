#ifndef BACKGROUNDDIALOG_H
#define BACKGROUNDDIALOG_H

#include <QDialog>

namespace Ui {
class BackgroundDialog;
}

class BackgroundDialog : public QDialog
{
	Q_OBJECT

public:
	explicit BackgroundDialog(QWidget *parent = nullptr);
	~BackgroundDialog();

private:
	Ui::BackgroundDialog *ui;
};

#endif // BACKGROUNDDIALOG_H
