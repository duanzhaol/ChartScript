#include "UniqueNamer.h"
#include <QDebug>

UniqueNamer::UniqueNamer(const QString&prefix, const QString&postfix, const int startIndex):
	prefix(prefix),postfix(postfix),index(startIndex)
{
qDebug()<<prefix<<endl;
}

QString UniqueNamer::getUniqueName()
{
	return prefix + (QString::number(++index)) + postfix;
}

bool UniqueNamer::hasUsed(const QString &name) const
{
	return names.contains(name);
}

void UniqueNamer::addName(const QString &name)
{
	names.insert(name);
}

void UniqueNamer::removeName(const QString &name)
{
	names.remove(name);
}

UniqueNamerPool::UniqueNamerPool()
{
	this->pool.insert(NamerSeed::VariantSeed,UniqueNamer("Node","",0));
}


UniqueNamer &UniqueNamerPool::getNamer(const NamerSeed seed)
{
	return UniqueNamerPool::instance.pool[seed];
}

uint qHash(const NamerSeed&seed)noexcept{
	return static_cast<uint>(seed);
}

UniqueNamerPool UniqueNamerPool::instance;
