﻿#ifndef TABLEARRAYINTERFACE_H
#define TABLEARRAYINTERFACE_H

#include <QVariant>
#include <QTableWidget>
#include <QTableWidgetItem>

class TableArrayInterface{
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

};



#endif // TABLEARRAYINTERFACE_H
