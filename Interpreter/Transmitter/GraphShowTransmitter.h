#ifndef GRAPHSHOWTRANSMITTER_H
#define GRAPHSHOWTRANSMITTER_H

#include <QObject>
#include <QChart>
#include "../GraphicsShowInterface/GraphicsShowInterface.h"

class GraphShowTransmitter:public QObject
{
	Q_OBJECT
	GraphShowTransmitter();
	static GraphShowTransmitter instancce;
public:
	static GraphShowTransmitter&getInstance();
signals:
	void sendChart(GraphicsShowInterface*chart);

public slots:

};

#endif // GRAPHSHOWTRANSMITTER_H
