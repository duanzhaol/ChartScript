#ifndef TABLEARRAYMODEL_H
#define TABLEARRAYMODEL_H

#include <QStandardItem>
#include "../GraphicsShowInterface/TableArrayInterface.h"

class TableArrayModel:public TableArrayInterface
{
	QList<QStandardItem*> arrayData;
	QString arrayName;
	QVariant::Type variantType;
public:
	TableArrayModel();

	QList<QStandardItem*> getItems();

	// TableArrayInterface interface
public:
	virtual QVariantList getArrayData() override;
	virtual QString getArrayName() override;
	virtual QVariant::Type getArrayType() override;
	virtual void setArrayType(const QVariant::Type newType) override;
	virtual void setArrayName(const QString &newArrayName) override;
	virtual void setArrayData(const QVariantList &newData) override;
};

#endif // TABLEARRAYMODEL_H
