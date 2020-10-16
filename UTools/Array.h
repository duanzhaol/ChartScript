﻿#ifndef ARRAY_H
#define ARRAY_H

#include <QList>
#include <QVariant>

template<typename T>
class Array:public QList<T>
{
	QVariant::Type elementType;
public:
	Array() = default;
	Array(QVariant::Type elementType);
	QVariant::Type getElementType() const;
	void setElementType(const QVariant::Type &value);
};

Q_DECLARE_METATYPE(Array<float>);
Q_DECLARE_METATYPE(Array<char>);
Q_DECLARE_METATYPE(Array<short>);
Q_DECLARE_METATYPE(Array<long long>);
Q_DECLARE_METATYPE(Array<QString>);
Q_DECLARE_METATYPE(Array<double>);
Q_DECLARE_METATYPE(Array<int>);

#endif // ARRAY_H

template<typename T>
QVariant::Type Array<T>::getElementType() const
{
	return elementType;
}

template<typename T>
void Array<T>::setElementType(const QVariant::Type &value)
{
	elementType = value;
}

template<typename T>
Array<T>::Array(QVariant::Type elementType):
	elementType(elementType)
{

}
