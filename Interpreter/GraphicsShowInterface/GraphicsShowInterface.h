#ifndef GRAPHICSSHOWINTERFACE_H
#define GRAPHICSSHOWINTERFACE_H

#include <QString>
#include <QChart>
#include "../../graphShow/ChartItem.h"

/**
 * @brief 统计图对象
 * @see ChartItem
 */
using Chart = ChartItem;

/**
 * @interface GraphicsShowInterface
 * @brief 用于编译部分和设计部分统计图传输的接口。
 * 编译部分实现该接口将生成的统计图发往设计部分
 */

class GraphicsShowInterface{
public:
	virtual QString getName()const = 0;
	virtual Chart*getChart()const = 0;
};

#endif // GRAPHICSSHOWINTERFACE_H
