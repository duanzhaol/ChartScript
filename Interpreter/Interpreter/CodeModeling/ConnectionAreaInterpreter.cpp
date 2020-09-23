#include "ConnectionAreaInterpreter.h"
#include "InitCodeLineInterpreter.h"
#include "ClosureInterpreter.h"
#include "ConnectionLineInterpreter.h"

#include "../../NodeShow/GraphicsNode/GraphicsStartNode.h"

ConnectionAreaInterpreter::ConnectionAreaInterpreter()
{

}

InterpreterController *ConnectionAreaInterpreter::interprete(
		CodeText &code,
		QHash<CodeText, AbstractNode *>&nodes)
{
	ClosureInterpreter::interprete(code,' ','\n');

	if(!code.startsWith("Connection:{\n")){
		throw InterpreterErrorException("invalid Connection Area Declaration!");
	}

	code.remove(0,13);

	StartNode*startNode = new GraphicsStartNode;

	InterpreterController*controller = new InterpreterController(startNode);

	while(code.front() != '}'){
		ClosureInterpreter::interprete(code,' ','\n');
		auto  connection = ConnectionLineInterpreter::interprete(code,nodes,startNode);
		controller->addConnect(connection.first,connection.second);
	}

	return controller;

}
