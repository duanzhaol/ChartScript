#ifndef TABLEARRAYITEM_H
#define TABLEARRAYITEM_H
#include"../GraphicsShowInterface/TableArrayInterface.h"
/**
 * @brief The TableArrayItem class
 * 对TableArrayInterface接口的实现
 * 维护了一个QVariantList
 * 这个list中存储了一列的全部数据，从第一行到第N行
 *
 */
class TableArrayItem:public TableArrayInterface
{
   //QList<QTableWidgetItem*> items; 
    Q_OBJECT
public:
    TableArrayItem();
    // TableArrayInterface interface
    QVariantList getArrayData();
    QVariantList &getData();
    QString getArrayName();
    QVariant::Type getArrayType();
    void setArrayType(const QVariant::Type newType);
    void setArrayName(const QString &newArrayName);
    void setArrayData(const QVariantList &newData);

    /**
     * @brief onTypeChanged
     * 发类型改变的信号
     */
    void onTypeChanged();
    /**
     * @brief onNameChanged
     * 发名字改变的信号
     */
    void onNameChanged();
    /**
     * @brief onDataChanged
     * 发数据改变的信号
     */
    void onDataChanged();
    /**
     * @brief onArrayDelete
     * 发当前列被删除的信号
     */
    void onArrayDelete();
private:
    /**
     * @brief data
     * 存储的数据
     */
    QVariantList data;

};

#endif // TABLEARRAYITEM_H
