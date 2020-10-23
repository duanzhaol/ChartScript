#ifndef LISTWIDGET_H
#define LISTWIDGET_H
#include<QListWidget>
#include"ListWidgetItem.h"
#include<QMouseEvent>
#include"graphShow/ChartItem.h"
#include"../../Interpreter/GraphicsShowInterface/GraphicsShowInterface.h"
/**
 * @brief The ListWidget class
 * 左侧的列表，可以保存qchart，显示缩略图，双击显示
 */
class ListWidget: public QListWidget
{
    Q_OBJECT
public:
    explicit ListWidget(QWidget *parent = nullptr);
    ChartItem* getChart(int index);
    void addChart(ChartItem* item);
    bool addItemAll(ChartItem* chart,ListWidgetItem* item);
    int getLength();
    bool removeItemAll(int index);
private:
    QVector<ChartItem*> chartItemList;
public slots:
	void reciveChart(GraphicsShowInterface*chartInterface);


};

#endif // LISTWIDGET_H
