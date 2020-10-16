#ifndef NODESHOWWINDOW_H
#define NODESHOWWINDOW_H

#include "ConnectController.h"

#include <QGraphicsScene>
#include <QListWidgetItem>
#include <QMainWindow>

namespace Ui {
class NodeShowWindow;
}

class NodeShowWindow : public QMainWindow
{
	Q_OBJECT

	static NodeShowWindow*instance;

public:
	explicit NodeShowWindow(QWidget *parent = nullptr);
	~NodeShowWindow();

	static void createWindow();
	static NodeShowWindow*getInstance();

	QGraphicsScene*scene = new QGraphicsScene;

private slots:
	void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
	Ui::NodeShowWindow *ui;
	void init();
};

#endif // NODESHOWWINDOW_H
