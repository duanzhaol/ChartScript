#ifndef TEXTDATACONVERTER_H
#define TEXTDATACONVERTER_H

#include <QVariant>

class TextDataConverter
{
public:
	TextDataConverter();
	static QVariant textToVariant(const QString&text,bool*ok,const QVariant::Type type);
};

#endif // TEXTDATACONVERTER_H
