#ifndef UNIQUENAMER_H
#define UNIQUENAMER_H
#include <QString>
#include <QHash>

class UniqueNamer
{
	QString prefix,postfix;
	int index;
public:
	UniqueNamer(const QString&prefix = QString(),const QString&postfix=QString(),const int startIndex = 0);
	QString getUniqueName();
};

enum class NamerSeed:char{
	GraphShow
};

uint qHash(const NamerSeed&seed)noexcept;

class UniqueNamerPool{
	QHash<NamerSeed,UniqueNamer> pool;
	static UniqueNamerPool instance;
	UniqueNamerPool();
public:
	static UniqueNamer&getNamer(const NamerSeed seed);
};

#endif // UNIQUENAMER_H
