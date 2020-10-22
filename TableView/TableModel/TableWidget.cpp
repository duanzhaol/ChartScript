#include "TableWidget.h"
#pragma execution_character_set("utf-8")

TableWidget::TableWidget(int row, int column, QWidget *parent):QTableWidget(row,column,parent)
{
	setItem(0,0,new QTableWidgetItem("abc"));
    QComboBox *combobox=createComboBox();
    setCellWidget(1,0,combobox);
    connect(this,&TableWidget::cellChanged,this,&TableWidget::onCellChanged);
    void (QComboBox::*index)(int) = &QComboBox::currentIndexChanged;
    connect(combobox,index,this,&TableWidget::onTypeChanged);
    onAddColumn(0);
}

void TableWidget::appendArrayItem(TableArrayItem *item)
{
    items.append(item);
}

void TableWidget::addArrayItem(TableArrayItem *item, int column)
{
    items.insert(column,item);
    //showList();
}


TableArrayItem* TableWidget::insertColumn(int column)
{
    QTableWidget::insertColumn(column);
    //qDebug()<<"column:"<<column;
    QComboBox *combobox=createComboBox();
    setCellWidget(1,column,combobox);
    void (QComboBox::*index)(int) = &QComboBox::currentIndexChanged;
    connect(combobox,index,this,&TableWidget::onTypeChanged);

    TableArrayItem *arrItem=onAddColumn(column);

	setItem(0,column,new QTableWidgetItem("abc"));
    return arrItem;
}

void TableWidget::insertRow(int row)
{
    QTableWidget::insertRow(row);
    onAddRow(row);
}

void TableWidget::removeColumn(int column)
{
    QTableWidget::removeColumn(column);
    onDeleteColumn(column);
}

void TableWidget::removeRow(int row)
{
    QTableWidget::removeRow(row);
    onDeleteRow(row);
}

QComboBox *TableWidget::createComboBox()
{
    QStringList combobox_list;
    combobox_list.append("string");
    combobox_list.append("int");
    combobox_list.append("double");
    combobox_list.append("long long");
    QComboBox *combobox=new QComboBox();
    combobox->addItems(combobox_list);
    return combobox;
}

void TableWidget::showList()
{
    for(TableArrayItem* item:items){
        QVariantList list=item->getData();
        for(QVariant x:list){
            qDebug()<<x;
        }
        qDebug()<<"-----------------------------------";
    }
    qDebug()<<"############################";
}
/**
 * @brief TableWidget::onCellChanged
 * 确定行和列的更改，只重置一格的数据
 * @param rows
 * @param columns
 */
void TableWidget::onCellChanged(int rows, int columns)
{
    while(rows>=rowCount()){
        insertRow(rowCount());
    }
    while(columns>=columnCount()){
        insertColumn(columnCount());
    }
    TableArrayItem* arrItem=items.at(columns);

    QVariantList &list=arrItem->getData();
    QVariant newCellData=QVariant(item(rows,columns)->data(0));

    list.replace(rows,newCellData);
    //arrItem->getData().replace(rows,item(rows,columns)->data(0));//将list中表格对应位置的值设为当前表格该处的值
    //showList();

	if(rows==0){
		arrItem->onNameChanged();
	}else{
		arrItem->onDataChanged();

	}

}
/**
 * @brief TableWidget::onCellChanged
 * 类型的修改
 * @param rows
 */
void TableWidget::onTypeChanged(int type)
{
    int count=0;
    for(TableArrayItem* item:items){
		int index=dynamic_cast<QComboBox*>(cellWidget(1,count++))->currentIndex();
        switch (index) {
        case 0:
            item->setArrayType(QVariant::String);
            break;
        case 1:
            item->setArrayType(QVariant::Int);
            break;
        case 2:
            item->setArrayType(QVariant::Double);
            break;
        case 3:
            item->setArrayType(QVariant::LongLong);
            break;
        default:
            break;
        }
        item->onTypeChanged();
    }
}

void TableWidget::onAddRow(int rows)
{
    //qDebug()<<"addrow"<<rows;
    for(TableArrayItem* item:items){
        item->getData().insert(rows,NULL);
        item->onDataChanged();
    }
}

TableArrayItem* TableWidget::onAddColumn(int Column)
{
    TableArrayItem *item=new TableArrayItem();
    int row=rowCount();
    QVariantList &list=item->getData();
    int length=list.length();
    //qDebug()<<row<<" "<<length;
    while(length<row){
        list.append("0");
        length++;
    }
    //qDebug()<<row<<" "<<list.length();

    addArrayItem(item,Column);
    return item;
}

void TableWidget::onDeleteRow(int rows)
{
    for(TableArrayItem* item:items){
        item->getData().removeAt(rows);
        item->onDataChanged();
    }

}

void TableWidget::onDeleteColumn(int Column)
{
    TableArrayItem* item=items.at(Column);
    item->onArrayDelete();
    items.removeAt(Column);
    //onArrayDelete

}

void TableWidget::checkChangeType()
{
    for(int i=0;i<columnCount();i++){
        QString type=dynamic_cast<QComboBox*>(cellWidget(1,i))->currentText();
        if(!type.compare("string")){
            for(int j=2;j<rowCount();j++){
                //qDebug()<<j;
                if(item(j,i)!=nullptr){
                    QVariant a=item(j,i)->data(0);
                    QString data=a.toString();
                    a.setValue(data);
                    item(j,i)->setData(0,a);
                    qDebug()<<a.type()<<" "<<a;
                }

            }
        }else if(!type.compare("double")){
            for(int j=2;j<rowCount();j++){
                if(item(j,i)!=nullptr){
                    QVariant a=item(j,i)->data(0);
                    QString data=QString::number(a.toDouble());
                    a.setValue(data);
                    item(j,i)->setData(0,a);
                    qDebug()<<a.type()<<" "<<a;
                }

            }
        }else if(!type.compare("int")){
            for(int j=2;j<rowCount();j++){
                if(item(j,i)!=nullptr){
                    QVariant a=item(j,i)->data(0);
                    QString data=QString::number(a.toInt());
                    a.setValue(data);
                    item(j,i)->setData(0,a);
                    qDebug()<<a.type()<<" "<<a;
                }

            }
        }else if(!type.compare("long long")){

            for(int j=2;j<rowCount();j++){
                if(item(j,i)!=nullptr){
                    QVariant a=item(j,i)->data(0);
                    QString data=QString::number(a.toInt());
                    a.setValue(data);
                    item(j,i)->setData(0,a);
                    qDebug()<<a.type()<<" "<<a;
                }

            }
        }
    }
}

QList<TableArrayItem *> &TableWidget::getItems()
{
    return items;
}
