#ifndef MODELNAMEINTERPRETER_H
#define MODELNAMEINTERPRETER_H

#include "../../DataModel/AbstractNode.h"

/**
 * @brief
 * 模块名称解释器，解释模块的名称
 */

class ModelNameInterpreter
{
	ModelNameInterpreter();
public:
	static CodeText interprete(CodeText&code);
};

#endif // MODELNAMEINTERPRETER_H
