#ifndef CONNECTIONAREAINTERPRETER_H
#define CONNECTIONAREAINTERPRETER_H

#include "../../DataModel/AbstractNode.h"
#include "../InterpreterController.h"
#include <QPair>

class ConnectionAreaInterpreter
{
	ConnectionAreaInterpreter();
public:
	static InterpreterController* interprete(CodeText&code,QHash<CodeText, AbstractNode *>&nodes);
};

#endif // CONNECTIONAREAINTERPRETER_H
