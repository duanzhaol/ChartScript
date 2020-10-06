#ifndef INTERPRETEREXCEPTION_H
#define INTERPRETEREXCEPTION_H

#include <exception>
#include <QString>

/**
 * @brief the base class of all interpreter related exception
 * @note call function what to get exception imformation
 */

class InterpreterException:public std::exception
{
	QString message;
public:
	InterpreterException();
	InterpreterException(QString message);

	/** return the reson of  current exception*/
	virtual QString getWhy()const;

	// exception interface
private:
	virtual const char *what() const override;
};

#endif // INTERPRETEREXCEPTION_H
