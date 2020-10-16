#ifndef DUALPORTINTERFACE_H
#define DUALPORTINTERFACE_H

#include "Inputable.h"
#include "Outputable.h"
#include "MovableProxyWidget.h"

/**
 * @brief The Dualputable interface
 * @interface
 */

class Dualputable :public Inputable,public Outputable{
public:
	Dualputable();
};

#endif // DUALPORTINTERFACE_H
