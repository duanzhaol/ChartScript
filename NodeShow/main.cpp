#include "GraphicsDataNode.h"
#include "MovableInputPortProxyWidget.h"
#include "ConnectLineItem.h"
#include "MovableDualPortProxyWidget.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>

auto getProxy(){
    auto node = new GraphicsDataNode;
    auto proxy = new MovableDualPortProxyWidget;
    proxy->setDualPortWidget(node);
    return proxy;
}

int main(int argc,char*argv[]){
    QApplication app(argc,argv);
    auto scene = new QGraphicsScene;
    auto view = new QGraphicsView;

    auto p1 = getProxy(),p2 = getProxy();
    auto line = new ConnectLineItem(p1,p2);

    scene->addItem(p1);
    scene->addItem(p2);
    scene->addItem(line);

    view->setScene(scene);
    view->showMaximized();
    view->setStyleSheet(R"(QGraphicsView{ background-image:url(:/img/img/beijing.jpg);})");
    view->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);


    return app.exec();
}
