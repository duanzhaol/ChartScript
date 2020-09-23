#ifndef MODELNAMEINTERPRETER_H
#define MODELNAMEINTERPRETER_H

#include "../../DataModel/AbstractNode.h"

class ModelNameInterpreter
{
	ModelNameInterpreter();
public:
	static CodeText interprete(CodeText&code);
};

#endif // MODELNAMEINTERPRETER_H
