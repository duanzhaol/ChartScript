#include "AbstractScatterSeriesNode.h"

AbstractScatterSeriesNode::AbstractScatterSeriesNode()
{

}


void AbstractScatterSeriesNode::process(AbstractNode *nextNode)
{
	AbstractSeriesNode::process(nextNode);
	auto
			x = this->getXData()->getNodeData().toList(),
			y = this->getYData()->getNodeData().toList();

	int size = qMin(x.size(),y.size());

	for(int index = 0;index < size; ++size){
		this->series->append(x[index].toDouble(),y[index].toDouble());
	}
}

QtCharts::QAbstractSeries *AbstractScatterSeriesNode::getSeries() const
{
	return this->series;
}


CodeText AbstractScatterSeriesNode::dataTexting() const
{
	return QString(R"(
				   \tX=%1
				   \tY=%2
				   )")
			.arg(this->getXData()->dataTexting())
			.arg(this->getYData()->dataTexting());
}

CodeText AbstractScatterSeriesNode::getModelTypeName() const
{
	return QStringLiteral("ScatterSeries");
}


ModelType AbstractScatterSeriesNode::getDataModelType() const
{
	return ModelType::ScatterSeries;
}
