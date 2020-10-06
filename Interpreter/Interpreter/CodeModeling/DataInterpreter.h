#ifndef DATAINTERPRETER_H
#define DATAINTERPRETER_H

#include "../../DataModel/AbstractNode.h"
#include <QVariant>

class DataInterpreter
{
	DataInterpreter();
	static int intInterprete(CodeText&code);
	static double doubleInterprete(CodeText&);
	static QString stringInterprete(CodeText&code);
public:
	static QVariant interprete(CodeText&code,const QVariant::Type dataType);
};

#endif // DATAINTERPRETER_H
