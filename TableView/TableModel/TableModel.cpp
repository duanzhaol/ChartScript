#include "TableModel.h"


TableModel::TableModel(QWidget *parent):
	QStandardItemModel (parent)
{

}

void TableModel::appendArrayModel(TableArrayModel *arrayModel)
{
	this->appendRow(arrayModel->getItems());
}

