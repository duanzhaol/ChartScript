#include "GraphicsDataArrayNode.h"
#include "ui_GraphicsDataArrayNode.h"

#include <QListView>
#include <QDebug>
#include <QMessageBox>
#include <Interpreter/Interpreter/InterpreterController.h>
#include <Interpreter/Exception/NodeNameConflictException.h>
#include <UTools/UniqueNamer.h>
#include <NodeShowWindow.h>
#include <QListWidget>


#pragma execution_character_set("utf-8")

/**
 * @bug ui里的信息数据更新不及时
 */

GraphicsDataArrayNode::GraphicsDataArrayNode(QWidget *parent) :
    ui(new Ui::GraphicsDataArrayNode)
{
    ui->setupUi(this);
    ui->comboBox->setView(new QListView());

    ui->dataArrayNodeName->setAlignment( Qt::AlignHCenter); //数据节点的名字居中显示

    ui->inputPort->setParent(this);
    ui->outputPort->setParent(this);
	this->initName();
}

GraphicsDataArrayNode::GraphicsDataArrayNode(const QString name, QWidget *parent):
	ui(new Ui::GraphicsDataArrayNode)
{
	ui->setupUi(this);
	ui->comboBox->setView(new QListView());

	ui->dataArrayNodeName->setAlignment( Qt::AlignHCenter); //数据节点的名字居中显示

	ui->inputPort->setParent(this);
	ui->outputPort->setParent(this);
	ui->dataArrayNodeName->setText(name);
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
    return  ui->dataArrayNodeName->text();
}

void GraphicsDataArrayNode::setNodeName(const NodeName &newNodeName)
{
    ui->dataArrayNodeName->setText(newNodeName);
   // tableArrayInterface->setArrayName(newNodeName);
}

/**
 * @brief GraphicsDataArrayNode::getNodeData
 * @return nodeData：有类型有值的QVariant
 */

QVariant GraphicsDataArrayNode::getNodeData() const
{
	return dataList;
}

void GraphicsDataArrayNode::setNodeData(const QVariant &newData)
{
	dataList = newData.toList();
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

    return QVariant::Type::Invalid;
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
        ui->comboBox->setCurrentText("int");
    }
    else if(type==QVariant::Type::LongLong)
    {
        ui->comboBox->setCurrentText("long long");
    }
    else if(type==QVariant::Type::Double)
    {
        ui->comboBox->setCurrentText("double");
    }
    else if(type==QVariant::Type::String)
    {
        ui->comboBox->setCurrentText("String");
    }

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
        setNodeName(UniqueNamerPool::getNamer(NamerSeed::VariantSeed).getUniqueName());
    }
	setNodeName(ui->dataArrayNodeName->text());
}

void GraphicsDataArrayNode::on_showData_clicked()
{
	QListWidget*list = new QListWidget;

	list->setStyleSheet(R"(
					QListWidget {
						alternate-background-color: yellow;
					}

					QListWidget{
						show-decoration-selected: 1;
				   }
				   QListWidget::item:alternate {
					   background: #EEEEEE;
				   }

				   QListWidget::item:selected {
					   border: 1px solid #6a6ea9;
				   }

				   QListWidget::item:selected:!active {
					   background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,
												   stop: 0 #ABAFE5, stop: 1 #8588B2);
				   }

				   QListWidget::item:selected:active {
					   background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,
												   stop: 0 #6a6ea9, stop: 1 #888dd9);
				   }

				   QListWidget::item:hover {
					   background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,
												   stop: 0 #FAFBFE, stop: 1 #DCDEF1);
				   }
				  )");

	int size = dataList.size();
	list->addItem(QString("数据共有%1项,为:\n").arg(size));
	for(int index = 0;index <size;++index){
		list->addItem(dataList[index].toString());
	}
	connect(list,&QListWidget::close,list,&QListWidget::deleteLater);
	list->show();
}
