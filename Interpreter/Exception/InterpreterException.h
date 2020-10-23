#ifndef INTERPRETEREXCEPTION_H
#define INTERPRETEREXCEPTION_H

#include <exception>
#include <QString>

/**
 * @exception InterpreterException
 * @brief 所有解释器相关异常的父类
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
    virtual const char *what() const noexcept override;
};

#endif // INTERPRETEREXCEPTION_H
