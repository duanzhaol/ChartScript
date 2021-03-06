#ifndef NODELISTWIDGET_H
#define NODELISTWIDGET_H

#include <QListWidget>
#include <../ChartScript/NodeShow/GraphicsNode/GraphicsNode/GraphicsInnerNode/GraphicsDataArrayNode.h>
#include <TableView/GraphicsShowInterface/TableArrayInterface.h>
#include <GraphicsNode/GraphicsTopNode/GraphicsTopArrayNode.h>

/**
 * @brief
 * 用于显示图节点的列表，以选取添加图节点
 * @see NodeListWidgetItem
 */

class NodeListWidget:public QListWidget
{
    Q_OBJECT
public:
    NodeListWidget(QWidget* parent = nullptr);

    QHash<int,GraphicsTopArrayNode*> arrayNodeList;

    void addArrayNode(GraphicsTopArrayNode * node);
    GraphicsTopArrayNode *getArrayNode(int index);
    bool addItemAll(GraphicsTopArrayNode * node, QListWidgetItem *item);
//    static NodeListWidget* getInstance();
    static void createWidget();

	int Nodeindex=10001;//表格结点和item的唯一编号


public slots:
    void reciveArray(TableArrayInterface *arrayInterface);

//private:
//    static NodeListWidget* instance;
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
