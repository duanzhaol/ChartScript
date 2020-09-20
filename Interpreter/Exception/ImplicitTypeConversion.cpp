#include "ImplicitTypeConversion.h"

ImplicitTypeConversion::ImplicitTypeConversion(
		const QVariant::Type outputNodeType,
		const QVariant::Type inputNodeType):
	outputNodeType(outputNodeType),
	inputNodeType(inputNodeType)

{

}

QString ImplicitTypeConversion::getWhy() const
{
	return QString("implicit cast from %1 to %2!")
			.arg(QVariant::typeToName(outputNodeType))
			.arg(QVariant::typeToName(inputNodeType));

}


