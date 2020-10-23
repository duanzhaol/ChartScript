#ifndef MODELTYPEINTERPRETER_H
#define MODELTYPEINTERPRETER_H

#include "../../DataModel/AbstractNode.h"
#include "../InterpreterController.h"

/**
 * @brief
 * 模块类型解释器，用于解释模块的类型。
 * @see ModelType
 */
class ModelTypeInterpreter
{
	ModelTypeInterpreter();
public:

	static ModelType interprete(CodeText&code);
};

#endif // MODELTYPEINTERPRETER_H
