#ifndef NODESHOWWINDOW_H
#define NODESHOWWINDOW_H

#include "ConnectController.h"
#include "NodeListWidgetItem.h"

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
    enum class NodeShowMouseType{Move,Connect,Delete};
    NodeShowMouseType mouseType=NodeShowMouseType::Move;

private slots:
	void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_listWidget_2_itemDoubleClicked(NodeListWidgetItem *item);

    void on_MoveButton_clicked();

    void on_ConnectButton_clicked();

    void on_DeleteButton_clicked();

public slots:
    void recieveNodeArrays(QListWidgetItem *item);

private:
	Ui::NodeShowWindow *ui;
	void init();
};

#endif // NODESHOWWINDOW_H
