#ifndef GRAPHICSXYNODEINTERFACE_H
#define GRAPHICSXYNODEINTERFACE_H
#include "../DataModel/AbstractArrayNode.h"
#include <QList>

/**
 * @interface GraphicsXYNodeInterface
 * XY坐标轴都为数字的序列（如折线图、区域图等）接口，实现该接口的子类能成为这些序列的编译单元
 */

class GraphicsXYNodeInterface
{
public:
	virtual AbstractArrayNode* getXData()const = 0;
	virtual AbstractArrayNode* getYData()const = 0;

};

#endif // GRAPHICSXYNODEINTERFACE_H
