#include "mywindow.h"
#include "ui_mywindow.h"
#include"widget/sceneDialogTheme.h"
#include"widget/SceneDialogTitle.h"
#include<QDebug>
#include <QStringListModel>
#include <QPieSeries>
#include <QFileDialog>

myWindow::myWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myWindow)
{
    //ui->graphicsView->
    ui->setupUi(this);
    initialListWidget();
}

void myWindow::setScene(GraphicsScene *myScene)
{
    ui->graphicsView->setScene(myScene);
	connect(listWidget1,&ListWidget::itemDoubleClicked,this,&myWindow::sendChart_Transmitter);
    connect(this,&myWindow::sendChart,dynamic_cast<GraphicsScene*>(ui->graphicsView->scene()),&GraphicsScene::recieveChart);
	connect(listWidget2,&QListWidget::itemDoubleClicked,dynamic_cast<GraphicsScene*>(ui->graphicsView->scene()),&GraphicsScene::recieveGraphics);
    connect(this,&myWindow::selectAll,dynamic_cast<GraphicsScene*>(ui->graphicsView->scene()),&GraphicsScene::selectAll);
    connect(this,&myWindow::toTop,dynamic_cast<GraphicsScene*>(ui->graphicsView->scene()),&GraphicsScene::toTop);
	connect(myScene,&GraphicsScene::mouseMove,this,&myWindow::setCursorCoor);
}

myWindow::~myWindow()
{
    delete ui;
}

/**
 * @brief myWindow::on_pushButton_theme_clicked
 * 点击主题改变按钮的槽函数
 */
void myWindow::on_pushButton_theme_clicked()
{
	SceneDialogTheme *sceneDialogTheme=new SceneDialogTheme(this);
    sceneDialogTheme->show();
    connect(sceneDialogTheme,&SceneDialogTheme::ThemeChange,dynamic_cast<GraphicsScene*>(ui->graphicsView->scene()),&GraphicsScene::ThemeChanged);
}

/**
 * @brief myWindow::sendChart_Transmitter
 * 提取QListWidgetItem的索引对应的Chart，通过信号函数进行发送
 * @param item
 */
void myWindow::sendChart_Transmitter(QListWidgetItem *item)
{
	int row=listWidget1->row(item);
    qDebug()<<row;
	ChartItem* chart=listWidget1->getChart(row);
    emit sendChart(chart);
}

void myWindow::initialListWidget()
{
	listWidget1 = new ListWidget(ui->tabWidget);
	listWidget2 = new ListWidget(ui->tabWidget);

	listWidget1->setParent(ui->tabWidget);
	listWidget1->setViewMode(QListView::IconMode);
    //设置QListWidget中单元项的图片大小
	listWidget1->setIconSize(QSize(100,100));
    //设置QListWidget中单元项的间距
	listWidget1->setSpacing(10);
    //设置自动适应布局调整（Adjust适应，Fixed不适应），默认不适应
	listWidget1->setResizeMode(QListWidget::Adjust);
    //设置不能移动
	listWidget1->setMovement(QListWidget::Static);

	listWidget2->setParent(ui->tabWidget);
	listWidget2->setViewMode(QListView::IconMode);
	listWidget2->setIconSize(QSize(100,100));
	listWidget2->setSpacing(10);
	listWidget2->setResizeMode(QListWidget::Adjust);
	listWidget2->setMovement(QListWidget::Static);

    ChartItem *chart =  new ChartItem();
    chart->createDefaultAxes();
    //圆饼图元素
    auto pie = new ::QtCharts::QPieSeries;
    //添加测试数据
    pie->append(new ::QtCharts::QPieSlice("blue",20));
    pie->append(new ::QtCharts::QPieSlice("red",20));
    qDebug() <<"左键点击选中了一个chart！";
    chart->addSeries(pie);
    pie->setVisible(true);
    chart->setVisible(true);
    chart->setPos(5,5);
    chart->setGeometry(5,5,800,800);
    chart->setFlag(QGraphicsItem::ItemIsMovable,true);
    chart->setFlag(QGraphicsItem::ItemIsSelectable,true);
    chart->acceptDrops();


	ListWidgetItem *item3=new ListWidgetItem(listWidget2);
	item3->setText(QStringLiteral("矩形"));
	item3->setIcon(QIcon(":/GraphShowImage/image/rect.png"));
    item3->setSizeHint(QSize(100,120));

	ListWidgetItem *item4=new ListWidgetItem(listWidget2);
	item4->setText(QStringLiteral("椭圆"));
	item4->setIcon(QIcon(":/GraphShowImage/image/ellipse.png"));
    item4->setSizeHint(QSize(100,120));

	ListWidgetItem *item5 = new ListWidgetItem(listWidget2);
	item5->setText(QStringLiteral("文本框"));
	item5->setIcon(QIcon(":/GraphShowImage/image/textBox.png"));
	item5->setSizeHint(QSize(100,120));

	ListWidgetItem *item6 = new ListWidgetItem(listWidget2);
	item6->setText(QStringLiteral("图片"));
	item6->setIcon(QIcon(":/GraphShowImage/image/addPixmap.png"));
	item6->setSizeHint(QSize(100,120));

	ListWidgetItem *item7 = new ListWidgetItem(listWidget2);
	item7->setText(QStringLiteral("三角形"));
	item7->setIcon(QIcon(":/GraphShowImage/image/triangle.png"));
	item7->setSizeHint(QSize(100,120));

   // listWidget1->addItemAll(chart,item1);
	//listWidget1->addItemAll(chart,item2);
	listWidget2->addItem(item3);
	listWidget2->addItem(item4);
	listWidget2->addItem(item5);
	listWidget2->addItem(item6);
	listWidget2->addItem(item7);

	ui->tabWidget->addTab(listWidget1,QStringLiteral("统计图元素"));
	ui->tabWidget->addTab(listWidget2,QStringLiteral("设计元素"));

}




/**
 * @brief myWindow::on_pushButton_shadow_clicked
 * 点击了选择全部按钮
 */
void myWindow::on_pushButton_shadow_clicked()
{
	emit selectAll(true);
}

void myWindow::on_pushButton_top_clicked()
{
	emit toTop();
}

void myWindow::setCursorCoor(const QPointF &point)
{
	ui->cursorCoor->setText(QStringLiteral("鼠标:")+QString("%1,%2")
							.arg(point.x())
							.arg(point.y()));
}



void myWindow::on_backgroundSet_clicked()
{
	QString fileName = QFileDialog::getOpenFileName(this,
													QStringLiteral("打开图片"),
													R"(C:\)",
													tr("All image(*.bmp *.jpg *.jpeg *.png *.ppm *.xbm *.xpm *.gif *.pbm *.pgm)"
													   ";;Windows Bitmap(*.bmp)"
													   ";;Joint Photographic Experts Group(*.jpg)"
													   ";;Joint Photographic Experts Group(*.jpeg)"
													   ";;Portable Network Graphics(*.png)"
													   ";;Portable Pixmap(*.ppm)"
													   ";;X11 Bitmap(*.xbm)"
													   ";;X11 Pixmap(*.xpm)"
													   ";;Graphic Interchange Format(*.gif)"
													   ";;Portable Bitmap(*.pbm)"
													   ";;Portable Graymap(*.pgm)"));

	this->setStyleSheet(QString(R"(QGraphicsView{ background-image:url(%1);})")
						.arg(fileName));
}

void myWindow::on_exportPushbuttom_clicked()
{
	emit selectAll(false);
	QPixmap pixmap = ui->graphicsView->grab();
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

	qDebug()<<fileName<<endl;
	pixmap.save(fileName,nullptr,100);
}
