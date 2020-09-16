#ifndef MovableSinglePortProxyWidget_H
#define MovableSinglePortProxyWidget_H

#include "MovableProxyWidget.h"
#include "GraphicsDataNode.h"


class MovableSinglePortProxyWidget :public MovableProxyWidget
{
    Q_OBJECT
    QWidget* widget()const;
public:
    MovableSinglePortProxyWidget();
    void setWidget(GraphicsDataNode*node);
    void setWidget(QWidget*node) = delete;


    GraphicsDataNode* getGraphicsDataNode();

    InputPortType*getInputPort();

};

#endif // MovableSinglePortProxyWidget_H
