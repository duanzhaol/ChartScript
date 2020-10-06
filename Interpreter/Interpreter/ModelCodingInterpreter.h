#ifndef MODELCODINGINTERPRETER_H
#define MODELCODINGINTERPRETER_H

#include "InterpreterController.h"
#include <QSet>

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
