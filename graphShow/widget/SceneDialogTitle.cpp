#include "SceneDialogTitle.h"
#include "ui_SceneDialogTitle.h"

SceneDialogTitle::SceneDialogTitle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SceneDialogTitle)
{
    ui->setupUi(this);
    ui->label->setText("主题");
}

SceneDialogTitle::~SceneDialogTitle()
{
    delete ui;
}
