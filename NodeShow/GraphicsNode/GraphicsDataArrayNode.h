#ifndef GRAPHICSDATAARRAYNODE_H
#define GRAPHICSDATAARRAYNODE_H

#include "DualPortWidget.h"
#include <QComboBox>
#include <QWidget>
#include <Interpreter/DataModel/AbstractArrayNode.h>
#include <Interpreter/DataModel/AbstractDataNode.h>


namespace Ui {
class GraphicsDataArrayNode;
}

class GraphicsDataArrayNode : public DualPortWidget,public AbstractArrayNode
{
    Q_OBJECT

public:
    explicit GraphicsDataArrayNode(QWidget *parent = nullptr);
    ~GraphicsDataArrayNode();
    QComboBox* getCombobox();

private:
    Ui::GraphicsDataArrayNode *ui;

    // GraphicsNodeInterface interface
public:
    virtual NodeName getNodeName() const override;
    virtual void setNodeName(const NodeName &newNodeName) override;

    // GraphicsDataNodeInterface interface
public:
    virtual QVariant getNodeData() const override;
    virtual void setNodeData(const QVariant &newData) override;

    // OutputPortWidget interface
public:
    virtual OutputPort *getOutputPort() override;

    // InputPortWidget interface
public:
    virtual InputPort *getInputPort() override;


    // GraphicsArrayNodeInterface interface
public:
    virtual QVariant::Type getElementType() const override;
    virtual void setElementType(QVariant::Type type) override;

};



#endif // GRAPHICSDATAARRAYNODE_H
