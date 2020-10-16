#ifndef GRAPHSHOWINITIALIZER_H
#define GRAPHSHOWINITIALIZER_H

#include "../../InitInterface/InitInterface.h"

class GraphShowInitializer:public InitInterface
{
	GraphShowInitializer();
	static GraphShowInitializer *instance;
public:

	// InitInterface interface
public:
	virtual void init() override;
	static InitInterface* getInstance();
};





#endif // GRAPHSHOWINITIALIZER_H
