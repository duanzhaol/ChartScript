#ifndef INPUTPORTINTERFACE_H
#define INPUTPORTINTERFACE_H

#include <QPushButton>
#include <QGraphicsItem>
#include <QGraphicsProxyWidget>
#include "AbstractGraphicsNode.h"
#include "InputPort.h"

/**
 * @interface Inputable
 * @brief 所有拥有输入端口的图节点的接口，实现该接口的子类能够被连接输入端口
 */

class Inputable{
public:

	Inputable();

    virtual QPointF getInputPortCoordinate(QGraphicsItem* item)=0;
	virtual InputPort* getInputPort() = 0;



};

#endif // INPUTPORTINTERFACE_H
