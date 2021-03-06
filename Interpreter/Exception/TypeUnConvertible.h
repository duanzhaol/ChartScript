#ifndef CONNECTEXCEPTION_H
#define CONNECTEXCEPTION_H

#include "InterpreterErrorException.h"
#include <QVariant>

/**
 * @exception TypeUnconvertible
 * @brief
 * 类型不可转换错误
 * @example
 * if port A has data which type is int and port B has data which type is double,
 * then this exception will never be throwed.
 *
 * if port A has data which type is Array(int) and port B has data which type is int,
 * then this exception will be throwed.
 */

class TypeUnconvertible:public InterpreterErrorException
{
	QVariant::Type outputNodeType,inputNodeType;
public:
	TypeUnconvertible(const QVariant::Type outputNodeType,const QVariant::Type inputNodeType);


	// InterpreterException interface
public:
	virtual QString getWhy() const override;
};

#endif // CONNECTEXCEPTION_H
