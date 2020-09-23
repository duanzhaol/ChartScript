#ifndef DATAINTERPRETER_H
#define DATAINTERPRETER_H

#include "../../DataModel/AbstractNode.h"

class DataInterpreter
{
	DataInterpreter();
public:
	static int intInterprete(CodeText&code);
	static double doubleInterprete(CodeText&);
	static QString stringInterprete(CodeText&code);
};

#endif // DATAINTERPRETER_H
