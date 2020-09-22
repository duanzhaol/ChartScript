#include "NodeNameConflictException.h"





NodeNameConflictException::NodeNameConflictException(const NodeName name):
	name(name)
{

}

QString NodeNameConflictException::getWhy() const
{
	return QString(R"(Node name: "%1" has been used!)")
			.arg(name);
}
