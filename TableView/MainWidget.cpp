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

	on_addNewTable_clicked();


}
//    QListWidgetItem* item = new QListWidgetItem();
//    item->setData(0,tr("信息统计表"));
//    item->setData(Qt::UserRole + 1,"222");//其他数据
//    ui->listWidget->addItem(item);
//    ui->listWidget->addItem(new QListWidgetItem(tr("趋势记录表")));
//    ui->listWidget->addItem(new QListWidgetItem(tr("平均年收入")));
//    //点击
//    connect(ui->listWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(ListItemClicked(QListWidgetItem*)));

//    //右键
//    ui->listWidget->setContextMenuPolicy(Qt::CustomContextMenu);


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





//void MainWidget::setTable(int row,int col,QString s)
//{
//    for(int i = 0;i < row;i++)
//    {
//        for(int j = 0;j < col;j++)
//        {
//            QTableWidgetItem* item = new QTableWidgetItem();
//            item->setText(s);
//            ui->tableWidget->setItem(i,j,item);//必须新建item指针
//        }
//    }
////    ui->tableWidget->clear();

//}

//void MainWidget::ListItemClicked(QListWidgetItem* item)
//{

//    QString s = item->text();
////    qDebug() << t;
//    int row = 0, col = 0;
//    if(s == tr("信息统计表"))    row = 6,col = 5;
//    if(s == tr("趋势记录表"))    row = 1,col = 1;
//    if(s == tr("平均年收入"))    row = 2,col = 2;
//    ui->tableWidget->setColumnCount(row);
//    ui->tableWidget->setRowCount(col);
//    setTable(row,col,s);
//}



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
    //table->setHorizontalHeaderItem(0,new QTableWidgetItem("请命名"));
    //table->insertColumn(0);    //    item->setText("新建表格");
    //    ui->listWidget->addItem(item);
    //    ui->tableWidget->setColumnCount(1);
    //    ui->tableWidget->setRowCount(1);

}

TableWidget *MainWidget::getTableNow()
{
    int index=ui->tabWidget->currentIndex();
    TableWidget *table=dynamic_cast<TableWidget*>(ui->tabWidget->widget(index));
    return table;
}

MainWidget* MainWidget::instance = nullptr;
