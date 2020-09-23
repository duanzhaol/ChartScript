#include "InitAreaInterpreter.h"
#include "InitCodeLineInterpreter.h"
#include "ClosureInterpreter.h"
#include <QSet>
#include <QDebug>

InitAreaInterpreter::InitAreaInterpreter()
{

}



QPair<QHash<CodeText, AbstractNode *>, QList<AbstractNode *> > InitAreaInterpreter::interpreter(CodeText &code)
{

	ClosureInterpreter::interprete(code);

	if(!code.startsWith("Init:{\n")){
		throw InterpreterErrorException("Init Area declare error!");
	}

	code.remove(0,7);

	QHash<CodeText, AbstractNode *> nodes;

	while(code.front() != '}'){
		AbstractNode* node = InitCodeLineInterpreter::interprete(code);
		if(nodes.find(node->getNodeName())!= nodes.end()){
			throw InterpreterErrorException(QString("Model \"%1\" redefine").arg(node->getNodeName()));
		}
		nodes.insert(node->getNodeName(),node);
		ClosureInterpreter::interprete(code,'\n');
	}

	nodes.values();

	code.remove(0,1);

	return QPair<QHash<CodeText, AbstractNode *>, QList<AbstractNode *> >(nodes,nodes.values());
}
