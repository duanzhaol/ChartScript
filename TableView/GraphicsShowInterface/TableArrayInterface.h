#ifndef TABLEARRAYINTERFACE_H
#define TABLEARRAYINTERFACE_H
#include <QVariant>

class TableArrayInterface:public QObject{
    Q_OBJECT
public:
    //! All QVariant type should be same as getArrayType()
    virtual QVariantList getArrayData() = 0;
    //! getArrayName
    virtual QString getArrayName() = 0;
    //! getArrayType
    virtual QVariant::Type getArrayType() = 0;
    virtual void setArrayType(const QVariant::Type newType) = 0;
    virtual void setArrayName(const QString &newArrayName) = 0;
    virtual void setArrayData(const QVariantList&newData) = 0;
signals:
    void arrayTypeChanged();
    void arrayNameChanged();
    void arrayDataChanged();
    void arrayDelete();
};

#endif // TABLEARRAYINTERFACE_H


