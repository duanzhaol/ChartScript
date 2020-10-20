#ifndef TABLEVIEWINITIALER_H
#define TABLEVIEWINITIALER_H
#include "../InitInterface/AbstractInitializer.h"


class TableViewInitialer:public AbstractInitializer
{
    static TableViewInitialer*instance;
public:
    TableViewInitialer();

    static TableViewInitialer*getInstance();

    // AbstractInitializer interface
public:
    virtual void init() override;
    virtual QString getWindowName() const override;
};

#endif // TABLEVIEWINITIALER_H
