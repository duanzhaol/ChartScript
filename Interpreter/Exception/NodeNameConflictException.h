#ifndef NODENAMECONFLICTEXCEPTION_H
#define NODENAMECONFLICTEXCEPTION_H

#include "../Exception/InterpreterErrorException.h"
#include "../DataModel/AbstractNode.h"

/**
 * @exception NodeNameConflictException
 * @brief 变量名重定义错误
 */

class NodeNameConflictException:public InterpreterErrorException
{
	const NodeName name;
public:
	NodeNameConflictException(const NodeName name);

	// InterpreterException interface
public:
	virtual QString getWhy() const override;
};

#endif // NODENAMECONFLICTEXCEPTION_H
