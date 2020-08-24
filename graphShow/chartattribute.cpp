#include "ChartAttribute.h"
#include "ui_ChartAttribute.h"
#include<QDebug>
ChartAttribute::ChartAttribute(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChartAttribute)
{
    ui->setupUi(this);
    ui->comboBox_ZoomColor->clear();
    QStringList strList;
    strList<<"White"<<"Red";
    ui->comboBox_ZoomColor->addItems(strList);
    ui->comboBox_SelectColor->addItems(strList);

}

ChartAttribute::~ChartAttribute()
{
    delete ui;
}



void ChartAttribute::on_confirmAttr_clicked(){
    qDebug()<<"123";
    this->close();

}
Ui::ChartAttribute* ChartAttribute::getUi(){
    return ui;
}

