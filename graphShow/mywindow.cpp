#include "mywindow.h"
#include "ui_mywindow.h"
#include"widget/sceneDialogTheme.h"
#include"widget/SceneDialogTitle.h"
#include<QDebug>

myWindow::myWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myWindow)
{
    //ui->graphicsView->
    ui->setupUi(this);

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

