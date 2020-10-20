#include "AbstractSeriesNode.h"

AbstractSeriesNode::AbstractSeriesNode()
{

}




void AbstractSeriesNode::process(AbstractNode *nextNode)
{
	Q_UNUSED(nextNode);Q_ASSERT()
	this->getSeries()->setName(this->getNodeName());
}
