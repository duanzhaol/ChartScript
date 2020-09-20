#ifndef INTERPRETEREXCEPTION_H
#define INTERPRETEREXCEPTION_H

#include <exception>

/**
 * @brief the base class of all interpreter related exception
 * @note call function what to get exception imformation
 */

class InterpreterException:public std::exception
{
public:
	InterpreterException();
};

#endif // INTERPRETEREXCEPTION_H
