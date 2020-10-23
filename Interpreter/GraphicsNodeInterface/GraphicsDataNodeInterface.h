#ifndef GRAPHICSDATANODEINTERFACE_H
#define GRAPHICSDATANODEINTERFACE_H

#include "GraphicsNodeInterface.h"
#include <QVariant>

/**
 * @interface GraphicsDataNodeInterface
 * @brief 数据节点接口，实现该接口的子类能够成为数据节点的编译单元
 */


class GraphicsDataNodeInterface{
public:
	virtual QVariant getNodeData()const = 0;
	virtual void setNodeData(const QVariant&newData) = 0;
};

#endif // GRAPHICSDATANODEINTERFACE_H
