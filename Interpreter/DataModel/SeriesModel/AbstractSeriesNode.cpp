#include "AbstractSeriesNode.h"

AbstractSeriesNode::AbstractSeriesNode()
{

}




void AbstractSeriesNode::process(AbstractNode *nextNode)
{
    Q_UNUSED(nextNode);
	this->getSeries()->setName(this->getNodeName());
}
