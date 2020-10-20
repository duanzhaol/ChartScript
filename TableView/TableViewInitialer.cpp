#include "TableViewInitialer.h"
#include "MainWidget.h"

TableViewInitialer::TableViewInitialer()
{

}

TableViewInitialer *TableViewInitialer::getInstance()
{
    return instance;
}


void TableViewInitialer::init()
{
    MainWidget::createWidget();
    widget = MainWidget::getInstance();
}

QString TableViewInitialer::getWindowName() const
{
    return QStringLiteral("Table");
}

TableViewInitialer* TableViewInitialer::instance = new TableViewInitialer;
