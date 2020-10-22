#include "NodeListWidget.h"
#include "NodeListWidgetItem.h"
#include <QDebug>
#include <TableView/GraphicsShowInterface/TableArrayInterface.h>
#include <TableView/GraphicsShowInterface/TableArrayInterface.h>
#pragma execution_character_set("utf-8")






NodeListWidget::NodeListWidget(QWidget *parent):
QListWidget(parent)
{

}

void NodeListWidget::addArrayNode(GraphicsTopArrayNode * node)
{
    arrayNodeList.insert(Nodeindex,node);

}

GraphicsTopArrayNode *NodeListWidget::getArrayNode(int index)
{

    QHash<int, GraphicsTopArrayNode*>::iterator i = arrayNodeList.find(index);
    if (i != arrayNodeList.end()) {
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

        qDebug()<<"NodeListWidget::addItemAll "<<"结点Hash："<<arrayNodeList<<"  "<<"arrayNodeListd的当前长度:"<<count();

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

	GraphicsTopArrayNode * topNode=new GraphicsTopArrayNode(arrayInterface,new MovableProxyWidget);

	NodeListWidgetItem *item=new NodeListWidgetItem(this);

	connect(arrayInterface,&TableArrayInterface::arrayNameChanged,this,[=](){
		item->setText(arrayInterface->getArrayName());
	});

	connect(arrayInterface,&TableArrayInterface::arrayDelete,this,[=]{
		this->removeItemWidget(item);
	});

	item->setItemIndex(Nodeindex);
	item->setText(arrayInterface->getArrayName());
	item->setIcon(QIcon(":/img/img/node/arrayNode.png"));
	item->setSizeHint(QSize(100,20));
	addItemAll(topNode,item);
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
