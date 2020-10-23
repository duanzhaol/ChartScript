#ifndef MODELCODINGINTERFACE_H
#define MODELCODINGINTERFACE_H

#include <QString>

//! 代码模块中代码存储的类型
using CodeText = QString;

/**
 * @brief
 * 图节点编程代码化的结构，所有实现了该接口的图节点方能代码化
 */
class ModelCodingInterface{
public:
    //! 获取节点的名称
    virtual CodeText getModelName()const = 0;
    //! 节点转代码
    virtual CodeText dataTexting()const = 0;
    //! 获取接待你类型的名称
    //! @see ModelType
    virtual CodeText getModelTypeName()const = 0;
};

#endif // MODELCODINGINTERFACE_H
