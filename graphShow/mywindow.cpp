#include "mywindow.h"
#include "ui_mywindow.h"
#include"widget/sceneDialogTheme.h"
#include"widget/SceneDialogTitle.h"
#include<QDebug>
#include <QStringListModel>
#include <QPieSeries>

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
    connect(ui->listWidget1,&ListWidget::itemDoubleClicked,this,&myWindow::sendChart_Transmitter);
    connect(this,&myWindow::sendChart,dynamic_cast<GraphicsScene*>(ui->graphicsView->scene()),&GraphicsScene::recieveChart);
    connect(ui->listWidget2,&QListWidget::itemDoubleClicked,dynamic_cast<GraphicsScene*>(ui->graphicsView->scene()),&GraphicsScene::recieveGraphics);
    connect(this,&myWindow::selectAll,dynamic_cast<GraphicsScene*>(ui->graphicsView->scene()),&GraphicsScene::selectAll);
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
    SceneDialogTheme *sceneDialogTheme=new SceneDialogTheme();
    sceneDialogTheme->show();
    connect(sceneDialogTheme,&SceneDialogTheme::ThemeChange,dynamic_cast<GraphicsScene*>(ui->graphicsView->scene()),&GraphicsScene::ThemeChanged);
}
/**
 * @brief myWindow::on_pushButton_title_clicked
 * 点击标题改变按钮的槽函数
 */
void myWindow::on_pushButton_title_clicked()
{
    SceneDialogTitle *sceneDialogTitle=new SceneDialogTitle();
    sceneDialogTitle->show();
}
/**
 * @brief myWindow::sendChart_Transmitter
 * 提取QListWidgetItem的索引对应的Chart，通过信号函数进行发送
 * @param item
 */
void myWindow::sendChart_Transmitter(QListWidgetItem *item)
{
    int row=ui->listWidget1->row(item);
    qDebug()<<row;
    ChartItem* chart=ui->listWidget1->getChart(row);
    emit sendChart(chart);
}

void myWindow::initialListWidget()
{
    ui->listWidget1->setParent(ui->tab);
    ui->listWidget1->setViewMode(QListView::IconMode);
    //设置QListWidget中单元项的图片大小
    ui->listWidget1->setIconSize(QSize(100,100));
    //设置QListWidget中单元项的间距
    ui->listWidget1->setSpacing(10);
    //设置自动适应布局调整（Adjust适应，Fixed不适应），默认不适应
    ui->listWidget1->setResizeMode(QListWidget::Adjust);
    //设置不能移动
    ui->listWidget1->setMovement(QListWidget::Static);

    ui->listWidget2->setParent(ui->tab_2);
    ui->listWidget2->setViewMode(QListView::IconMode);
    ui->listWidget2->setIconSize(QSize(100,100));
    ui->listWidget2->setSpacing(10);
    ui->listWidget2->setResizeMode(QListWidget::Adjust);
    ui->listWidget2->setMovement(QListWidget::Static);

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

    ListWidgetItem *item1=new ListWidgetItem(ui->listWidget1);
    item1->setText("aaa");
    item1->setIcon(QIcon("C:/Users/duan/Desktop/2.png"));
    item1->setSizeHint(QSize(100,120));
    ListWidgetItem *item2=new ListWidgetItem(ui->listWidget1);
    item2->setText("bbb");
    item2->setIcon(QIcon("C:/Users/duan/Desktop/2.png"));
    item2->setSizeHint(QSize(100,120));

    ListWidgetItem *item3=new ListWidgetItem(ui->listWidget2);
    item3->setText("rect");
    item3->setIcon(QIcon("C:/Users/duan/Documents/QTProgram/ChartScript/graphShow/image/rect.png"));
    item3->setSizeHint(QSize(100,120));

    ListWidgetItem *item4=new ListWidgetItem(ui->listWidget2);
    item4->setText("ellipse");
    item4->setIcon(QIcon("C:/Users/duan/Documents/QTProgram/ChartScript/graphShow/image/ellipse.png"));
    item4->setSizeHint(QSize(100,120));

    ui->listWidget1->addItemAll(chart,item1);
    ui->listWidget1->addItemAll(chart,item2);
    ui->listWidget2->addItem(item3);
    ui->listWidget2->addItem(item4);
    ui->listWidget1->show();
    ui->listWidget2->show();

}




/**
 * @brief myWindow::on_pushButton_shadow_clicked
 * 点击了选择全部按钮
 */
void myWindow::on_pushButton_shadow_clicked()
{
    emit selectAll();
}
