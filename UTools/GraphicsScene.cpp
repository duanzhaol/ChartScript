﻿#include "GraphicsScene.h"
#include<QDebug>
#include <QGraphicsSceneMouseEvent>
GraphicsScene::GraphicsScene(QObject *parent)
{
	clearFocus();
}

void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

	QGraphicsScene::mousePressEvent(event);
	if(!event->isAccepted()){
		if (event->button() == Qt::LeftButton){
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
		ChartItem *myItem=dynamic_cast<ChartItem*>(item);
//        selectItems.append(myItem);
//        qDebug()<<selectItems;
		removeItem(myItem);
	}
}

void GraphicsScene::selectAll()
{
	foreach(QGraphicsItem *item,items()){
		ChartItem *myItem=dynamic_cast<ChartItem*>(item);
		myItem->setSelected(true);
	}
}



