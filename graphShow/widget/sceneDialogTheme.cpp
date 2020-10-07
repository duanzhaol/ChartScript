#include "sceneDialogTheme.h"
#include "ui_scenedialogtheme.h"
#include<QDebug>
SceneDialogTheme::SceneDialogTheme(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sceneDialogTheme)
{
    ui->setupUi(this);
    QStringList strList;
    strList<<"Light"<<"BlueCerulean"<<"Dark"<<"BrownSand"
          <<"BlueNcs"<<"HighContrast"<<"BlueIcy"<<"Qt";
    ui->comboBox->addItems(strList);
    ui->label->setText("主题");
}

SceneDialogTheme::~SceneDialogTheme()
{
    delete ui;
}

void SceneDialogTheme::on_buttonBox_accepted()
{
    //qDebug()<<"123";
    emit ThemeChange(ui->comboBox->currentIndex());
}
