#ifndef ABSTRACTGRAPHICSINNERDUALPUTNODE_H
#define ABSTRACTGRAPHICSINNERDUALPUTNODE_H

#include "AbstractGraphicsInnerNode.h"
#include "Dualputable.h"

class AbstractGraphicsInnerDualputNode:
		public AbstractGraphicsInnerNode,
		public Dualputable
{

public:
	AbstractGraphicsInnerDualputNode();

	// Outputable interface
public:
	virtual QPointF getOutputPortCoordinate(QGraphicsItem *item) override;

	// Inputable interface
public:
	virtual QPointF getInputPortCoordinate(QGraphicsItem *item) override;
};

#endif // ABSTRACTGRAPHICSINNERDUALPUTNODE_H
