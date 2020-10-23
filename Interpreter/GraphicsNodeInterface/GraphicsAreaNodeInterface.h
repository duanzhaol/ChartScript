#ifndef GRAPHICSAREANODEINTERFACE_H
#define GRAPHICSAREANODEINTERFACE_H
#include <QList>
#include "../DataModel/AbstractArrayNode.h"

/**
 * @interface GraphicsAreaNodeInterface
 * 区域序列节点接口，实现该接口的子类能够成为区域序列节点的编译单元
 */

class GraphicsAreaNodeInterface{
public:
	virtual AbstractArrayNode* getUpperXData()const = 0;
	virtual AbstractArrayNode* getUpperYData()const = 0;
	virtual AbstractArrayNode* getBottomXData()const = 0;
	virtual AbstractArrayNode* getBottomYData()const = 0;
};

#endif // GRAPHICSAREANODEINTERFACE_H
