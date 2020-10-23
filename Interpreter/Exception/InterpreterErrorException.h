#ifndef INTERPRETERERROREXCEPTION_H
#define INTERPRETERERROREXCEPTION_H

#include "InterpreterException.h"

/**
 * @exception InterpreterErrorException
 * @brief
 * 编译错误的父类
 */

class InterpreterErrorException:public InterpreterException{
public:
	InterpreterErrorException()=default;
	InterpreterErrorException(const QString&message);
};



#endif // INTERPRETERERROREXCEPTION_H




