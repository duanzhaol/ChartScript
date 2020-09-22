#ifndef GRAPHICSPIENODEINTERFACE_H
#define GRAPHICSPIENODEINTERFACE_H

#include "../DataModel/AbstractArrayNode.h"
#include <QStringList>

class GraphicsPieNodeInterface{
public:
	virtual AbstractArrayNode* getLabels()const = 0;
	virtual AbstractArrayNode* getData()const = 0;
};

#endif // GRAPHICSPIENODEINTERFACE_H
