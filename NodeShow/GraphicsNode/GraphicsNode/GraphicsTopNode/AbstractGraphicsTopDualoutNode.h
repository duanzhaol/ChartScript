#ifndef ABSTRACTGRAPHICSTOPDUALOUTNODE_H
#define ABSTRACTGRAPHICSTOPDUALOUTNODE_H

#include "AbstractGraphicsTopNode.h"
#include "../Dualputable.h"

class AbstractGraphicsTopDualoutNode:
		public AbstractGraphicsTopNode,
		public Dualputable
{

public:
	AbstractGraphicsTopDualoutNode(MovableProxyWidget*proxy);

	// Outputable interface
public:
	virtual QPointF getOutputPortCoordinate(QGraphicsItem *item) override;

	// Inputable interface
public:
	virtual QPointF getInputPortCoordinate(QGraphicsItem *item) override;

};

#endif // ABSTRACTGRAPHICSTOPDUALOUTNODE_H
