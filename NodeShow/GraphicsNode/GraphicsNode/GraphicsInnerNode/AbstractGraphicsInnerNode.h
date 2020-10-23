#ifndef ABSTRACTGRAPHICSINNERNODE_H
#define ABSTRACTGRAPHICSINNERNODE_H

#include "../Dualputable.h"
#include "../AbstractGraphicsNode.h"

#include "MovableProxyWidget.h"

using Proxy = MovableProxyWidget;

/**
 * @brief
 * 所有内部节点的父类。
 * 内部节点即没有可移动代理，作为顶层节点一部分的节点。比如统计图节点中的序列节点
 * @see AbstractGraphicsTopNode
 */
class AbstractGraphicsInnerNode:public AbstractGraphicsNode
{
	Proxy*topProxy = nullptr;
public:
	AbstractGraphicsInnerNode();

	Proxy *getTopProxy() const;
	virtual void setTopProxy(Proxy *value);
};

#endif // ABSTRACTGRAPHICSINNERNODE_H
