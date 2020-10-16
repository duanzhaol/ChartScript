#ifndef GRAPHICSSHOWINTERFACE_H
#define GRAPHICSSHOWINTERFACE_H

#include <QString>
#include <QChart>
#include "../../graphShow/ChartItem.h"

using Chart = ChartItem;

class GraphicsShowInterface{
public:
	virtual QString getName()const = 0;
	virtual Chart*getChart()const = 0;
};

#endif // GRAPHICSSHOWINTERFACE_H
