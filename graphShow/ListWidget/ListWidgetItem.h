#ifndef LISTWIDGETITEM_H
#define LISTWIDGETITEM_H
#include<QListWidgetItem>

/**
 * @brief The ListWidgetItem class
 * 是ListWidget的每一项，用于添加list的项
 */

class ListWidgetItem : public QListWidgetItem
{
public:
    explicit ListWidgetItem(QListWidget *view = nullptr);

};

#endif // LISTWIDGETITEM_H
