#include "MainWidget.h"
#include "ui_MainWidget.h"
#include "Setting.h"

#pragma execution_character_set("utf-8")


//1。重写tablewidget，1.保存数据 2.维护数据类型信息3.一键改类型
//2.维护一个tablelistwidget，用来保存表格
//3.zycnm

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
}

MainWidget::~MainWidget()
{
    delete ui;
}

MainWidget *MainWidget::getInstance()
{
    return instance;
}

void MainWidget::createWidget()
{
    instance = new MainWidget;
}

void MainWidget::on_addColumn_clicked()
{

    TableWidget *table=getTableNow();

    QList<QTableWidgetItem*> items = table->selectedItems();
    int current=-1;
    TableArrayItem *arrItem=nullptr;

    if(!items.isEmpty()){

        QTableWidgetItem* item=items.first();
        current= item->column()+1;

        arrItem=table->insertColumn(current);
    }else{
        current=table->columnCount();
        arrItem=table->insertColumn(current);
    }
    emit newArray(arrItem);
}

void MainWidget::on_addRow_clicked()
{
    TableWidget *table=getTableNow();
    QList<QTableWidgetItem*> items =table->selectedItems();
    int current=-1;
    if(!items.isEmpty()){
		if(items.first()->row()!=0&&items.first()->row()!=1){
			QTableWidgetItem* item=items.first();
			current = item->row()+1;
			table->insertRow(current);
		}

    }else{
        current=table->rowCount();
        table->insertRow(current);
    }
}

void MainWidget::on_deleteColumn_clicked()
{
    TableWidget *table=getTableNow();
    QList<QTableWidgetItem*> items = table->selectedItems();
    int current=-1;
    if(!items.isEmpty()){
        QTableWidgetItem* item=items.first();
        current = item->column();
        table->removeColumn(current);
    }
}


void MainWidget::on_deleteRow_clicked()
{
    TableWidget *table=getTableNow();
    QList<QTableWidgetItem*> items = table->selectedItems();
    int current=-1;
    if(!items.isEmpty()){
        QTableWidgetItem* item=items.first();
        current = item->row();
        table->removeRow(current);
    }
}


void MainWidget::on_exportData_clicked()
{
    TableWidget *table=getTableNow();
    table->checkChangeType();

}



void MainWidget::on_setting_clicked()
{
    Setting setting;
    setting.exec();
}

void MainWidget::on_importCsv_clicked()
{
    TableWidget *table=getTableNow();
    DataLoader *loader=new DataLoader(0,table);//type=0是csv

}

void MainWidget::on_importExcel_clicked()
{
    TableWidget *table=getTableNow();
    DataLoader *loader=new DataLoader(1,table);//type=1是excel
}

void MainWidget::on_addNewTable_clicked()
{
    TableWidget *table=new TableWidget(3,1);
    ui->tabWidget->addTab(table,"新建表格");
    TableArrayItem* item=table->getItems().first();
    emit newArray(item);

}

TableWidget *MainWidget::getTableNow()
{
    int index=ui->tabWidget->currentIndex();
    TableWidget *table=dynamic_cast<TableWidget*>(ui->tabWidget->widget(index));
    return table;
}

MainWidget* MainWidget::instance = nullptr;
