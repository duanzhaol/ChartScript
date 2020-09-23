#ifndef INTERPRETERERROREXCEPTION_H
#define INTERPRETERERROREXCEPTION_H

#include "InterpreterException.h"

class InterpreterErrorException:public InterpreterException{
public:
	InterpreterErrorException()=default;
	InterpreterErrorException(const QString&message);
};



#endif // INTERPRETERERROREXCEPTION_H



InterpreterErrorException::InterpreterErrorException(const QString &message):
	InterpreterException (message)
{

}
