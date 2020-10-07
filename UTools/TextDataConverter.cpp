#include "TextDataConverter.h"

TextDataConverter::TextDataConverter()
{

}

QVariant TextDataConverter::textToVariant(const QString &text, bool *ok, const QVariant::Type type)
{
#define REGISTER_TYPE(TYPE) \
	case QVariant::Type::TYPE:return QVariant(text.to##TYPE(ok))

	QVariant v(type);
	switch (type) {
	REGISTER_TYPE(Int);
	REGISTER_TYPE(Double);
	REGISTER_TYPE(LongLong);
	}
#undef REGISTER_TYPE

}
