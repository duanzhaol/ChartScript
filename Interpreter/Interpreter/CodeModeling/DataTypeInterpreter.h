#ifndef DATATYPEINTERPRETER_H
#define DATATYPEINTERPRETER_H

#include "../../DataModel/AbstractNode.h"
#include <QVariant>

/**
 * @brief
 * 数据类型解释器，用于解释数据类型
 */

class DataTypeInterpreter
{
	DataTypeInterpreter();
public:
	static QVariant::Type interprete(CodeText&code);
};

#endif // DATATYPEINTERPRETER_H
