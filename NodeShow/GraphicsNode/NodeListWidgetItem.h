#ifndef NODELISTWIDGETITEM_H
#define NODELISTWIDGETITEM_H

#include "NodeListWidget.h"

#include <QListWidgetItem>



class NodeListWidgetItem:public QListWidgetItem
{
public:
    NodeListWidgetItem(NodeListWidget* listview);
    int getItemIndex();
    void setItemIndex(int index);

private:
    int ItemIndex=-1;
};

#endif // NODELISTWIDGETITEM_H
