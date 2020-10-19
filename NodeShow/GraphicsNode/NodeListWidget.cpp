﻿#include "NodeListWidget.h"
#include "NodeListWidgetItem.h"
#include <QDebug>





NodeListWidget::NodeListWidget(QWidget *parent):
QListWidget(parent)
{
    NodeListWidgetItem *item=new NodeListWidgetItem(this);
    item->setItemIndex(Nodeindex);
    item->setText("arrayInterface->getArrayName()");
    //    item->setIcon(QIcon(p));
    item->setSizeHint(QSize(100,120));
}

void NodeListWidget::addArrayNode(GraphicsTopArrayNode * node)
{
    arrayNodeList.insert(Nodeindex,node);

}

GraphicsTopArrayNode *NodeListWidget::getArrayNode(int index)
{

    qDebug()<<"当前长度:"<<arrayNodeList<<"  "<<count();

    QHash<int, GraphicsTopArrayNode*>::iterator i = arrayNodeList.find(index);
    if (i != arrayNodeList.end()) {
        qDebug()<< i.value() << Qt::endl;
        return i.value();
    }
    else{
        return nullptr;
    }
}


bool NodeListWidget::addItemAll(GraphicsTopArrayNode * node, QListWidgetItem *item)
{
    if(node!=nullptr&&item!=nullptr){
        addArrayNode(node);
        addItem(item);
        qDebug()<<"当前长度:"<<arrayNodeList<<"  "<<count();

        Nodeindex++;

        return true;
    }else{
        return false;
    }

}

//NodeListWidget *NodeListWidget::getInstance()
//{
//    return instance;
//}

//void NodeListWidget::createWidget()
//{
//    instance = new NodeListWidget;
//}

void NodeListWidget::reciveArray(TableArrayInterface *arrayInterface)
{

//    ChartItem* chart=dynamic_cast<ChartItem*>(chartInterface->getChart());
//    chart->createDefaultAxes();


//    qsrand(time(NULL));
//    int n = qrand() % 99999;//存储的随机数


//    QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
//    chartView->setRenderHint(QPainter::Antialiasing);  //消除边缘
//    chartView->setChart(chart);

//    //QPixmap p = QPixmap::grabWidget(chartView);
//    QPixmap p = chartView->grab();

//    //    QImage image=p.toImage();
//    //	QString url=":/img/image/";//前缀
//    //    url=url+QString(n)+".png";
//    //    image.save(url);


    GraphicsDataArrayNode * node=new GraphicsDataArrayNode();
    node->setTableArrayInterface(arrayInterface);
    GraphicsTopArrayNode * topNode=new GraphicsTopArrayNode(node,new MovableProxyWidget);


    NodeListWidgetItem *item=new NodeListWidgetItem(this);
    item->setItemIndex(Nodeindex);
    item->setText(arrayInterface->getArrayName());
//    item->setIcon(QIcon(p));
    item->setSizeHint(QSize(100,120));


    this->addItemAll(topNode,item);
}



















//#include "ListWidget.h"
//#include<QDebug>
//#include <QChartView>
//#include <ctime>
//#include<QPieSeries>
//#include "../../Interpreter/Transmitter/GraphShowTransmitter.h"
//ListWidget::ListWidget(QWidget *parent)
//{
//    setMouseTracking(true);
//    connect(&GraphShowTransmitter::getInstance(),&GraphShowTransmitter::sendChart,
//            this,&ListWidget::reciveChart);
//}

//ChartItem *ListWidget::getChart(int index)
//{
//    qDebug()<<"当前长度:"<<chartItemList.length()<<"  "<<count();

//    if(index<chartItemList.length()){
//        return chartItemList[index];
//    }else{
//        return nullptr;
//    }
//}

//void ListWidget::addChart(ChartItem *item)
//{
//    chartItemList.append(item);
//}

//bool ListWidget::addItemAll(ChartItem *chart, ListWidgetItem *item)
//{
//    if(chart!=nullptr&&item!=nullptr){
//        addChart(chart);
//        addItem(item);
//        qDebug()<<"当前长度:"<<chartItemList.length()<<"  "<<count();
//        return true;
//    }else{
//        return false;
//    }

//}

//int ListWidget::getLength()
//{
//    return chartItemList.length();
//}

//bool ListWidget::removeItemAll(int index)
//{
//    if(index<chartItemList.length()){
//        chartItemList.removeAt(index);
//        takeItem(index);
//    }else{
//        return false;
//    }
//}

//void ListWidget::reciveChart(GraphicsShowInterface *chartInterface)
//{
//    QString chartName=chartInterface->getName();
//    ChartItem* chart=dynamic_cast<ChartItem*>(chartInterface->getChart());
//    chart->createDefaultAxes();


//    qsrand(time(NULL));
//    int n = qrand() % 99999;//存储的随机数

//    QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
//    chartView->setRenderHint(QPainter::Antialiasing);  //消除边缘
//    chartView->setChart(chart);
//    //QPixmap p = QPixmap::grabWidget(chartView);
//    QPixmap p = chartView->grab();

//    //    QImage image=p.toImage();
//    //	QString url=":/img/image/";//前缀
//    //    url=url+QString(n)+".png";
//    //    image.save(url);

//    ListWidgetItem *item=new ListWidgetItem(this);
//    item->setText("chartName");
//    item->setIcon(QIcon(p));
//    item->setSizeHint(QSize(100,120));
//    this->addItemAll(chart,item);
//}

//NodeListWidget* NodeListWidget::instance = nullptr;
