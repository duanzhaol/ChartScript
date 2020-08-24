#include "ChartItem.h"
#include "GraphicsScene.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsProxyWidget>
#include <QChart>
#include <QtCharts/QBarSeries>
#include <QChartView>
#include <QBarSet>
#include <QLineSeries>
#include <QPieSeries>
#include <QPixmap>
#include<QDebug>
#include <QChartView>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //QChart是一个QGraphicsWidget子类，能管理多个统计图元素
    ChartItem *chart =  new ChartItem();


    chart->createDefaultAxes();
    //圆饼图元素
    auto pie = new ::QtCharts::QPieSeries;
    //添加测试数据
    pie->append(new ::QtCharts::QPieSlice("blue",20));
    pie->append(new ::QtCharts::QPieSlice("red",20));
    qDebug() <<"左键点击选中了一个chart！";
    chart->addSeries(pie);
    pie->setVisible(true);
    chart->setVisible(true);
    chart->setPos(5,5);
    chart->setGeometry(5,5,800,800);
    chart->setFlag(QGraphicsItem::ItemIsMovable,true);
    chart->setFlag(QGraphicsItem::ItemIsSelectable,true);
    chart->acceptDrops();

    ChartItem *chart2 =  new ChartItem();
    chart2->createDefaultAxes();
    //圆饼图元素
    auto pie2 = new ::QtCharts::QPieSeries;
    //添加测试数据
    pie2->append(new ::QtCharts::QPieSlice("pink",20));
    pie2->append(new ::QtCharts::QPieSlice("black",20));
    qDebug() <<"左键点击选中了一个chart！";
    chart2->addSeries(pie2);
    pie2->setVisible(true);
    chart2->setVisible(true);
    chart2->setPos(50,50);
    chart2->setGeometry(50,50,800,800);
    chart2->setFlag(QGraphicsItem::ItemIsMovable,true);
    chart2->setFlag(QGraphicsItem::ItemIsSelectable,true);
    chart2->acceptDrops();
    GraphicsScene *sc = new GraphicsScene();
    sc->addItem(chart);
    sc->addItem(chart2);
    //MyChartItem chart2=chart;
    QtCharts::QChartView* view = new QtCharts::QChartView();
    view->setScene(sc);
    view->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);//shua'xin'f刷新方式，重要
    view->show();
    //view->setRubberBand(QtCharts::QChartView::RectangleRubberBand);//设置缩放模式
    view->setDragMode(QGraphicsView::RubberBandDrag);//重要
    return a.exec();
}
