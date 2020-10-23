#ifndef UNIQUENAMER_H
#define UNIQUENAMER_H
#include <QString>
#include <QHash>
#include <QSet>

/**
 * @brief
 * 获取全局唯一的名称，并提供对名称唯一性的查询
 * @see UniqueNamerPool
 */

class UniqueNamer
{
	QString prefix,postfix;
	int index;
	QSet<QString> names;
public:
	UniqueNamer(const QString&prefix = QString(),const QString&postfix=QString(),const int startIndex = 0);
	QString getUniqueName();
	bool hasUsed(const QString&name)const;
	void addName(const QString&name);
	void removeName(const QString&name);
};

/**
 * @see UniqueNamerPool
 */
enum class NamerSeed:char{
	VariantSeed
};


uint qHash(const NamerSeed&seed)noexcept;

/**
 * @brief
 * 命名器池，通过NamerSeed获取唯一命名器
 */
class UniqueNamerPool{
	QHash<NamerSeed,UniqueNamer> pool;
	static UniqueNamerPool instance;
	UniqueNamerPool();
public:
	static UniqueNamer&getNamer(const NamerSeed seed);
};

#endif // UNIQUENAMER_H
