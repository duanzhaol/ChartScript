#include "GraphShowWindow.h"
#include "ui_GraphShowWindow.h"
#include"widget/sceneDialogTheme.h"
#include"widget/SceneDialogTitle.h"
#include<QDebug>
#include <QStringListModel>
#include <QPieSeries>
#include <QFileDialog>
#include <graphShow/AttributeDialog/BackgroundDialog.h>
#include <Interpreter/Transmitter/GraphShowTransmitter.h>

GraphShowWindow::GraphShowWindow(QWidget *parent) :
    QWidget(parent),
	ui(new Ui::GraphShowWindow)
{
    ui->setupUi(this);
    initialListWidget();
}

void GraphShowWindow::setScene(GraphicsScene *myScene)
{
    ui->graphicsView->setScene(myScene);

	connect(chartListWidget,&ListWidget::itemDoubleClicked,
			this,&GraphShowWindow::sendChart_Transmitter);

	connect(this,&GraphShowWindow::sendChart,
			dynamic_cast<GraphicsScene*>(ui->graphicsView->scene()),&GraphicsScene::recieveChart);

	connect(designElementsListWidget,&QListWidget::itemDoubleClicked,
			dynamic_cast<GraphicsScene*>(ui->graphicsView->scene()),&GraphicsScene::recieveGraphics);

	connect(this,&GraphShowWindow::selectAll,
			dynamic_cast<GraphicsScene*>(ui->graphicsView->scene()),&GraphicsScene::selectAll);

	connect(this,&GraphShowWindow::toTop,
			dynamic_cast<GraphicsScene*>(ui->graphicsView->scene()),&GraphicsScene::toTop);

	connect(myScene,&GraphicsScene::mouseMove,this,&GraphShowWindow::setCursorCoor);

	connect(&GraphShowTransmitter::getInstance(),&GraphShowTransmitter::sendChart,
			chartListWidget,&ListWidget::reciveChart);

	scene = myScene;
}

GraphShowWindow::~GraphShowWindow()
{
    delete ui;
}

/**
 * @brief myWindow::on_pushButton_theme_clicked
 * 点击主题改变按钮的槽函数
 */
void GraphShowWindow::on_pushButton_theme_clicked()
{
	SceneDialogTheme *sceneDialogTheme=new SceneDialogTheme(this);
    sceneDialogTheme->show();
	connect(sceneDialogTheme,&SceneDialogTheme::ThemeChange,
			dynamic_cast<GraphicsScene*>(ui->graphicsView->scene()),&GraphicsScene::ThemeChanged);
}

/**
 * @brief myWindow::sendChart_Transmitter
 * 提取QListWidgetItem的索引对应的Chart，通过信号函数进行发送
 * @param item
 */
void GraphShowWindow::sendChart_Transmitter(QListWidgetItem *item)
{
	int row=chartListWidget->row(item);
	ChartItem* chart=chartListWidget->getChart(row);
    emit sendChart(chart);
}

void GraphShowWindow::initialListWidget()
{
	chartListWidget = new ListWidget(ui->tabWidget);
	designElementsListWidget = new ListWidget(ui->tabWidget);

	chartListWidget->setParent(ui->tabWidget);
	chartListWidget->setViewMode(QListView::IconMode);
    //设置QListWidget中单元项的图片大小
	chartListWidget->setIconSize(QSize(100,100));
    //设置QListWidget中单元项的间距
	chartListWidget->setSpacing(10);
    //设置自动适应布局调整（Adjust适应，Fixed不适应），默认不适应
	chartListWidget->setResizeMode(QListWidget::Adjust);
    //设置不能移动
	chartListWidget->setMovement(QListWidget::Static);

	designElementsListWidget->setParent(ui->tabWidget);
	designElementsListWidget->setViewMode(QListView::IconMode);
	designElementsListWidget->setIconSize(QSize(100,100));
	designElementsListWidget->setSpacing(10);
	designElementsListWidget->setResizeMode(QListWidget::Adjust);
	designElementsListWidget->setMovement(QListWidget::Static);

	ListWidgetItem *item3=new ListWidgetItem(designElementsListWidget);
	item3->setText(QStringLiteral("矩形"));
	item3->setIcon(QIcon(":/GraphShowImage/image/rect.png"));
    item3->setSizeHint(QSize(100,120));

	ListWidgetItem *item4=new ListWidgetItem(designElementsListWidget);
	item4->setText(QStringLiteral("椭圆"));
	item4->setIcon(QIcon(":/GraphShowImage/image/ellipse.png"));
    item4->setSizeHint(QSize(100,120));

	ListWidgetItem *item5 = new ListWidgetItem(designElementsListWidget);
	item5->setText(QStringLiteral("文本框"));
	item5->setIcon(QIcon(":/GraphShowImage/image/textBox.png"));
	item5->setSizeHint(QSize(100,120));

	ListWidgetItem *item6 = new ListWidgetItem(designElementsListWidget);
	item6->setText(QStringLiteral("图片"));
	item6->setIcon(QIcon(":/GraphShowImage/image/addPixmap.png"));
	item6->setSizeHint(QSize(100,120));

	ListWidgetItem *item7 = new ListWidgetItem(designElementsListWidget);
	item7->setText(QStringLiteral("三角形"));
	item7->setIcon(QIcon(":/GraphShowImage/image/triangle.png"));
	item7->setSizeHint(QSize(100,120));

   // listWidget1->addItemAll(chart,item1);
	//listWidget1->addItemAll(chart,item2);
	designElementsListWidget->addItem(item3);
	designElementsListWidget->addItem(item4);
	designElementsListWidget->addItem(item5);
	designElementsListWidget->addItem(item6);
	designElementsListWidget->addItem(item7);

	ui->tabWidget->addTab(chartListWidget,QStringLiteral("统计图元素"));
	ui->tabWidget->addTab(designElementsListWidget,QStringLiteral("设计元素"));

}




/**
 * @brief myWindow::on_pushButton_shadow_clicked
 * 点击了选择全部按钮
 */
void GraphShowWindow::on_pushButton_shadow_clicked()
{
	emit selectAll(true);
}

void GraphShowWindow::on_pushButton_top_clicked()
{
	emit toTop();
}

void GraphShowWindow::setCursorCoor(const QPointF &point)
{
	ui->cursorCoor->setText(QStringLiteral("鼠标:")+QString("%1,%2")
							.arg(point.x())
							.arg(point.y()));
}



void GraphShowWindow::on_backgroundSet_clicked()
{
	BackgroundDialog* dialog = new BackgroundDialog(
	{ui->graphicsView->getImage(),ui->graphicsView->backgroundBrush()},this);
	connect(dialog,&BackgroundDialog::confirm,this,[this](const BackgroundDialog::Result&result){
		if(result.image.has_value()){
			ui->graphicsView->setImage(result.image.value());
		}
		else{
			ui->graphicsView->setImage(QImage());
		}
		ui->graphicsView->setBackgroundBrush(result.brush);
	});
	dialog->show();
}

void GraphShowWindow::on_exportPushbuttom_clicked()
{
	emit selectAll(false);
	QString fileName = QFileDialog::getSaveFileName(this,
								 QStringLiteral("保存图片"),
								 R"(C:\)",
								 tr("Windows Bitmap(*.bmp)"
									";;Joint Photographic Experts Group(*.jpg)"
									";;Joint Photographic Experts Group(*.jpeg)"
									";;Portable Network Graphics(*.png)"
									";;Portable Pixmap(*.ppm)"
									";;X11 Bitmap(*.xbm)"
									";;X11 Pixmap(*.xpm)"));

	QPixmap *shortCut = ui->graphicsView->getPixmap();
	shortCut->save(fileName,nullptr,100);

}
