#ifndef OUTPUTPORTINTERFACE_H
#define OUTPUTPORTINTERFACE_H

#include <QPushButton>
#include <QGraphicsItem>

using OutputPortType = QPushButton;

class OutputPortInterface{
public:
    virtual OutputPortType* getOutputPort() = 0;
    virtual QPointF getOutputPortCoordinate(const QGraphicsItem* item) = 0;
};
#endif // OUTPUTPORTINTERFACE_H
