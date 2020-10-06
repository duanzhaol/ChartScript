#ifndef INITAREAINTERPRETER_H
#define INITAREAINTERPRETER_H

#include "../../DataModel/AbstractNode.h"
#include <QPair>


class InitAreaInterpreter
{
	InitAreaInterpreter();
public:
	static QPair< QHash<CodeText,AbstractNode*>,QList<AbstractNode*>> interpreter(CodeText&code);
};

#endif // INITAREAINTERPRETER_H
