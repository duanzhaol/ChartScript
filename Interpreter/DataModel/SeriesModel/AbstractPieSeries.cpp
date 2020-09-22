#include "AbstractPieSeries.h"

AbstractPieSeries::AbstractPieSeries()
{

}


void AbstractPieSeries::process(AbstractNode *nextNode)
{

	AbstractSeriesNode::process(nextNode);
	QStringList labelList = this->getLabels();
	QList<qreal> dataList = this->getData();

	int size = qMin(labelList.size(),dataList.size());

	for(int index = 0;index < size; ++size){
		this->series->append(new QtCharts::QPieSlice(labelList[index],dataList[index]));
	}
}

QtCharts::QAbstractSeries *AbstractPieSeries::getSeries() const
{
	return this->series;
}
