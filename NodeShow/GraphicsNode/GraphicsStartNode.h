#ifndef GRAPHICSSTARTNODE_H
#define GRAPHICSSTARTNODE_H

#include <QWidget>
#include "OutputPortWidget.h"

namespace Ui {
class GraphicsStartNode;
}

class GraphicsStartNode : public OutputPortWidget
{
    Q_OBJECT

public:
    explicit GraphicsStartNode(QWidget *parent = nullptr);
    ~GraphicsStartNode();

private:
    Ui::GraphicsStartNode *ui;

	// InputPortWidget interface
public:
	virtual OutputPort *getOutputPort() override;
};



#endif // GRAPHICSSTARTNODE_H
