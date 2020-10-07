#ifndef TABLEARRAYINTERFACE_H
#define TABLEARRAYINTERFACE_H

#include <QVariant>

class TableArrayInterface{
public:
	virtual QVariantList getArrayData() = 0;
	virtual QString getArrayName() = 0;
	virtual QVariant::Type getArrayType() = 0;
	virtual void setArrayType(const QVariant::Type newType) = 0;
	virtual void setArrayName(const QString &newArrayName) = 0;
	virtual void setArrayData(const QVariantList&newData) = 0;
};

#endif // TABLEARRAYINTERFACE_H
