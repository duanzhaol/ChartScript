#ifndef GRAPHSHOWTRANSMITTER_H
#define GRAPHSHOWTRANSMITTER_H

#include <QObject>
#include <QChart>

class GraphShowTransmitter:public QObject
{
	Q_OBJECT
	GraphShowTransmitter();
	GraphShowTransmitter&getInstance();
	static GraphShowTransmitter instancce;
public:
signals:
	void sendChart(QtCharts::QChart*chart);

public slots:

};

#endif // GRAPHSHOWTRANSMITTER_H
