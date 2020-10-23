#ifndef INITAREAINTERPRETER_H
#define INITAREAINTERPRETER_H

#include "../../DataModel/AbstractNode.h"
#include <QPair>

/**
 * @brief
 * 初始化区域解释器，解释数据的整个初始化区域。
 * @see InitCodeLineInterpreter
 */
class InitAreaInterpreter
{
	InitAreaInterpreter();
public:
	static QPair< QHash<CodeText,AbstractNode*>,QList<AbstractNode*>> interpreter(CodeText&code);
};

#endif // INITAREAINTERPRETER_H
