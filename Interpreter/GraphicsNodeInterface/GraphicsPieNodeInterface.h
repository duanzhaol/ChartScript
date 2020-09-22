#ifndef GRAPHICSPIENODEINTERFACE_H
#define GRAPHICSPIENODEINTERFACE_H

#include <QStringList>

class GraphicsPieNodeInterface{
public:
	virtual QStringList& getLabels() = 0;
	virtual QList<qreal>& getData() = 0;
};

#endif // GRAPHICSPIENODEINTERFACE_H
