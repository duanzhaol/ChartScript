#ifndef GraphicsDataNode_H
#define GraphicsDataNode_H

#include <QPushButton>
#include <QWidget>
#include "DualPortWidget.h"

namespace Ui {
class GraphicsDataNode;
}

using InputPort = QPushButton;
using OutputPort = QPushButton;

class GraphicsDataNode : public DualPortWidget{
	Q_OBJECT

public:
    explicit GraphicsDataNode(QWidget *parent = nullptr);
	~GraphicsDataNode()override;

	// OutputPortWidget interface
public:
	virtual OutputPort *getOutputPort() override;

	// InputPortWidget interface
public:
	virtual InputPort *getInputPort() override;

private:
	Ui::GraphicsDataNode *ui;
};








#endif // GraphicsDataNode_H
