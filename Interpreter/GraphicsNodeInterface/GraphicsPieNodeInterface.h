#ifndef GRAPHICSPIENODEINTERFACE_H
#define GRAPHICSPIENODEINTERFACE_H

#include "../DataModel/AbstractArrayNode.h"
#include <QStringList>

/**
 * @interface GraphicsPieNodeInterface
 * @brief 饼状序列节点接口，实现该接口的子类能够成为饼状序列节点的编译单元
 */

class GraphicsPieNodeInterface{
public:
    virtual AbstractArrayNode* getLabels()const = 0;//labels是String
    virtual AbstractArrayNode* getData()const = 0; //Data是数字，啥数字都行
};

#endif // GRAPHICSPIENODEINTERFACE_H
