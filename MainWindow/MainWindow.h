#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "../InitInterface/AbstractInitializer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();
	void addSubWindow(AbstractInitializer*windowInitializer);

private:
	Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
