#ifndef DATALOADER_H
#define DATALOADER_H
#include <QFileDialog>
#include <QAxObject>
#include<QTableWidget>
#include "TableModel/TableWidget.h"
/**
 * @brief The DataLoader class
 * 导入csv和excel，现在存在一些bug，应该是创建行列的地方出了问题
 */
class DataLoader
{
public:
    DataLoader(int type,TableWidget* table);
private:
    void excelReader(TableWidget* table);
    void csvReader(TableWidget* table);
};

#endif // DATALOADER_H
