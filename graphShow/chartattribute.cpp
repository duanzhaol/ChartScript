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
	this->setWindowTitle(QStringLiteral("属性设置"));//设置左上角标题
	connect(ui->confirmAttr,&QPushButton::clicked,this,&ChartAttribute::confirm);
}

ChartAttribute::~ChartAttribute()
{
    delete ui;
}


Ui::ChartAttribute* ChartAttribute::getUi(){
	return ui;
}

QString ChartAttribute::getSelectColor() const
{
	return ui->comboBox_SelectColor->currentText();
}

QString ChartAttribute::getZoomColor() const
{
	return ui->comboBox_ZoomColor->currentText();
}

