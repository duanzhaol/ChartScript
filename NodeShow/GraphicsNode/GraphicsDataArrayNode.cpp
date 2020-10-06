#include "GraphicsDataArrayNode.h"
#include "ui_GraphicsDataArrayNode.h"

#include <QListView>

GraphicsDataArrayNode::GraphicsDataArrayNode(QWidget *parent) :
      PortWidget(parent),
      ui(new Ui::GraphicsDataArrayNode)
{
    ui->setupUi(this);
    ui->comboBox->setView(new QListView());

    /*两个单独lineedit文字居中*/
    ui->dataArrayNodeName->setAlignment( Qt::AlignHCenter); //数据节点的名字居中显示
    ui->dataArrayNodeData->setAlignment( Qt::AlignHCenter); //数据节点的数据居中显示

}

GraphicsDataArrayNode::~GraphicsDataArrayNode()
{
    delete ui;
}

QComboBox* GraphicsDataArrayNode::getCombobox()
{
    return ui->comboBox;
}

NodeName GraphicsDataArrayNode::getNodeName() const
{
    return ui->dataArrayNodeName->text();
}

void GraphicsDataArrayNode::setNodeName(const NodeName &newNodeName)
{
    ui->dataArrayNodeName->setText(newNodeName);
}

QVariant GraphicsDataArrayNode::getNodeData() const
{
    return QVariant::fromValue(ui->dataArrayNodeData->text());
}

void GraphicsDataArrayNode::setNodeData(const QVariant &newData)
{
    ui->dataArrayNodeData->setText(newData.toString());
}

OutputPort *GraphicsDataArrayNode::getOutputPort()
{
    return ui->outputPort;
}

InputPort *GraphicsDataArrayNode::getInputPort()
{
    return ui->inputPort;
}

QVariant::Type GraphicsDataArrayNode::getElementType() const
{

    /**
     * 获取combobox当前的text
     * 朱千奥 0923
     *
     */

    QString comboxText = ui->comboBox->currentText();

    if(comboxText=="int"){
        return QVariant::Type::Int;
    }
    else if(comboxText=="String"){
        return QVariant::Type::String;
    }
    else if(comboxText=="float"){
        return QVariant::Type::Double;//无float类型
    }
    else if(comboxText=="double"){
        return QVariant::Type::Double;
    }
    else if(comboxText=="long long"){
        return QVariant::Type::LongLong;
    }
}


void GraphicsDataArrayNode::setElementType(QVariant::Type type)
{
    //todo 设置模型类型，设置个字符串名字就行
}
