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

/**
 * @brief GraphicsDataArrayNode::getNodeData
 * @return nodeData：有类型有值的QVariant
 */

QVariant GraphicsDataArrayNode::getNodeData() const
{
    QVariant nodeData(getElementType());
    nodeData.setValue(ui->dataArrayNodeData->text().toInt());
    return nodeData;
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


/**
 * @brief GraphicsDataArrayNode::setElementType
 * @param type
 * @note  设置模型类型，设置个字符串名字就行 10/7
 */
void GraphicsDataArrayNode::setElementType(QVariant::Type type)
{
    if(type==QVariant::Type::Int)
    {
        ui->comboBox->currentText()="int";
    }
    else if(type==QVariant::Type::LongLong)
    {
        ui->comboBox->currentText()="long long";
    }
    else if(type==QVariant::Type::Double)
    {
        ui->comboBox->currentText()="double";
    }
    else if(type==QVariant::Type::String)
    {
        ui->comboBox->currentText()="String";
    }

}
