#include<QApplication>
#include <QDebug>
#include <QDateTime>
#include <QSplashScreen>
#include <QTextCodec>
#include <QStyleFactory>
#include "MainWindow/MainWindowInitializer.h"
#include <QtCharts/QChartView>
#include "graphShow/ChartItem.h"
#include <QLineSeries>
#include "GraphicsDataArrayNode.h"
#include <TableView/TableView.h>

void LoadImage(){
    /*程序进入前的开场动画效果*/
	QPixmap lodingPix(":/img/img/ChartScript-banner-small.png");
    QSplashScreen splash(lodingPix);
    splash.show();
    //    splash.showMessage("程序正在加载......", Qt::AlignTop|Qt::AlignRight, Qt::red);
    QDateTime time = QDateTime::currentDateTime();
    QDateTime currentTime = QDateTime::currentDateTime();   //记录当前时间
    while (time.secsTo(currentTime) <= 3)                   //3为需要延时的秒数
    {
        currentTime = QDateTime::currentDateTime();
    };

}

using namespace QtCharts;
int main(int argc,char*argv[]){
	QApplication app(argc,argv);

	LoadImage();

    MainWindowInitializer::getInstance()->init();

	app.exec();
}





