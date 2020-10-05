#ifndef LISTWIDGETITEM_H
#define LISTWIDGETITEM_H
#include<QListWidgetItem>

class ListWidgetItem : public QListWidgetItem
{
public:
    explicit ListWidgetItem(QListWidget *view = nullptr);

};

#endif // LISTWIDGETITEM_H
