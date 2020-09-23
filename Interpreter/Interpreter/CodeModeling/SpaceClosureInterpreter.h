#ifndef SPACECLOSUREINTERPRETER_H
#define SPACECLOSUREINTERPRETER_H

#include "../../DataModel/AbstractDataNode.h"

/**
 * @brief The SpaceClosureInterpreter class
 */

class SpaceClosureInterpreter
{
	SpaceClosureInterpreter() = default;
public:
	static int interprete(CodeText&code);
};

#endif // SPACECLOSUREINTERPRETER_H
