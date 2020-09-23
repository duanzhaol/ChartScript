#ifndef CODELINEINTERPRETER_H
#define CODELINEINTERPRETER_H

#include "../../DataModel/AbstractNode.h"

class InitCodeLineInterpreter
{
	InitCodeLineInterpreter();
public:
	AbstractNode*interprete(CodeText&code);
};

#endif // CODELINEINTERPRETER_H
