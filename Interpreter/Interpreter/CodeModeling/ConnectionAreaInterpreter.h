#ifndef CONNECTIONAREAINTERPRETER_H
#define CONNECTIONAREAINTERPRETER_H

#include "../../DataModel/AbstractNode.h"
#include "../InterpreterController.h"
#include <QPair>
#include "../../NodeShow/GraphicsNode/GraphicsNode/AbstractGraphicsNode.h"


class ConnectionAreaInterpreter
{
	ConnectionAreaInterpreter();
public:
	static QPair<InterpreterController*,QHash<AbstractNode*,QList<AbstractNode*>> > interprete(CodeText&code,
											 QHash<CodeText, AbstractNode *>&nodes);
};

#endif // CONNECTIONAREAINTERPRETER_H
