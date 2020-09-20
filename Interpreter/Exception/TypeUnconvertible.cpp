#include "TypeUnconvertible.h"
#include <QString>

TypeUnconvertible::TypeUnconvertible(
		const QVariant::Type outputNodeType,
		const QVariant::Type inputNodeType):
	outputNodeType(outputNodeType),
	inputNodeType(inputNodeType)

{

}


const char *TypeUnconvertible::what() const
{
	return  QString("can not cast from %1 to %2!")
			.arg(QVariant::typeToName(outputNodeType))
			.arg(QVariant::typeToName(inputNodeType))
			.toUtf8().data();
}
