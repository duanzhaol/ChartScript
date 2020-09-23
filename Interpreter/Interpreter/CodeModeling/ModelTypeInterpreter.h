#ifndef MODELTYPEINTERPRETER_H
#define MODELTYPEINTERPRETER_H

#include "../../DataModel/AbstractNode.h"
#include "../InterpreterController.h"

class ModelTypeInterpreter
{
	ModelTypeInterpreter();
public:

	static ModelType interprete(CodeText&code);
};

#endif // MODELTYPEINTERPRETER_H
