#include "ListWidget.h"
#include<QDebug>
#include <QChartView>
#include <ctime>
ListWidget::ListWidget(QWidget *parent)
{
    setMouseTracking(true);

}

ChartItem *ListWidget::getChart(int index)
{
    qDebug()<<"当前长度:"<<chartItemList.length()<<"  "<<count();

    if(index<chartItemList.length()){
        return chartItemList[index];
    }else{
        return nullptr;
    }
}

void ListWidget::addChart(ChartItem *item)
{
    chartItemList.append(item);
}

bool ListWidget::addItemAll(ChartItem *chart, ListWidgetItem *item)
{
    if(chart!=nullptr&&item!=nullptr){
        addChart(chart);
        addItem(item);
        qDebug()<<"当前长度:"<<chartItemList.length()<<"  "<<count();
        return true;
    }else{
        return false;
    }

}

int ListWidget::getLength()
{
    return chartItemList.length();
}

bool ListWidget::removeItemAll(int index)
{
    if(index<chartItemList.length()){
        chartItemList.removeAt(index);
        takeItem(index);
    }else{
        return false;
    }
}

void ListWidget::reciveChart(GraphicsShowInterface *chart)
{
    QString chartName=chart->getName();
    ChartItem* myChart=dynamic_cast<ChartItem*>(chart->getChart());

    qsrand(time(NULL));
    int n = qrand() % 99999;//存储的随机数

    QtCharts::QChartView *chartView = new QtCharts::QChartView(myChart);
    chartView->setRenderHint(QPainter::Antialiasing);  //消除边缘
    chartView->setChart(myChart);
    QPixmap p = QPixmap::grabWidget(chartView);
    QImage image=p.toImage();
    QString url="C:/Users/duan/Documents/QTProgram/ChartScript/graphShow/image/chartPicture/";//前缀
    url=url+QString(n)+".png";
    image.save(url);

    ListWidgetItem *item=new ListWidgetItem(this);
    item->setText(chartName);
    item->setIcon(QIcon(url));
    item->setSizeHint(QSize(100,120));
    this->addItemAll(myChart,item);
}


