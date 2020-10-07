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
#include"qchartviewfactory.h"
#include"mywindow.h"
#include"item/GraphicsRectItem.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    myWindow *myWindows=new myWindow();
	GraphicsScene *sc = new GraphicsScene();
	myWindows->setScene(sc);
    myWindows->show();

    return a.exec();
}
