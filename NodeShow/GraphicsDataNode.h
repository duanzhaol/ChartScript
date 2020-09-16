#ifndef GraphicsDataNode_H
#define GraphicsDataNode_H

#include <QPushButton>
#include <QWidget>
#include "DualPortInterface.h"

namespace Ui {
class GraphicsDataNode;
}

using InputPortType = QPushButton;
using OutputPortType = QPushButton;

class GraphicsDataNode : public QWidget,public DualPortInterface
	Q_OBJECT

public:
    explicit GraphicsDataNode(QWidget *parent = nullptr);
    ~GraphicsDataNode();
    virtual InputPortType* getInputPort() override;
    virtual OutputPortType* getOutputPort() override;

private:
    Ui::GraphicsDataNode *ui;

	// QWidget interface
protected:
	virtual void mousePressEvent(QMouseEvent *event) override;


    // OutputPortInterface interface
    public:
    virtual QPointF getOutputPortCoordinate(const QGraphicsItem *item) override;

    // InputPortInterface interface
    public:
    virtual QPointF getInputPortCoordinate(const QGraphicsItem *item) override;
    };


#endif // GraphicsDataNode_H
