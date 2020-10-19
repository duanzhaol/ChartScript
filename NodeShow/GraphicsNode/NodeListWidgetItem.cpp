#include "NodeListWidgetItem.h"

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
