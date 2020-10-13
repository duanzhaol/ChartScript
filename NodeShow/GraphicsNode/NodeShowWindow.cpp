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
#include <MovableDualPortProxyWidget.h>
#include <Interpreter/Interpreter/InterpreterController.h>
#include <QDebug>


auto getProxy1(){
    auto node = new GraphicsDataNode;
    auto proxy = new MovableDualPortProxyWidget;
    proxy->setDualPortWidget(node);
    return proxy;
}

auto getProxy2(){
    auto node = new GraphicsDataArrayNode;
    auto proxy = new MovableDualPortProxyWidget;
    proxy->setDualPortWidget(node);
    return proxy;
}

auto getProxy3(){
    auto node = new GraphicsAreaSeriesNode;
    auto proxy = new MovableDualPortProxyWidget;
    proxy->setDualPortWidget(node);
    return proxy;
}

auto getProxy4(){
    auto node = new GraphicsLineSeriesNode;
    auto proxy = new MovableDualPortProxyWidget;
    proxy->setDualPortWidget(node);
    return proxy;
}

auto getProxy5(){
    auto node = new GraphicsPieSeriesNode;
    auto proxy = new MovableDualPortProxyWidget;
    proxy->setDualPortWidget(node);
    return proxy;
}

auto getProxy6(){
    auto node = new GraphicsScatterSeriesNode;
    auto proxy = new MovableDualPortProxyWidget;
    proxy->setDualPortWidget(node);
    return proxy;
}

auto getChart(){
    auto node = new GraphicsChartNode;
    auto proxy = new MovableDualPortProxyWidget;
    proxy->setDualPortWidget(node);
    return proxy;
}

auto getStart(){
    auto proxy = new MovableOutputPortProxyWidget;
    proxy->setOutputPortWidget(new GraphicsStartNode);
    return proxy;
}



NodeShowWindow *NodeShowWindow::getInstance()
{
        return instance;
}

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

    scene->addItem(s);

    scene->addItem(c);

    /*生成节点间的连接线*/
    //	auto line =  new ConnectLineItem(p2,p1);
    //	auto line2 = new ConnectLineItem(p1,s);
    //	auto line3 = new ConnectLineItem(p3,p2);
    //	auto line4 = new ConnectLineItem(g1,p3);
    //	auto line5 = new ConnectLineItem(g2,g1);
    //	auto line6 = new ConnectLineItem(g3,g2);
    //	auto line7 = new ConnectLineItem(g4,g3);

    //auto line8 = new ConnectLineItem(c,s);


    InterpreterController::getGlobalInstance()->setStartNode(
        dynamic_cast<AbstractNode*>(s->getOutputPortWidget()));

    /*把连接线添加到场景中*/
    //	scene->addItem(line);
    //	scene->addItem(line2);
    //	scene->addItem(line3);
    //	scene->addItem(line4);
    //	scene->addItem(line5);
    //	scene->addItem(line6);
    //	scene->addItem(line7);

    //  scene->addItem(line8);



    ui->graphicsView->setStyleSheet(R"(QGraphicsView{ background-image:url(:/img/img/beijing.jpg);})");//设置scene背景
    ui->graphicsView->showMaximized();//全屏窗口打开
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);//流畅刷新

}

NodeShowWindow::~NodeShowWindow()
{
    delete ui;
}

void NodeShowWindow::createWindow()
{
    NodeShowWindow::instance=new NodeShowWindow();
}

NodeShowWindow* NodeShowWindow::instance=nullptr;

