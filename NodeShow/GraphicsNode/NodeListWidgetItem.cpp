#include "NodeListWidgetItem.h"
#pragma execution_character_set("utf-8")

NodeListWidgetItem::NodeListWidgetItem(NodeListWidget* listview):QListWidgetItem(listview)
{

}

int NodeListWidgetItem::getItemIndex()
{
    return ItemIndex;
}

void NodeListWidgetItem::setItemIndex(int index)
{
    ItemIndex=index;
}


