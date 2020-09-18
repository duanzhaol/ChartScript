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

class GraphicsDataNode : public QWidget{
	Q_OBJECT

public:
    explicit GraphicsDataNode(QWidget *parent = nullptr);
    ~GraphicsDataNode();
	InputPortType* getInputPort();
	OutputPortType* getOutputPort();

private:
    Ui::GraphicsDataNode *ui;

	// QWidget interface
protected:
	virtual void mousePressEvent(QMouseEvent *event) override;
};




#endif // GraphicsDataNode_H
