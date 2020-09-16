#ifndef INPUTPORTINTERFACE_H
#define INPUTPORTINTERFACE_H

#include <QPushButton>
#include <QGraphicsItem>

using InputPortType = QPushButton;

class InputPortInterface{
public:
    virtual InputPortType* getInputPort() = 0;
    virtual QPointF getInputPortCoordinate(const QGraphicsItem* item) = 0;
};

#endif // INPUTPORTINTERFACE_H
