#include "TableViewInitialer.h"
#include "TableView.h"

TableViewInitialer::TableViewInitialer()
{

}

TableViewInitialer *TableViewInitialer::getInstance()
{
    return instance;
}


void TableViewInitialer::init()
{
    TableView::createWidget();
    widget = TableView::getInstance();
}

QString TableViewInitialer::getWindowName() const
{
    return QStringLiteral("Table");
}

TableViewInitialer* TableViewInitialer::instance = new TableViewInitialer;
