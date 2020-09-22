#include "AbstractLineSeriesNode.h"

AbstractLineSeriesNode::AbstractLineSeriesNode()
{

}
#include <QList>

void AbstractLineSeriesNode::verifyConnectable(AbstractNode *node)
{
	AbstractSeriesNode::verifyConnectable(node);
}

void AbstractLineSeriesNode::process(AbstractNode *nextNode)
{
	AbstractSeriesNode::process(nextNode);
	QVariant
			x = this->getXDataNode()->getNodeData(),
			y = this->getYDataNode()->getNodeData();



}

QtCharts::QAbstractSeries *AbstractLineSeriesNode::getSeries() const
{
	return this->series;
}
