#ifndef MODELCODINGINTERPRETER_H
#define MODELCODINGINTERPRETER_H

#include "InterpreterController.h"
#include <QSet>

/**
 * @brief
 * 图节点编程代码化的编译器。
 * 该编译其组织所有ModelCodingInterface生成文本代码
 * @see ModelCodingInterface
 */

class ModelCodingInterpreter
{
	InterpreterController*controller;
	QSet<AbstractNode*> nodes;
	void initNodes(AbstractNode*start);
public:
	ModelCodingInterpreter(InterpreterController*controller);
	CodeText coding()const;
};

#endif // MODELCODINGINTERPRETER_H
