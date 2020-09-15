#ifndef ABSTRACTNODE_H
#define ABSTRACTNODE_H
#include <QHash>

class AbstractNode{
protected:
	using NodeName_t  = QString;

	QHash<NodeName_t,AbstractNode*> nextNodes;
	NodeName_t nodeName;
public:
	AbstractNode(const QString&name);
	virtual void process();
	virtual ~AbstractNode() = 0;
	void addNextNodes(AbstractNode*node);
	NodeName_t getNodeName() const;
	void setNodeName(const NodeName_t &value);
};

#endif // ABSTRACTNODE_H
