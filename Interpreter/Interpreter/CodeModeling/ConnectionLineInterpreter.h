#ifndef CONNECTIONLINEINTERPRETER_H
#define CONNECTIONLINEINTERPRETER_H

#include "../../DataModel/AbstractNode.h"
#include "../../DataModel/StartNode.h"
#include <QPair>

/**
 * @brief
 * 单行连接解释器，解释单行连接代码
 */

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
