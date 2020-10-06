#ifndef LISTWIDGET_H
#define LISTWIDGET_H
#include<QListWidget>
#include"ListWidgetItem.h"
#include<QMouseEvent>
#include"graphShow/ChartItem.h"
#include"../../Interpreter/GraphicsShowInterface/GraphicsShowInterface.h"
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
    void reciveChart(GraphicsShowInterface*chart);


};

#endif // LISTWIDGET_H
