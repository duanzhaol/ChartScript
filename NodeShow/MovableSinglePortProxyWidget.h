#ifndef MovableSinglePortProxyWidget_H
#define MovableSinglePortProxyWidget_H

#include "MovableProxyWidget.h"
#include "GraphicsDataNode.h"
#include "InputPortInterface.h"

class MovableSinglePortProxyWidget :public MovableProxyWidget,public InputPortInterface
{
    Q_OBJECT
    QWidget* widget()const;
public:
    MovableSinglePortProxyWidget();
    void setWidget(GraphicsDataNode*node);
    void setWidget(QWidget*node) = delete;


    GraphicsDataNode* getGraphicsDataNode();

    InputPortType*getInputPort();


	// InputPortInterface interface
public:
	virtual QPointF getInputPortCoordinate(const QGraphicsItem *item) override;
};



#endif // MovableSinglePortProxyWidget_H
