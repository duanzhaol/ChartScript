#ifndef ARRAYINTERPRETER_H
#define ARRAYINTERPRETER_H

#include "../../DataModel/AbstractDataNode.h"

/**
 * @brief
 * 数组解释器，解释数组代码对象
 */

class ArrayInterpreter
{
	ArrayInterpreter();
public:
	static QVariant interprete(CodeText&code,const QVariant::Type elementType);
};

#endif // ARRAYINTERPRETER_H
