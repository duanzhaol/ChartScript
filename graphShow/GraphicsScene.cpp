#include "GraphicsScene.h"
#include<QDebug>
#include <QGraphicsSceneMouseEvent>
#include "item/ShapeItem/GraphicsEllipseItem.h"
#include "item/GraphicsTextItem.h"
#include "item/GraphicsImageItem.h"
GraphicsScene::GraphicsScene(QObject *parent):QGraphicsScene(parent)
{
	clearFocus();
}

void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

	QGraphicsScene::mousePressEvent(event);

	if(!event->isAccepted()){
		if (event->button() == Qt::LeftButton){
			if(event->modifiers()==Qt::ControlModifier){//按ctrl多选
				foreach(QGraphicsItem *item,items(event->scenePos())){
					ChartItem *myItem=dynamic_cast<ChartItem*>(item);
					item->setSelected(true);
				}
			}else{
				//selectItems.clear();
			}
		}else if (event->button() == Qt::RightButton){
		}
	}else if(selectedItems().count()>1&&event->modifiers()!=Qt::ControlModifier){
		foreach(QGraphicsItem *item,selectedItems()){
			item->setSelected(false);
		}
		//selected->setSelected(true);
	}
}

void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	QGraphicsScene::mouseMoveEvent(event);
	emit mouseMove(event->scenePos());
}

void GraphicsScene::keyPressEvent(QKeyEvent *event)
{
	switch (event->key()) {
	case Qt::Key_Delete:{
		return deleteSelect();
	}
	}
	constexpr static qreal moveFactor = 5;
	for(QGraphicsItem*item:selectedItems()){
		switch (event->key()) {
		case Qt::Key_Up:{
			item->setY(item->y()-moveFactor);
			break;
		}
		case Qt::Key_Down:{
			item->setY(item->y()+moveFactor);
			break;
		}
		case Qt::Key_Left:{
			item->setX(item->x()-moveFactor);
			break;
		}
		case Qt::Key_Right:{
			item->setX(item->x()+moveFactor);
			break;
		}

		}
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

void GraphicsScene::selectAll(bool isSelect)
{
	foreach(QGraphicsItem *item,items()){
		item->setSelected(isSelect);
	}
}

void GraphicsScene::ThemeChanged(int type)
{
	foreach(QGraphicsItem *item,selectedItems()){
		qDebug()<<type;
		ChartItem *myItem=dynamic_cast<ChartItem*>(item);
		if(myItem==nullptr)continue;
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
#include <QtCharts/QLineSeries>

#include <graphShow/item/ShapeItem/GraphicsTriangleItem.h>
void GraphicsScene::recieveGraphics(QListWidgetItem *item)
{

	if(item->text()==QStringLiteral("矩形")){
		qDebug()<<item->text();
		GraphicsRectItem *rect=new GraphicsRectItem(0,0,100,100);
		addItem(rect);
		ChartItem*item = new ChartItem;
		item->setGeometry(0,0,100,100);
		auto s = new QtCharts::QLineSeries;
		s->append(1,1);
		s->append(2,2);
		item->createDefaultAxes();
		item->addSeries(s);
		addItem(item);
	}else if(item->text()==QStringLiteral("椭圆")){
		qDebug()<<item->text();

		GraphicsEllipseItem *ellipse=new GraphicsEllipseItem(0,0,100,100);
		addItem(ellipse);
	}
	else if(item->text()==QStringLiteral("文本框")){
		qDebug()<<item->text();
		GraphicsTextItem*text = new GraphicsTextItem(0,0);
		addItem(text);
	}
	else if(item->text()==QStringLiteral("图片")){
		qDebug()<<item->text();
		GraphicsImageItem*text = new GraphicsImageItem(0,0,100,100);
		addItem(text);
	}
	else if(item->text()==QStringLiteral("三角形")){
		qDebug()<<item->text();
		GraphicsTriangleItem*text = new GraphicsTriangleItem(0,0,100,100);
		addItem(text);
	}
}

void GraphicsScene::toTop()
{
	//无法通过collisionItems判断，因为小圆圈的存在，无法准确的获得所有的碰撞物体
	if(selectedItems().count()!=1){
		qDebug()<<"操作无效，请选择一个物体！";
	}else{
		QGraphicsItem *myItem=selectedItems().first();
		removeItem(myItem);
		addItem(myItem);
	}
}

