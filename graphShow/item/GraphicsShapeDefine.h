#ifndef GRAPHICSSHAPEDEFINE_H
#define GRAPHICSSHAPEDEFINE_H

#include "AbstractGraphicsItem.h"

#define GRAPHICS_SHAPDE_DEFINE_H(GraphicsType) \
class GraphicsType :public QObject,public AbstractGraphicsItem<Q##GraphicsType> \
{ \
	Q_OBJECT \
public: \
	GraphicsType(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr); \
private slots : \
	void setAttr(); \
protected: \
	virtual void SLOT_openAttributeWidget() override; \
}; \




#define GRAPHICS_SHAPDE_DEFINE_CPP(GraphicsType) \
GraphicsType :: GraphicsType \
(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent): \
	AbstractGraphicsItem(x,y,width,height,parent){} \
\
void GraphicsType ::setAttr() \
{ \
	AbstractGraphicsItem::setAttr(); \
} \
\
void GraphicsType ::SLOT_openAttributeWidget() \
{ \
	AbstractGraphicsItem::SLOT_openAttributeWidget(); \
	this->connect(attr,&ChartAttribute::confirm, \
				  this,& GraphicsType ::setAttr); \
}


#endif // GRAPHICSSHAPEDEFINE_H
