#ifndef ABSTRACTDATANODE_H
#define ABSTRACTDATANODE_H
#include "AbstractNode.h"
#include <QVariant>

class AbstractDataNode : public AbstractNode
{
protected:
	QVariant nodeData;
public:
	AbstractDataNode(const QString&name);

	// AbstractNode interface
public:
	virtual void process() override;
	QVariant getNodeData() const;
	void setNodeData(const QVariant &value);
};

#endif // ABSTRACTDATANODE_H
