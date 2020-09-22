#include "AbstractPieSeries.h"

AbstractPieSeries::AbstractPieSeries()
{

}


void AbstractPieSeries::process(AbstractNode *nextNode)
{

	AbstractSeriesNode::process(nextNode);
	QStringList labelList = this->getLabels()->getNodeData().toStringList();
	QVariantList dataList = this->getData()->getNodeData().toList();

	int size = qMin(labelList.size(),dataList.size());

	for(int index = 0;index < size; ++size){
		this->series->append(new QtCharts::QPieSlice(labelList[index],dataList[index].toDouble()));
	}
}

QtCharts::QAbstractSeries *AbstractPieSeries::getSeries() const
{
	return this->series;
}


CodeText AbstractPieSeries::dataTexting() const
{
	return QString(R"(
				   \tLabels=%1
				   \tData=%2
				   )")
			.arg(this->getLabels()->dataTexting())
			.arg(this->getData()->dataTexting());
}

CodeText AbstractPieSeries::getModelType() const
{
	return QStringLiteral("PieSeries");
}
