#ifndef CONNECTIONLINEINTERPRETER_H
#define CONNECTIONLINEINTERPRETER_H

#include "../../DataModel/AbstractNode.h"
#include "../../DataModel/StartNode.h"
#include <QPair>

class ConnectionLineInterpreter
{
	ConnectionLineInterpreter();
public:
	static QPair<AbstractNode*,AbstractNode*> interprete(
			CodeText&code,
			QHash<CodeText, AbstractNode *>&nodes,
			StartNode*startNode);
};

#endif // CONNECTIONLINEINTERPRETER_H
