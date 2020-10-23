#ifndef DUALPORTINTERFACE_H
#define DUALPORTINTERFACE_H

#include "Inputable.h"
#include "Outputable.h"
#include "MovableProxyWidget.h"

/**
 * @interface Dualputable
 * 所有拥有输入输出端口的图节点的接口，实现该接口的子类能够被连接输入输出端口
 */


class Dualputable :public Inputable,public Outputable{
public:
	Dualputable();
};

#endif // DUALPORTINTERFACE_H
