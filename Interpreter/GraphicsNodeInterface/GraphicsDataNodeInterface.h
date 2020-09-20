#ifndef GRAPHICSDATANODEINTERFACE_H
#define GRAPHICSDATANODEINTERFACE_H

#include "GraphicsNodeInterface.h"
#include "../DataModel/AbstractDataNode.h"
#include <QVariant>

class GraphicsDataNodeInterface:public GraphicsNodeInterface{
public:
	virtual QVariant getNodeData() = 0;
	virtual void setNodeData(const QVariant&newData) = 0;
};

#endif // GRAPHICSDATANODEINTERFACE_H
