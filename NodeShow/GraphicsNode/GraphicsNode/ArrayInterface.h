#ifndef ArrayInterface_H
#define ArrayInterface_H

#include <QString>
#include <QVariantList>



class ArrayInterface{
public:
    virtual QString getArrayName();
    virtual QVariantList *getArrayData(); //发指针给我
    virtual QVariant::Type getArrayType();
};


#endif // ArrayInterface_H
