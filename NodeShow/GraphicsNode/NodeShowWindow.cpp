#include "ConnectController.h"
#include "NodeShowWindow.h"
#include "ui_NodeShowWindow.h"

#include "GraphicsAreaSeriesNode.h"
#include "GraphicsChartNode.h"
#include "GraphicsDataArrayNode.h"
#include "GraphicsLineSeriesNode.h"
#include "GraphicsPieSeriesNode.h"
#include "GraphicsScatterSeriesNode.h"
#include "GraphicsStartNode.h"
#include "ScalingGraphicsView.h"
#include <ConnectLineItem.h>
#include <Interpreter/Interpreter/InterpreterController.h>
#include <QDebug>
#pragma execution_character_set("utf-8")

auto getChart(){
	return new GraphicsChartNode(new MovableProxyWidget);
}

auto getStart(){
	return new GraphicsStartNode(new MovableProxyWidget);
}

//auto getArrayNode(){

//}



NodeShowWindow::NodeShowWindow(QWidget *parent) :
	  QMainWindow(parent),
	  ui(new Ui::NodeShowWindow)
{
	ui->setupUi(this);





	ui->graphicsView->setScene(scene);
	ui->graphicsView->setStyleSheet("padding:0px;border:0px");




	/*生成widget并获得代理*/
	//	auto p1 = getProxy1(),p2 = getProxy1(),p3=getProxy2();
	//	auto g1= getProxy3();
	//	auto g2= getProxy4();
	//	auto g3= getProxy5();

	//	auto g4= getProxy6();
	auto s = getStart();

	auto c= getChart();

	/*往场景里添加各代理widget（graphicsItem）*/
	//	scene->addItem(p1);
	//	scene->addItem(p2);
	//	scene->addItem(p3);

	//	scene->addItem(g1);
	//	scene->addItem(g2);
	//	scene->addItem(g3);
	//	scene->addItem(g4);

	scene->addItem(s->getProxy());

	scene->addItem(c->getProxy());

	/*生成节点间的连接线*/
	//	auto line =  new ConnectLineItem(p2,p1);
	//	auto line2 = new ConnectLineItem(p1,s);
	//	auto line3 = new ConnectLineItem(p3,p2);
	//	auto line4 = new ConnectLineItem(g1,p3);
	//	auto line5 = new ConnectLineItem(g2,g1);
	//	auto line6 = new ConnectLineItem(g3,g2);
	//	auto line7 = new ConnectLineItem(g4,g3);

   // auto line8 = new ConnectLineItem(c,s);


	InterpreterController::getGlobalInstance()->setStartNode(
		dynamic_cast<AbstractNode*>(s));

	/*把连接线添加到场景中*/
	//	scene->addItem(line);
	//	scene->addItem(line2);
	//	scene->addItem(line3);
	//	scene->addItem(line4);
	//	scene->addItem(line5);
	//	scene->addItem(line6);
	//	scene->addItem(line7);

   // scene->addItem(line8);

	init();

	ui->graphicsView->setStyleSheet(R"(QGraphicsView{ background-image:url(:/img/img/beijing.png);})");//设置scene背景

	ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);//流畅刷新

}

NodeShowWindow::~NodeShowWindow()
{
	delete ui;
}

void NodeShowWindow::createWindow()
{
	instance = new NodeShowWindow;
}

NodeShowWindow *NodeShowWindow::getInstance()
{
	return instance;
}

void NodeShowWindow::init()
{
	ui->listWidget->setViewMode(QListView::IconMode);
	ui->listWidget->setIconSize(QSize(100,100));
	ui->listWidget->setSpacing(10);
	ui->listWidget->setResizeMode(QListWidget::Adjust);
	ui->listWidget->setMovement(QListWidget::Static);

	QListWidgetItem *item1=new QListWidgetItem(ui->listWidget);
	item1->setText("开始结点");
	item1->setIcon(QIcon("/img/img/startNode.png"));
	item1->setSizeHint(QSize(140,130));

    QListWidgetItem *item2=new QListWidgetItem(ui->listWidget);
    item2->setText("数列结点(占位，添加函数改变了)");
	item2->setIcon(QIcon(":/img/img/node/arrayNode.png"));
    item2->setSizeHint(QSize(140,130));

//	QListWidgetItem *item3=new QListWidgetItem(ui->listWidget);
//	item3->setText("线图序列");
//	item3->setIcon(QIcon(":/img/node/img/node/lineSeriesNode.png"));
//	item3->setSizeHint(QSize(140,130));

//	QListWidgetItem *item4=new QListWidgetItem(ui->listWidget);
//	item4->setText("区域图序列");
//	item4->setIcon(QIcon(":/img/node/img/node/areaSeries.png"));
//	item4->setSizeHint(QSize(140,130));

//	QListWidgetItem *item5=new QListWidgetItem(ui->listWidget);
//	item5->setText("饼图序列");
//	item5->setIcon(QIcon(":/img/node/img/node/pieSeries.png"));
//	item5->setSizeHint(QSize(140,130));

//	QListWidgetItem *item6=new QListWidgetItem(ui->listWidget);
//	item6->setText("散点图序列");
//	item6->setIcon(QIcon(":/img/node/img/node/scatterSeries.png"));
//	item6->setSizeHint(QSize(140,130));

	QListWidgetItem *item7=new QListWidgetItem(ui->listWidget);
	item7->setText("统计图结点");
	item7->setIcon(QIcon(":/img/node/img/node/chartNode.png"));
	item7->setSizeHint(QSize(140,130));

}


void NodeShowWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{

	if(item->text()=="开始结点"){
		qDebug()<<item->text();
		//GraphicsRectItem *rect=new GraphicsRectItem(0,0,100,100);
		//addItem(rect);
		auto start= getStart();
		scene->addItem(start->getProxy());

	}
//    else if(item->text()=="数列结点"){
//        qDebug()<<item->text();
//        //GraphicsRectItem *rect=new GraphicsRectItem(0,0,100,100);
//        //addItem(rect);
//        auto array= getProxy2();
//        scene->addItem(array);

//    }
//    else if(item->text()=="线图序列"){
//		qDebug()<<item->text();
//	   // GraphicsEllipseItem *ellipse=new GraphicsEllipseItem(0,0,100,100);
//		//addItem(ellipse);
//		auto lineSeries=getProxy4();
//		scene->addItem(lineSeries);
//	}
//	else if(item->text()=="区域图序列"){
//		qDebug()<<item->text();
//		// GraphicsEllipseItem *ellipse=new GraphicsEllipseItem(0,0,100,100);
//		//addItem(ellipse);
//		auto areaSeries=getProxy3();
//		scene->addItem(areaSeries);
//	}
//	else if(item->text()=="饼图序列"){
//		qDebug()<<item->text();
//		// GraphicsEllipseItem *ellipse=new GraphicsEllipseItem(0,0,100,100);
//		//addItem(ellipse);
//		auto pieSeries=getProxy5();
//		scene->addItem(pieSeries);
//	}
//	else if(item->text()=="散点图序列"){
//		qDebug()<<item->text();
//		// GraphicsEllipseItem *ellipse=new GraphicsEllipseItem(0,0,100,100);
//		//addItem(ellipse);
//		auto scatterSeries=getProxy6();
//		scene->addItem(scatterSeries);
//	}
	else if(item->text()=="统计图结点"){
		qDebug()<<item->text();
		// GraphicsEllipseItem *ellipse=new GraphicsEllipseItem(0,0,100,100);
		//addItem(ellipse);
		auto chart=getChart();
		scene->addItem(chart->getProxy());
	}

}

NodeShowWindow* NodeShowWindow::instance = nullptr;
