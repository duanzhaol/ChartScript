#include "TableArrayItem.h"

#include <QTableWidgetItem>
#include<QDebug>
#pragma execution_character_set("utf-8")
TableArrayItem::TableArrayItem()
{
    data.append(QStringLiteral("请命名"));
    data.append("string");
    data.append("0");
}
/**
 * @brief TableArrayItem::getArrayData
 * 返回自data中第二个元素之后的内容(去除了name和type)
 * todo：实时更新
 * @return
 */
QVariantList TableArrayItem::getArrayData()
{
    return data.mid(2);
}

QVariantList& TableArrayItem::getData()
{
    return data;
}
/**
 * @brief TableArrayItem::getArrayName
 *
 * @return
 */
QString TableArrayItem::getArrayName()
{
    return data.first().toString();
}

QVariant::Type TableArrayItem::getArrayType()
{
    QString type=data.at(1).toString();
    if(type=="string"){
        return QVariant::String;
    }else if(type=="int"){
        return QVariant::Int;
    }else if(type=="double"){
        return QVariant::Double;
    }else if(type=="long long"){
        return QVariant::LongLong;
    }
}

void TableArrayItem::setArrayType(const QVariant::Type newType)
{
    //newData.at(1)
    if(newType==QVariant::String){
        data.replace(1,"string");
    }else if(newType==QVariant::Int){
        data.replace(1,"int");
    }else if(newType==QVariant::Double){
        data.replace(1,"double");
    }else if(newType==QVariant::LongLong){
        data.replace(1,"long long");
    }
}

void TableArrayItem::setArrayName(const QString &newArrayName)
{
    data.replace(0,newArrayName);
}

void TableArrayItem::setArrayData(const QVariantList &newData)
{
    //考虑newData长度超出原本表格的大小??
    for(int i=2;i<data.length();i++){
        data.replace(i,newData.at(i-2));
    }

}

void TableArrayItem::onTypeChanged()
{
    emit arrayTypeChanged();
    qDebug()<<"typeChange";
}

void TableArrayItem::onNameChanged()
{
    emit arrayNameChanged();
    qDebug()<<"NameChange";

}

void TableArrayItem::onDataChanged()
{
    emit arrayDataChanged();
    qDebug()<<"DataChange";

}


void TableArrayItem::onArrayDelete()
{
    emit arrayDelete();
    qDebug()<<"DeleteChange";

}
