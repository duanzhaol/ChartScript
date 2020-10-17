﻿#ifndef SPACECLOSUREINTERPRETER_H
#define SPACECLOSUREINTERPRETER_H

#include "../../DataModel/AbstractDataNode.h"

/**
 * @brief The SpaceClosureInterpreter class
 */

class ClosureInterpreter
{
	ClosureInterpreter() = default;
public:
	static int interprete(CodeText&code,const QChar&closureChar = ' ');
	static int interprete(CodeText&code,const QChar&closureChar1,const QChar &closureChar2);
};

#endif // SPACECLOSUREINTERPRETER_H