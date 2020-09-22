#include "AbstractLineSeriesNode.h"
#include <QList>

AbstractLineSeriesNode::AbstractLineSeriesNode()
{

}


void AbstractLineSeriesNode::verifyConnectable(AbstractNode *node)
{
	AbstractSeriesNode::verifyConnectable(node);
}

void AbstractLineSeriesNode::process(AbstractNode *nextNode)
{
	AbstractSeriesNode::process(nextNode);
	QVariantList
			x = this->getXDataNode()->getNodeData().toList(),
			y = this->getYDataNode()->getNodeData().toList();

	int size = qMin(x.size(),y.size());

	for(int index = 0;index < size; ++size){
		this->series->append(x[index].toDouble(),y[index].toDouble());
	}

}

QtCharts::QAbstractSeries *AbstractLineSeriesNode::getSeries() const
{
	return this->series;
}
