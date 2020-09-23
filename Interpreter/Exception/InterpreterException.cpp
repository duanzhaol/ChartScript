#include "InterpreterException.h"

InterpreterException::InterpreterException()
{

}

InterpreterException::InterpreterException(QString message):
	message(message)
{

}

QString InterpreterException::getWhy() const
{
	return message;
}

const char *InterpreterException::what() const
{
	return std::exception::what();
}
