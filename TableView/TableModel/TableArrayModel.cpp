#include "TableArrayModel.h"
#include "../../UTools/TextDataConverter.h"

TableArrayModel::TableArrayModel()
{

}

QList<QStandardItem *> TableArrayModel::getItems()
{
	return this->arrayData;
}


QVariantList TableArrayModel::getArrayData()
{
	QVariantList dataList;
	for(auto&data:this->arrayData){
		bool *ok = new bool;
		dataList<<TextDataConverter::textToVariant(data->text(),ok,this->getArrayType());
		Q_ASSERT(ok);
	}
	return dataList;
}

QString TableArrayModel::getArrayName()
{
	return this->arrayName;
}

QVariant::Type TableArrayModel::getArrayType()
{
	return this->variantType;
}

void TableArrayModel::setArrayType(const QVariant::Type newType)
{
	this->variantType = newType;
}

void TableArrayModel::setArrayName(const QString &newArrayName)
{
	this->arrayName = newArrayName;
}

void TableArrayModel::setArrayData(const QVariantList &newData)
{
	for(int index = 0;index <newData.size();++index){
		this->arrayData[index]->setText(newData[index].toString());
	}
}
