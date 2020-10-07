#ifndef NODESHOWINITIALIZER_H
#define NODESHOWINITIALIZER_H

#include "InitInterface/InitInterface.h"

class NodeShowInitializer:public InitInterface
{
	static NodeShowInitializer *instance;
public:
	NodeShowInitializer();
	static NodeShowInitializer* getInstance();


	// InitInterface interface
public:
	virtual void init() override;
};

#endif // NODESHOWINITIALIZER_H
