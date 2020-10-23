#ifndef NODELISTWIDGETITEM_H
#define NODELISTWIDGETITEM_H

#include "NodeListWidget.h"

#include <QListWidgetItem>

/**
 * @brief NodeListWIdgetItem里的每一项，对应一个类型的图节点
 * @see NodeListWidget
 */

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
