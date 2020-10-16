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

UniqueNamerPool::UniqueNamerPool()
{
	this->pool.insert(NamerSeed::GraphShow,UniqueNamer("Node","",0));
}


UniqueNamer &UniqueNamerPool::getNamer(const NamerSeed seed)
{
	return UniqueNamerPool::instance.pool[seed];
}

uint qHash(const NamerSeed&seed)noexcept{
	return static_cast<uint>(seed);
}

UniqueNamerPool UniqueNamerPool::instance;
