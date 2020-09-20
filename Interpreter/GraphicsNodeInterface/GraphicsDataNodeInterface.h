#ifndef GRAPHICSDATANODEINTERFACE_H
#define GRAPHICSDATANODEINTERFACE_H

#include "GraphicsNodeInterface.h"
#include <QVariant>

class GraphicsDataNodeInterface:public GraphicsNodeInterface{
public:
	virtual QVariant*getNodeData() = 0;
	virtual void setNodeData(QVariant*newData) = 0;
};

#endif // GRAPHICSDATANODEINTERFACE_H
