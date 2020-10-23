#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QObject>
#include "../InitInterface/AbstractInitializer.h"

namespace Ui {
class MainWindow;
}

/**
 * @brief 程序主窗口，组转所有模块的窗口。
 */
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
