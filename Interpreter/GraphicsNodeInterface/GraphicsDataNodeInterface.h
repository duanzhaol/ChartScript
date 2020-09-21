#ifndef GRAPHICSDATANODEINTERFACE_H
#define GRAPHICSDATANODEINTERFACE_H

#include "GraphicsNodeInterface.h"
#include <QVariant>

class GraphicsDataNodeInterface{
public:
	virtual QVariant getNodeData()const = 0;
	virtual void setNodeData(const QVariant&newData) = 0;
};

#endif // GRAPHICSDATANODEINTERFACE_H
