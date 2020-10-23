#ifndef DATAINTERPRETER_H
#define DATAINTERPRETER_H

#include "../../DataModel/AbstractNode.h"
#include <QVariant>

/**
 * @brief
 * 数据对象解释器。
 * 组合数据类型、名称、内容解释器
 */

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
