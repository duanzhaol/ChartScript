#ifndef GRAPHSHOWTRANSMITTER_H
#define GRAPHSHOWTRANSMITTER_H

#include <QObject>
#include <QChart>
#include "../GraphicsShowInterface/GraphicsShowInterface.h"

/**
 * @brief
 * 用于编译模块和设计模块接口传输的类。
 * 编译模块将数据接口发送到设计模块，发送逻辑由该类实现。
 */

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
