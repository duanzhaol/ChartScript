#ifndef CODEMODELINGINTERPRETER_H
#define CODEMODELINGINTERPRETER_H

#include "../../DataModel/AbstractNode.h"
#include "InitAreaInterpreter.h"
#include "ConnectionAreaInterpreter.h"

struct CodeModelingResult{
	QList<AbstractNode*> allNodes;
	InterpreterController*controller;
};

class CodeModelingInterpreter
{
	CodeModelingInterpreter();
public:
	static CodeModelingResult interprete(CodeText&code);
};

#endif // CODEMODELINGINTERPRETER_H
