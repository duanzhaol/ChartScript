#include "ListWidget.h"
#include<QDebug>
#include <QChartView>
#include <ctime>
#include<QPieSeries>
#include "../../Interpreter/Transmitter/GraphShowTransmitter.h"
ListWidget::ListWidget(QWidget *parent)
{
    setMouseTracking(true);
	connect(&GraphShowTransmitter::getInstance(),&GraphShowTransmitter::sendChart,
			this,&ListWidget::reciveChart);
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

void ListWidget::reciveChart(GraphicsShowInterface *chartInterface)
{
	QString chartName=chartInterface->getName();
	ChartItem* chart=chartInterface->getChart();
	chart->createDefaultAxes();

	QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);  //消除边缘
	chartView->setChart(chart);
	chartView->show();
	//QPixmap p = QPixmap::grabWidget(chartView);
	QPixmap p = chartView->grab();

//    QImage image=p.toImage();
//	QString url=":/img/image/";//前缀
//    url=url+QString(n)+".png";
//    image.save(url);

    ListWidgetItem *item=new ListWidgetItem(this);
	item->setText(chartInterface->getName());
	item->setIcon(QIcon(p));
    item->setSizeHint(QSize(100,120));
	this->addItemAll(chart,item);
}


