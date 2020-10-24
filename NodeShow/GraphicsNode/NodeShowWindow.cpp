#include "ConnectController.h"
#include "NodeShowWindow.h"
#include "ui_NodeShowWindow.h"
#include "GraphicsAreaSeriesNode.h"
#include "GraphicsChartNode.h"
#include "GraphicsDataArrayNode.h"
#include "GraphicsLineSeriesNode.h"
#include "GraphicsPieSeriesNode.h"
#include "GraphicsScatterSeriesNode.h"
#include "GraphicsStartNode.h"
#include "ScalingGraphicsView.h"
#include <ConnectLineItem.h>
#include <Interpreter/Interpreter/InterpreterController.h>
#include <QDebug>
#include <QPixmap>
#include <GraphicsTopArrayNode.h>
#include <QFileDialog>
#include "Interpreter/Interpreter/InterpreterController.h"
#pragma execution_character_set("utf-8")

NodeShowWindow::NodeShowWindow(QWidget *parent) :
	  QMainWindow(parent),
	  ui(new Ui::NodeShowWindow)
{
	ui->setupUi(this);
    ui->mouseTypeState->setAlignment(Qt::AlignHCenter);
    ui->lcdNumber->setDecMode();

    connect(this,&NodeShowWindow::MouseTypechanged,
            ConnectController::getInstance(),&ConnectController::clearPort);

    connect(this,&NodeShowWindow::newArray,ui->listWidget_2,
            &NodeListWidget::reciveArray);

	GraphicsStartNode*start = new GraphicsStartNode(new MovableProxyWidget);

	InterpreterController::getGlobalInstance()->setStartNode(start);

	connect(ui->startCompileButton,&QPushButton::clicked,start,&GraphicsStartNode::start);

	ui->graphicsView->setScene(scene);

	ui->graphicsView->setStyleSheet("padding:0px;border:0px");

	scene->addItem(start->getProxy());

	init();

    ui->graphicsView->setStyleSheet(R"(QGraphicsView{ background-image:url(:/img/img/beijing.png);})");//设置scene背景
	ui->graphicsView->showMaximized();//全屏窗口打开

	ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);//流畅刷新



}

NodeShowWindow::~NodeShowWindow()
{
	delete ui;
}

void NodeShowWindow::createWindow()
{
	instance = new NodeShowWindow;
}

NodeShowWindow *NodeShowWindow::getInstance()
{
    return instance;
}

void NodeShowWindow::setLcdNumber(int number)
{
    ui->lcdNumber->display(number);
}

void NodeShowWindow::init()
{
	ui->listWidget->setViewMode(QListView::IconMode);
	ui->listWidget->setIconSize(QSize(100,100));
	ui->listWidget->setSpacing(10);
	ui->listWidget->setResizeMode(QListWidget::Adjust);
	ui->listWidget->setMovement(QListWidget::Static);

	QListWidgetItem *chartItem=new QListWidgetItem(ui->listWidget);
	chartItem->setText("统计图结点");

	chartItem->setIcon(QIcon(":/img/img/node/chartNode.png"));

	chartItem->setSizeHint(QSize(140,130));

}


void NodeShowWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{

	if(item->text()=="统计图结点"){
		GraphicsChartNode*chartNode = new GraphicsChartNode(new MovableProxyWidget);
		scene->addItem(chartNode->getProxy());
	}

}

void NodeShowWindow::on_MoveButton_clicked()
{
    mouseType=NodeShowMouseType::Move;
    ui->mouseTypeState->setText("当前状态：移动");
    emit MouseTypechanged();
}

void NodeShowWindow::on_ConnectButton_clicked()
{
    mouseType=NodeShowMouseType::Connect;
    ui->mouseTypeState->setText("当前状态：连线");
}

void NodeShowWindow::on_DeleteButton_clicked()
{
    mouseType=NodeShowMouseType::Delete;
    ui->mouseTypeState->setText("当前状态：删除");
    emit MouseTypechanged();
}


void NodeShowWindow::on_listWidget_2_itemDoubleClicked(QListWidgetItem *item)
{
    auto nodeItem=dynamic_cast<NodeListWidgetItem*>(item);
    int index=nodeItem->getItemIndex();
	auto node = ui->listWidget_2->getArrayNode(index);
	scene->addItem(node->getProxy());
}



void NodeShowWindow::on_toCodeButton_clicked()
{
    ModelCodingInterpreter* modelCodingInterpreter=new ModelCodingInterpreter(
        InterpreterController::getGlobalInstance());

    QString code=modelCodingInterpreter->coding();


        QString fileName = QFileDialog::getSaveFileName(this,
                                                        QStringLiteral("SaveCode"),
                                                        R"(C:\)",
                                                        tr("Text files (*.txt)"));
        QFile myfile(fileName);//创建一个输出文件的文档
        if (myfile.open(QFile::WriteOnly|QFile::Text))//注意WriteOnly是往文本中写入的时候用，ReadOnly是在读文本中内容的时候用，Truncate表示将原来文件中的内容清空
        {
            QTextStream out(&myfile);
            out << code;
            myfile.close();
        }


        modelCodingInterpreter->~ModelCodingInterpreter();
}

NodeShowWindow* NodeShowWindow::instance = nullptr;
