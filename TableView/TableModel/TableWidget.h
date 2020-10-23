#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H
#include<QTableWidget>
#include"TableArrayItem.h"
#include<QComboBox>
#include<QDebug>
/**
 * @brief The TableWidget class
 * 继承的QTableWidget的表格类
 * 1.重写了增/删、行/列的函数，使进行了这些操作后会发送信号
 * 2.维护了一个QList<TableArrayItem*>，这个list中存储了多个列对象，所有对表格的操作都会对应的在list中进行操作
 * 3.写这里很痛苦
 * 4.
 */
class TableWidget:public QTableWidget
{    
    QList<TableArrayItem*>items;

public:
    /**
     * @brief TableWidget
     * 构造函数，设置了表格第一列默认的名字，创建了第二行的comboBox，连接了对应的信号(comboBox
     * @param row
     * @param column
     * @param parent
     */
    TableWidget(int row,int column,QWidget*parent=nullptr);
    /**
     * @brief appendArrayItem
     * 在list的末尾添加一列
     * @param item
     */
    void appendArrayItem(TableArrayItem* item);
    /**
     * @brief addArrayItem
     * 在list的某个位置添加一列
     * @param item
     * @param column
     */
    void addArrayItem(TableArrayItem* item,int column);
    /**
     * @brief insertColumn
     * 重写的插入列函数，新的列会加入list，同时，会使得MainWidget发送一个创建列的信号(来自上层的调用)
     * @param column
     * @return
     */
    TableArrayItem* insertColumn(int column);
    /**
     * @brief insertRow
     * 重写的插入列，使得这个表格下每一列都会添加一行(发信号，数据改变)
     * @param row
     */
    void insertRow(int row);
    /**
     * @brief removeColumn
     * @param column
     */
    void removeColumn(int column);
    /**
     * @brief removeRow
     * @param row
     */
    void removeRow(int row);
    /**
     * @brief checkChangeType
     * 点击保存按钮时触发
     * 将所有列的数据按当前的数据类型进行改变
     */
    void checkChangeType();
    /**
     * @brief getItems
     * 获取list的引用
     * @return
     */
    QList<TableArrayItem*>& getItems();
private:
    QComboBox* createComboBox();
    void showList();
public slots:
    /**
     * @brief onCellChanged
     * 当某一个数据发生改变时调用
     * 如果这一个在列的类中还不存在，则延长列的数据长度
     * 并更新数据
     * 如果行数为0或1则不会发生改变
     * @param rows
     * @param columns
     */
    void onCellChanged(int rows,int columns);
    void onTypeChanged(int type);
    void onAddRow(int rows);
    TableArrayItem* onAddColumn(int Column);
    void onDeleteRow(int rows);
    void onDeleteColumn(int Column);

};

#endif // TABLEWIDGET_H
