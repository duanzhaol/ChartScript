﻿#ifndef NODELISTWIDGET_H
#define NODELISTWIDGET_H

#include <QListWidget>
#include <../ChartScript/NodeShow/GraphicsNode/GraphicsNode/GraphicsInnerNode/GraphicsDataArrayNode.h>
#include <TableView/GraphicsShowInterface/TableArrayInterface.h>

class NodeListWidget:public QListWidget
{
    Q_OBJECT
public:
    NodeListWidget();
    QHash<int,GraphicsDataArrayNode*> arrayNodeList;

    void addArrayNode(GraphicsDataArrayNode * node);
    GraphicsDataArrayNode *getArrayNode(int index);
    bool addItemAll(GraphicsDataArrayNode * node, QListWidgetItem *item);
    static NodeListWidget* getInstance();

    int Nodeindex=0;

public slots:
    void reciveArray(TableArrayInterface *arrayInterface);

private:
    static NodeListWidget* instance;
};




#endif // CONNECTCONTROLLER_H


//class ListWidget: public QListWidget
//{
//    Q_OBJECT
//public:
//    explicit ListWidget(QWidget *parent = nullptr);
//    ChartItem* getChart(int index);
//    void addChart(ChartItem* item);
//    bool addItemAll(ChartItem* chart,ListWidgetItem* item);
//    int getLength();
//    bool removeItemAll(int index);
//private:
//    QVector<ChartItem*> chartItemList;
//public slots:
//    void reciveChart(GraphicsShowInterface*chartInterface);


//};
