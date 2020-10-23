#ifndef CODELINEINTERPRETER_H
#define CODELINEINTERPRETER_H

#include "../../DataModel/AbstractNode.h"
#include "NodeShow/GraphicsNode/GraphicsNode/AbstractGraphicsNode.h"


/**
 * @brief 初始化区域单行代码解释器
 */
class InitCodeLineInterpreter
{
	InitCodeLineInterpreter();
public:
	static AbstractNode*interprete(CodeText&code);
};

#endif // CODELINEINTERPRETER_H
