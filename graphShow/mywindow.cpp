#include "mywindow.h"
#include "ui_mywindow.h"
#include"widget/sceneDialogTheme.h"
#include"widget/SceneDialogTitle.h"
#include<QDebug>
#include <QStringListModel>
myWindow::myWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myWindow)
{
    //ui->graphicsView->
    ui->setupUi(this);
    QStringList theStrList; //保存初始 StringList
    theStrList<<"北京"<<"上海"<<"天津"<<"河北"<<"山东"<<"四川"<<"重庆"<<"广东"<<"河南"; //初始化 StringList
    auto theModel=new QStringListModel(this);

            //setStringList() 函数可以初始化数据模型的字符串列表的内容
            //也就是把数据装进这个盒子里
    theModel->setStringList(theStrList);
    ui->listView->setModel(theModel);
}

void myWindow::setScene(GraphicsScene *myScene)
{
    ui->graphicsView->setScene(myScene);
}

myWindow::~myWindow()
{
    delete ui;
}


void myWindow::on_pushButton_theme_clicked()
{
    SceneDialogTheme *sceneDialogTheme=new SceneDialogTheme();
    sceneDialogTheme->show();
    connect(sceneDialogTheme,&SceneDialogTheme::ThemeChange,dynamic_cast<GraphicsScene*>(ui->graphicsView->scene()),&GraphicsScene::ThemeChanged);
}

void myWindow::on_pushButton_title_clicked()
{
    SceneDialogTitle *sceneDialogTitle=new SceneDialogTitle();
    sceneDialogTitle->show();
}

