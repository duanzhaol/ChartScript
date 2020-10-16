#ifndef GRAPHICSPIENODEINTERFACE_H
#define GRAPHICSPIENODEINTERFACE_H

#include "../DataModel/AbstractArrayNode.h"
#include <QStringList>

class GraphicsPieNodeInterface{
public:
    virtual AbstractArrayNode* getLabels()const = 0;//labels是String
    virtual AbstractArrayNode* getData()const = 0; //Data是数字，啥数字都行
};

#endif // GRAPHICSPIENODEINTERFACE_H
