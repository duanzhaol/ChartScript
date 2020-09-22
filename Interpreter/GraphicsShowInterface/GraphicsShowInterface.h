#ifndef GRAPHICSSHOWINTERFACE_H
#define GRAPHICSSHOWINTERFACE_H

#include <QString>
#include <QChart>

class GraphicsShowInterface{
public:
	virtual QString getName()const = 0;
	virtual QtCharts::QChart*getChart()const = 0;
};

#endif // GRAPHICSSHOWINTERFACE_H
