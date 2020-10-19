#include "GraphicsDataArrayNode.h"
#include "ui_GraphicsDataArrayNode.h"

#include <QListView>
#include <QDebug>
#include <QMessageBox>

#include <Interpreter/Interpreter/InterpreterController.h>

#include <Interpreter/Exception/NodeNameConflictException.h>

#include <UTools/UniqueNamer.h>
#include <NodeShowWindow.h>

#pragma execution_character_set("utf-8")

/**
 * @bug ui里的信息数据更新不及时
 */

TableArrayInterface *GraphicsDataArrayNode::getTableArrayInterface() const
{
    Q_ASSERT(tableArrayInterface != nullptr);
    return tableArrayInterface;
}

void GraphicsDataArrayNode::setTableArrayInterface(TableArrayInterface *value)
{
    tableArrayInterface = value;
    Q_ASSERT(tableArrayInterface!=nullptr);

    setNodeData(tableArrayInterface->getArrayData());
    setNodeName(tableArrayInterface->getArrayName());
    setElementType(tableArrayInterface->getArrayType());
}

GraphicsDataArrayNode::GraphicsDataArrayNode(QWidget *parent) :
    ui(new Ui::GraphicsDataArrayNode)
{
    ui->setupUi(this);
    ui->comboBox->setView(new QListView());


    //    qDebug()<<this->mapTo(NodeShowWindow::getInstance(),this->pos());

    /*两个单独lineedit文字居中*/
    ui->dataArrayNodeName->setAlignment( Qt::AlignHCenter); //数据节点的名字居中显示
    ui->dataArrayNodeData->setAlignment( Qt::AlignHCenter); //数据节点的数据居中显示

    ui->inputPort->setParent(this);
    ui->outputPort->setParent(this);
	this->initName();



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
    return tableArrayInterface->getArrayName();
}

void GraphicsDataArrayNode::setNodeName(const NodeName &newNodeName)
{
    ui->dataArrayNodeName->setText(newNodeName);
    tableArrayInterface->setArrayName(newNodeName);
}

/**
 * @brief GraphicsDataArrayNode::getNodeData
 * @return nodeData：有类型有值的QVariant
 */

QVariant GraphicsDataArrayNode::getNodeData() const
{
    QVariant list(QVariant::Type::List);
    list.setValue(tableArrayInterface->getArrayData());
    return list;
}

void GraphicsDataArrayNode::setNodeData(const QVariant &newData)
{
    ui->dataArrayNodeData->setText(newData.toString());
    tableArrayInterface->setArrayData(newData.toList());
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
    return tableArrayInterface->getArrayType();
}


/**
 * @brief GraphicsDataArrayNode::setElementType
 * @param type
 * @note  设置模型类型，设置个字符串名字就行 10/7
 */
void GraphicsDataArrayNode::setElementType(QVariant::Type type)
{
    tableArrayInterface->setArrayType(type);
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

class ArrayInterface{
	//! 获取一列数据
	virtual QVariantList getArrayData() = 0;
    //! 获取数据类型
	virtual QVariant::Type getArrayType() = 0;
	//! 获取列的名字
	virtual QString getArrayName() = 0;
};

void GraphicsDataArrayNode::on_inputPort_clicked()
{
    //emit PortClicked(ui->inputPort,"inputPort");
    emit PortClicked(this,PortType::InputPort);
}

void GraphicsDataArrayNode::on_outputPort_clicked()
{
    emit PortClicked(this,PortType::OutputPort);
    //emit PortClicked(ui->outputPort,"outputPort");
}




/**
 * @brief GraphicsDataArrayNode::on_dataArrayNodeName_editingFinished
 * 选择原因：当按返回或者回车键时，或者行编辑失去焦点时，发出此信号。
 *
 */
void GraphicsDataArrayNode::on_dataArrayNodeName_editingFinished()
{
	qDebug()<<ui->dataArrayNodeName->text();
    try {
        this->testNodeNameIfDuplicate(ui->dataArrayNodeName->text());
	} catch (NodeNameConflictException &e) {
        qDebug()<<e.getWhy();

        //messageBox
		QMessageBox::information(nullptr, "结点命名重复", "请重新命名！");
        setNodeName(UniqueNamerPool::getNamer(NamerSeed::GraphShow).getUniqueName());
    }
	setNodeName(ui->dataArrayNodeName->text());
}

//void GraphicsDataArrayNode::on_dataArrayNodeName_textChanged(const QString &arg1)
//{
//    try {

//        this->testNodeNameIfDuplicate(arg1);
//    } catch (NodeNameConflictException e) {
//        qDebug()<<e.getWhy();

//        //messageBox
//        QMessageBox::information(NULL, "结点命名重复", "请重新命名！");
//        setNodeName(UniqueNamerPool::getNamer(NamerSeed::GraphShow).getUniqueName());
//    }
//}
