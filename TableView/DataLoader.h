#ifndef DATALOADER_H
#define DATALOADER_H
#include <QFileDialog>
#include <QAxObject>
#include<QTableWidget>
#include "TableModel/TableWidget.h"
class DataLoader
{
public:
    DataLoader(int type,TableWidget* table);
private:
    void excelReader(TableWidget* table);
    void csvReader(TableWidget* table);
};

#endif // DATALOADER_H
