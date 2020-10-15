#ifndef CODEMODELINGINTERPRETER_H
#define CODEMODELINGINTERPRETER_H

#include "../../DataModel/AbstractNode.h"
#include "InitAreaInterpreter.h"
#include "ConnectionAreaInterpreter.h"
#include "../../NodeShow/GraphicsNode/GraphicsNode/AbstractGraphicsNode.h"

struct CodeModelingResult{
	//! get all Data model nodes
	QList<AbstractNode*> allNodes;
	//! get a related Interpreter controller @see InterpreterController
	InterpreterController*controller;
	//! get connections of nodes.
	QHash<AbstractNode*,QList<AbstractNode*>> relationships;
};

class CodeModelingInterpreter
{
	CodeModelingInterpreter();
public:
	static CodeModelingResult interprete(CodeText&code);
};

#endif // CODEMODELINGINTERPRETER_H
