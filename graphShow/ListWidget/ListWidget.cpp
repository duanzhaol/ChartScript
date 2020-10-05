#include "ListWidget.h"
#include<QDebug>

ListWidget::ListWidget(QWidget *parent)
{
    setMouseTracking(true);

}

ChartItem *ListWidget::getChart(int index)
{
    qDebug()<<"当前长度:"<<chartItemList.length()<<"  "<<count();

    if(index<chartItemList.length()){
        return chartItemList[index];
    }else{
        return nullptr;
    }
}

void ListWidget::addChart(ChartItem *item)
{
    chartItemList.append(item);
}

bool ListWidget::addItemAll(ChartItem *chart, ListWidgetItem *item)
{
    if(chart!=nullptr&&item!=nullptr){
        addChart(chart);
        addItem(item);
        qDebug()<<"当前长度:"<<chartItemList.length()<<"  "<<count();
        return true;
    }else{
        return false;
    }

}

int ListWidget::getLength()
{
    return chartItemList.length();
}

bool ListWidget::removeItemAll(int index)
{
    if(index<chartItemList.length()){
        chartItemList.removeAt(index);
        takeItem(index);
    }else{
        return false;
    }
}


