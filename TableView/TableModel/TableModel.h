#ifndef TABLEARRAYVIEW_H
#define TABLEARRAYVIEW_H

#include <QTableView>
#include "TableArrayModel.h"

class TableModel:protected QStandardItemModel
{
public:
	TableModel(QWidget*parent = nullptr);
	void appendArrayModel(TableArrayModel* arrayModel);
};

#endif // TABLEARRAYVIEW_H
