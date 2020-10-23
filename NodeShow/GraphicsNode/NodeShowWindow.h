#ifndef NODESHOWWINDOW_H
#define NODESHOWWINDOW_H

#include "ConnectController.h"
#include "NodeListWidgetItem.h"

#include <QGraphicsScene>
#include <QListWidgetItem>
#include <QMainWindow>
#include "TableView/GraphicsShowInterface/TableArrayInterface.h"

namespace Ui {
class NodeShowWindow;
}
/**
 * @brief 图节点模块的主窗口。
 * 包含图节点模块资源的初始化、窗口的组织
 */
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
    void setLcdNumber(int number);

signals:
    void MouseTypechanged();
    void newArray(TableArrayInterface*);

private slots:
	void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_listWidget_2_itemDoubleClicked(QListWidgetItem *item);

    void on_MoveButton_clicked();

    void on_ConnectButton_clicked();

    void on_DeleteButton_clicked();


//public slots:
//    void recieveNodeArrays(QListWidgetItem *item);


private:
    Ui::NodeShowWindow *ui;
	void init();
};

#endif // NODESHOWWINDOW_H
