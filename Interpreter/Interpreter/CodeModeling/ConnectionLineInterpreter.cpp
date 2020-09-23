#include "ConnectionLineInterpreter.h"
#include "ModelNameInterpreter.h"
#include "ClosureInterpreter.h"

ConnectionLineInterpreter::ConnectionLineInterpreter()
{

}



QPair<AbstractNode *, AbstractNode *> ConnectionLineInterpreter::interprete(
		CodeText &code,
		QHash<CodeText, AbstractNode *>&nodes,
		StartNode*startNode)
{
	QPair<AbstractNode *,AbstractNode *> connection;

	ClosureInterpreter::interprete(code,' ','\n');

	if(code.startsWith("[*]")){
		code.remove(0,3);
		connection.first = startNode;
	}
	else{
		connection.first = *nodes.find(ModelNameInterpreter::interprete(code));
	}

	ClosureInterpreter::interprete(code);

	if(!code.startsWith("->")){
		throw InterpreterErrorException("invalid connection. need \"->\" between two data model");
	}

	code.remove(0,2);

	ClosureInterpreter::interprete(code);

	connection.second = *nodes.find(ModelNameInterpreter::interprete(code));
	ClosureInterpreter::interprete(code);

	return connection;
}
