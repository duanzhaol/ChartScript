#ifndef OUTPUTPORTINTERFACE_H
#define OUTPUTPORTINTERFACE_H

#include "AbstractGraphicsNode.h"
#include "OutputPort.h"

#include <QPushButton>
#include <QGraphicsItem>
#include <QGraphicsProxyWidget>

/**
 * @interface Outputable
 * 所有拥有输出端口的图节点的接口，实现该接口的子类能够被连接输出端口
 */


class Outputable{
public:

	Outputable();

    virtual QPointF getOutputPortCoordinate(QGraphicsItem* item)=0;
	virtual OutputPort* getOutputPort() = 0;

};
#endif // OUTPUTPORTINTERFACE_H
