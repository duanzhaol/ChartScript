#ifndef DATATYPEINTERPRETER_H
#define DATATYPEINTERPRETER_H

#include "../../DataModel/AbstractNode.h"
#include <QVariant>

class DataTypeInterpreter
{
	DataTypeInterpreter();
public:
	static QVariant::Type interprete(CodeText&code);
};

#endif // DATATYPEINTERPRETER_H
