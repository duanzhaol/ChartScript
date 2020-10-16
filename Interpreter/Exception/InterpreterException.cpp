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

const char *InterpreterException::what() const noexcept
{
	return std::exception::what();
}
