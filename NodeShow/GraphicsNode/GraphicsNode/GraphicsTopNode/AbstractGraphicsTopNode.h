#ifndef ABSTRACTGRAPHICSTOPNODE_H
#define ABSTRACTGRAPHICSTOPNODE_H

#include "MovableProxyWidget.h"
#include "../AbstractGraphicsNode.h"

using Proxy = MovableProxyWidget;

/**
 * @brief
 * 所有顶层节点的公共父类。
 * 顶层节点即拥有可移动代理，组织多个内部图节点的图节点
 * @see AbstractGraphicsInnerNode
 */
class AbstractGraphicsTopNode:public AbstractGraphicsNode
{
	Proxy*proxy = nullptr;
public:
	AbstractGraphicsTopNode(MovableProxyWidget*proxy);
	Proxy *getProxy() const;
};

#endif // ABSTRACTGRAPHICSTOPNODE_H
