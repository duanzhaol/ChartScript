#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QListWidget>
#include"DataLoader.h"
#include<QDebug>
#include<QTableWidgetItem>
#include<QTableWidget>
#include"TableModel/TableWidget.h"

namespace Ui {
class MainWidget;
}
/**
 * @brief
 * 表格界面的主窗口类
 * 会发送创建新列的信号
 */
class MainWidget : public QWidget
{
    Q_OBJECT

    static MainWidget*instance;

    MainWidget(QWidget*parent=nullptr);

    ~MainWidget();

public:

    static MainWidget*getInstance();
    static void createWidget();

private:
    Ui::MainWidget *ui;
    //void setTable(int,int,QString);


private slots:
    //void ListItemClicked(QListWidgetItem*);



    void on_addColumn_clicked();

    void on_addRow_clicked();

    void on_deleteColumn_clicked();

    void on_deleteRow_clicked();

    void on_exportData_clicked();



    void on_setting_clicked();

    void on_importCsv_clicked();

    void on_importExcel_clicked();

    void on_addNewTable_clicked();

    TableWidget *getTableNow();

signals:
    void newArray(TableArrayInterface*item);
};

#endif // MAINWIDGET_H
