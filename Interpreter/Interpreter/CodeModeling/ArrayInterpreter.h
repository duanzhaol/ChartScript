#ifndef ARRAYINTERPRETER_H
#define ARRAYINTERPRETER_H

#include "../../DataModel/AbstractDataNode.h"

class ArrayInterpreter
{
	ArrayInterpreter();
public:
	static QVariant interprete(CodeText&code,const QVariant::Type elementType);
};

#endif // ARRAYINTERPRETER_H
