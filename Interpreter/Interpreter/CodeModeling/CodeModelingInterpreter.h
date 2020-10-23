#ifndef CODEMODELINGINTERPRETER_H
#define CODEMODELINGINTERPRETER_H

#include "../../DataModel/AbstractNode.h"
#include "InitAreaInterpreter.h"
#include "ConnectionAreaInterpreter.h"
#include "../../NodeShow/GraphicsNode/GraphicsNode/AbstractGraphicsNode.h"

/**
 * @brief
 * 文本代码图节点化的结果
 * @see CodeModelingInterpreter
 */

struct CodeModelingResult{
	//! get all Data model nodes
	QList<AbstractNode*> allNodes;
	//! get a related Interpreter controller @see InterpreterController
	InterpreterController*controller;
	//! get connections of nodes.
	QHash<AbstractNode*,QList<AbstractNode*>> relationships;
};

/**
 * @brief
 * 文本代码图节点化解释器。
 * 可以将文本代码转为图节点编程
 * @see CodeModelingResult
 */

class CodeModelingInterpreter
{
	CodeModelingInterpreter();
public:
	static CodeModelingResult interprete(CodeText&code);
};

#endif // CODEMODELINGINTERPRETER_H
