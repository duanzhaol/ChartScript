#include "ChartAttribute.h"
#include "ui_chartattribute.h"
#include<QDebug>
ChartAttribute::ChartAttribute(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChartAttribute)
{
    ui->setupUi(this);
    ui->comboBox_ZoomColor->clear();
    QStringList strList;
    strList<<"white"<<"black"<<"red"<<"green"<<"blue"<<"cyan"<<"magenta"<<"yellow"<<"gray"<<"transparent";
    ui->comboBox_ZoomColor->addItems(strList);
    ui->comboBox_SelectColor->addItems(strList);

}

ChartAttribute::~ChartAttribute()
{
    delete ui;
}


Ui::ChartAttribute* ChartAttribute::getUi(){
    return ui;
}

