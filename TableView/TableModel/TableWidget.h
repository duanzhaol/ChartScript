#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H
#include<QTableWidget>
#include"TableArrayItem.h"
#include<QComboBox>
#include<QDebug>

class TableWidget:public QTableWidget
{    
    QList<TableArrayItem*>items;

public:
    TableWidget(int row,int column,QWidget*parent=nullptr);
    void appendArrayItem(TableArrayItem* item);
    void addArrayItem(TableArrayItem* item,int column);
    TableArrayItem* insertColumn(int column);
    void insertRow(int row);
    void removeColumn(int column);
    void removeRow(int row);
    void checkChangeType();
    QList<TableArrayItem*>& getItems();
private:
    QComboBox* createComboBox();
    void showList();
public slots:
    void onCellChanged(int rows,int columns);
    void onTypeChanged(int type);
    void onAddRow(int rows);
    TableArrayItem* onAddColumn(int Column);
    void onDeleteRow(int rows);
    void onDeleteColumn(int Column);

};

#endif // TABLEWIDGET_H
