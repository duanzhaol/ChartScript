#ifndef GRAPHICSSHAPEDEFINE_H
#define GRAPHICSSHAPEDEFINE_H

#include "AbstractGraphicsItem.h"

/**
* @def GRAPHICS_SHAPDE_DEFINE_H(GraphicsType)
* 为GraphicsShapeItem的子类生成公共的声明代码
*/
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



/**
* @def GRAPHICS_SHAPDE_DEFINE_CPP(GraphicsType)
* 为GraphicsShapeItem的子类生成公共的定义代码
*/

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
