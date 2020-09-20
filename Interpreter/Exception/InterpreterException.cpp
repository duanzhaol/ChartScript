#include "InterpreterException.h"

InterpreterException::InterpreterException()
{

}

const char *InterpreterException::what() const
{
	return std::exception::what();
}
