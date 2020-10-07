#include<QApplication>
#include <QDebug>
#include <QDateTime>
#include "graphShow/GraphShowInitializer.h"
#include "NodeShow/NodeShowInitializer.h"




int main(int argc,char*argv[]){
	QApplication app(argc,argv);

	GraphShowInitializer::getInstance()->init();
	NodeShowInitializer::getInstance()->init();

	app.exec();
}



//	/*程序进入前的开场动画效果*/
//	QPixmap lodingPix(":/img/img/ChartScript-banner-small.png");
//	QSplashScreen splash(lodingPix);
//	splash.show();
////    splash.showMessage("程序正在加载......", Qt::AlignTop|Qt::AlignRight, Qt::red);
//	QDateTime time = QDateTime::currentDateTime();
//	QDateTime currentTime = QDateTime::currentDateTime();   //记录当前时间
//	while (time.secsTo(currentTime) <= 3)                   //5为需要延时的秒数
//	{
//		currentTime = QDateTime::currentDateTime();
//		app.processEvents();
//	};


