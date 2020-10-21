#include "DataLoader.h"
#include<QDebug>
DataLoader::DataLoader(int type,TableWidget* table)
{
    if(type==0){
        csvReader(table);
    }else if(type==1){
        excelReader(table);
    }else{
        qDebug()<<"error in dataloader";
    }
}

void DataLoader::excelReader(TableWidget* table)
{
    QString path = QFileDialog::getOpenFileName(nullptr,"open",
                                                "../","execl(*.xlsx)");
    //指定父对象（this），“open”具体操作，打开，“../”默认，之后可以添加要打开文件的格式
    if(path.isEmpty()==false)
    {
        //文件对象
        QFile file(path);
        //打开文件,默认为utf8变量，
        bool flag = file.open(QIODevice::ReadOnly);
        if(flag == true)//打开成功
        {
            QAxObject *excel = new QAxObject();//建立excel操作对象
            excel->setControl("Excel.Application");//连接Excel控件
            excel->setProperty("Visible", false);//不显示窗体看效果
            excel->setProperty("DisplayAlerts", false);//不显示警告看效果
            /*********获取COM文件的一种方式************/
            QAxObject *workbooks = excel->querySubObject("WorkBooks");
            //获取工作簿(excel文件)集合
            qDebug()<<0;
            workbooks->dynamicCall("Open(const QString&)", path);//path至关重要，获取excel文件的路径
            //打开一个excel文件
            qDebug()<<1;
            QAxObject *workbook = excel->querySubObject("ActiveWorkBook");
            QAxObject *worksheet = workbook->querySubObject("WorkSheets(int)",1);//访问excel中的工作表中第一个单元格
            QAxObject *usedRange = worksheet->querySubObject("UsedRange");//sheet的范围
            /*********获取COM文件的一种方式************/
            //获取打开excel的起始行数和列数和总共的行数和列数
            int intRowStart = usedRange->property("Row").toInt();//起始行数
            int intColStart = usedRange->property("Column").toInt(); //起始列数
            QAxObject *rows, *columns;
            rows = usedRange->querySubObject("Rows");//行
            columns = usedRange->querySubObject("Columns");//列
            qDebug()<<2;
            int intRow = rows->property("Count").toInt();//行数
            int intCol = columns->property("Count").toInt();//列数
//            //起始行列号
//            qDebug()<<intRowStart;
//            qDebug()<<intColStart;
//            //行数和列数
//            qDebug()<<intRow;
//            qDebug()<<intCol;
            int a,b;
            a=intRow-intRowStart+1,b=intCol-intColStart+1;
           // QString text[a][b];
            QString **text = new QString*[a];
            for(int index = 0;index<a;++index){
                text[index] = new QString[b];
            }
            int coerow=0,coecol=0;
            qDebug()<<3;
            for (int i = intRowStart; i < intRowStart + intRow; i++,coerow++)
            {
                coecol=0;//务必是要恢复初值的
                for (int j = intColStart; j < intColStart + intCol; j++,coecol++)
                {
                    QAxObject *cell = excel->querySubObject("Cells(Int, Int)", i, j );
                    QVariant cellValue = cell->dynamicCall("value");

                    text[coerow][coecol]=cellValue.toString();//QVariant转换为QByteArray

                    //qDebug()<<coerow<<" "<<coecol<<" "<<text[coerow][coecol];
                    //QString exceldata[coerow][coecol]=QString(text[coerow][coecol]);//QByteArray转换为QString
                }
            }
            qDebug()<<4;
            workbook->dynamicCall( "Close(Boolean)", false );
            excel->dynamicCall( "Quit(void)" );
            delete excel;
            //QMessageBox::warning(this,tr("读取情况"),tr("读取完成！"),QMessageBox::Yes);

            table->setRowCount(a+2);
            int nowColumn=table->columnCount();
            qDebug()<<5;
            while(nowColumn<b)
            {
                table->insertColumn(nowColumn);
                nowColumn++;
            }
            for(int i=0;i<a;i++){
                for(int j=0;j<b;j++){
                    table->setItem(i+2,j,new QTableWidgetItem(text[i][j]));
                }
            }
        }
        file.close();
    }

}

void DataLoader::csvReader(TableWidget* table)
{

}
