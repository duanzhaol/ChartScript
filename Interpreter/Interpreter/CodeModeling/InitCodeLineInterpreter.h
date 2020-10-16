#ifndef CODELINEINTERPRETER_H
#define CODELINEINTERPRETER_H

#include "../../DataModel/AbstractNode.h"
#include "NodeShow/GraphicsNode/GraphicsNode/AbstractGraphicsNode.h"

class InitCodeLineInterpreter
{
	InitCodeLineInterpreter();
public:
	static AbstractNode*interprete(CodeText&code);
};

#endif // CODELINEINTERPRETER_H
