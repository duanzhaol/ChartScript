#include "ConnectionAreaInterpreter.h"
#include "InitCodeLineInterpreter.h"
#include "ClosureInterpreter.h"
#include "ConnectionLineInterpreter.h"

#include "../../NodeShow/GraphicsNode/GraphicsNode/GraphicsTopNode/GraphicsStartNode.h"
#include "../../NodeShow/ConnectLine/ConnectLineItem.h"
#include <QDebug>

ConnectionAreaInterpreter::ConnectionAreaInterpreter()
{

}

QPair<InterpreterController *, QHash<AbstractNode *, QList<AbstractNode *> > > ConnectionAreaInterpreter::interprete(
		CodeText &code,
		QHash<CodeText, AbstractNode *>&nodes)
{
	ClosureInterpreter::interprete(code,' ','\n');

	if(!code.startsWith("Connection:{\n")){
		throw InterpreterErrorException("invalid Connection Area Declaration!");
	}

	code.remove(0,13);

	StartNode*startNode = new GraphicsStartNode(new MovableProxyWidget);

	InterpreterController*controller = new InterpreterController(startNode);

	QHash<AbstractNode*,QList<AbstractNode*>> relations;

	while(code.front() != '}'){
		ClosureInterpreter::interprete(code,' ','\n');
		auto  connection = ConnectionLineInterpreter::interprete(code,nodes,startNode);
		controller->addConnect(connection.first,connection.second);
		relations[connection.first].append(connection.second);
		ClosureInterpreter::interprete(code,' ','\n');
	}

	return QPair<InterpreterController *,QHash<AbstractNode*,QList<AbstractNode*>>>{controller,relations};

}
