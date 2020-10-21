#ifndef TABLEARRAYITEM_H
#define TABLEARRAYITEM_H
#include"../GraphicsShowInterface/TableArrayInterface.h"

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

    void onTypeChanged();
    void onNameChanged();
    void onDataChanged();
    void onArrayDelete();
private:
    QVariantList data;

};

#endif // TABLEARRAYITEM_H
