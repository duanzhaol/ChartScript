﻿#ifndef GRAPHICSDATAARRAYNODE_H
#define GRAPHICSDATAARRAYNODE_H

#include "../Dualputable.h"
#include <QComboBox>
#include <QPushButton>
#include <QWidget>
#include <Interpreter/DataModel/AbstractArrayNode.h>
#include <Interpreter/DataModel/AbstractDataNode.h>
#include <Interpreter/DataModel/AbstractDataNode.h>
#include "AbstractGraphicsInnerDualputNode.h"



namespace Ui {
class GraphicsDataArrayNode;
}

class GraphicsDataArrayNode : public AbstractGraphicsInnerDualputNode, public AbstractArrayNode
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

	// Outputable interface
public:
    virtual OutputPort *getOutputPort() override;

	// Inputable interface
public:
    virtual InputPort *getInputPort() override;

	// GraphicsArrayNodeInterface interface
public:
    virtual QVariant::Type getElementType() const override;
	virtual void setElementType(QVariant::Type type) override;

private slots:
    void on_inputPort_clicked();
    void on_outputPort_clicked();
    void on_dataArrayNodeName_editingFinished();
//    void on_dataArrayNodeName_textChanged(const QString &arg1);
};



#endif // GRAPHICSDATAARRAYNODE_H