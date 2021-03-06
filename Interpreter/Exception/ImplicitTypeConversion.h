#ifndef IMPLICITTYPECONVERSION_H
#define IMPLICITTYPECONVERSION_H

#include "InterpreterWarnningException.h"
#include <QVariant>
/**
 * @exception ImplicitTypeConversion
 * @brief 隐式类型转换警告
 */
class ImplicitTypeConversion:public InterpreterWarnningException
{
	QVariant::Type outputNodeType,inputNodeType;

public:
	ImplicitTypeConversion(const QVariant::Type outputNodeType,const QVariant::Type inputNodeType);


	// InterpreterException interface
public:
	virtual QString getWhy() const override;
};

#endif // IMPLICITTYPECONVERSION_H
