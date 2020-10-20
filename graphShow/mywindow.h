#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QWidget>
#include"GraphicsScene.h"
#include"ListWidget/ListWidgetItem.h"
#include"ListWidget/ListWidget.h"
#include"item/ShapeItem/GraphicsRectItem.h"
namespace Ui {
class myWindow;
}
/**
 * @brief 主窗口类
 */
class myWindow : public QWidget
{
    Q_OBJECT

	ListWidget*listWidget1,*listWidget2;

public:
    /**
     * @brief 平淡无奇的构造函数
     * @param parent
     */
    explicit myWindow(QWidget *parent = nullptr);
    /**
     * @brief 设置当前窗口的Qgraphicsview的scene
     * @param GraphicsScene
     */
    void setScene(GraphicsScene *myScene);
    ~myWindow();

private slots:
    /**
     * @brief 点击主题按钮，弹出主题窗口
     */
    void on_pushButton_theme_clicked();

    void sendChart_Transmitter(QListWidgetItem*item);
    void initialListWidget();

    void on_pushButton_shadow_clicked();

    void on_pushButton_top_clicked();

	void setCursorCoor(const QPointF&);


	void on_backgroundSet_clicked();

	void on_exportPushbuttom_clicked();

private:
    Ui::myWindow *ui;
signals:
    void sendChart(ChartItem* item);
	void selectAll(bool isSelect);
    void toTop();

};

#endif // MYWINDOW_H
