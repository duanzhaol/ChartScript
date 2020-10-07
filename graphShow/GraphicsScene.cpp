#include "GraphicsScene.h"
#include<QDebug>
#include <QGraphicsSceneMouseEvent>
#include "item/GraphicsEllipseItem.h"
GraphicsScene::GraphicsScene(QObject *parent):QGraphicsScene(parent)
{
    clearFocus();
}

void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    QGraphicsScene::mousePressEvent(event);

    if(!event->isAccepted()){
        if (event->button() == Qt::LeftButton){
            qDebug()<<"aaaaaaaaaaaa";
             if(event->modifiers()==Qt::ControlModifier){//按ctrl多选
                 qDebug()<<"ctrl选中";
                 foreach(QGraphicsItem *item,items(event->scenePos())){
                     ChartItem *myItem=dynamic_cast<ChartItem*>(item);
                     selectItems.append(myItem);
                     qDebug()<<selectItems;
                 }
             }else{
                 qDebug()<<"左键空白区域";
                 selectItems.clear();
             }
        }else if (event->button() == Qt::RightButton){
             qDebug() <<"右键点击空白位置";
        }
    }else if(selectedItems().count()>1){
        qDebug()<<"sbsbsbsbsbsb";
        //hartItem *selected=dynamic_cast<ChartItem*>(selectedItems().last());
        //selectedItems().clear();
       // selected->setSelected(true);
        foreach(QGraphicsItem *item,selectedItems()){
           item->setSelected(false);
        }
        //selected->setSelected(true);
    }
}

void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    //qDebug() << "场景被移动";

    QGraphicsScene::mouseMoveEvent(event);
}

void GraphicsScene::keyPressEvent(QKeyEvent *event)
{
    //qDebug()<<
    if(event->key()==Qt::Key_Delete){
        qDebug()<<"delete";
        deleteSelect();
    }
}

void GraphicsScene::deleteSelect()
{
    foreach(QGraphicsItem *item,selectedItems()){
       // ChartItem *myItem=dynamic_cast<ChartItem*>(item);
//        selectItems.append(myItem);
//        qDebug()<<selectItems;
        removeItem(item);
    }
}

void GraphicsScene::selectAll()
{
    foreach(QGraphicsItem *item,items()){
        //ChartItem *myItem=dynamic_cast<ChartItem*>(item);
        item->setSelected(true);
    }
}

void GraphicsScene::ThemeChanged(int type)
{
    foreach(QGraphicsItem *item,selectedItems()){
        qDebug()<<type;
        ChartItem *myItem=dynamic_cast<ChartItem*>(item);
        switch (type) {
        case 0:
            myItem->setTheme(QtCharts::QChart::ChartThemeLight);
            break;
        case 1:
            myItem->setTheme(QtCharts::QChart::ChartThemeBlueCerulean);
            break;
        case 2:
            myItem->setTheme(QtCharts::QChart::ChartThemeDark);
            break;
        case 3:
            myItem->setTheme(QtCharts::QChart::ChartThemeBrownSand);
            break;
        case 4:
            myItem->setTheme(QtCharts::QChart::ChartThemeBlueNcs);
            break;
        case 5:
            myItem->setTheme(QtCharts::QChart::ChartThemeHighContrast);
            break;
        case 6:
            myItem->setTheme(QtCharts::QChart::ChartThemeBlueIcy);
            break;
        case 7:
            myItem->setTheme(QtCharts::QChart::ChartThemeQt);
            break;

        }
    }
}

void GraphicsScene::recieveChart(ChartItem *item)
{
    qDebug()<<"123123";
    addItem(item);
}

void GraphicsScene::recieveGraphics(QListWidgetItem *item)
{

    if(item->text()=="rect"){
        qDebug()<<item->text();
        GraphicsRectItem *rect=new GraphicsRectItem(0,0,100,100);
        addItem(rect);
    }else if(item->text()=="ellipse"){
        qDebug()<<item->text();

        GraphicsEllipseItem *ellipse=new GraphicsEllipseItem(0,0,100,100);
        addItem(ellipse);
    }
}
