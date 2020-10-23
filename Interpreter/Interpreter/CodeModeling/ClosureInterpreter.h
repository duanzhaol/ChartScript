#ifndef SPACECLOSUREINTERPRETER_H
#define SPACECLOSUREINTERPRETER_H

#include "../../DataModel/AbstractDataNode.h"

/**
 * @brief
 * 空白字符闭包解释器，解释代码间的空白字符
 */

class ClosureInterpreter
{
	ClosureInterpreter() = default;
public:
	static int interprete(CodeText&code,const QChar&closureChar = ' ');
	static int interprete(CodeText&code,const QChar&closureChar1,const QChar &closureChar2);
};

#endif // SPACECLOSUREINTERPRETER_H
