#ifndef GRAPHSHOWINITIALIZER_H
#define GRAPHSHOWINITIALIZER_H

#include "../../InitInterface/AbstractInitializer.h"

class GraphShowInitializer:public AbstractInitializer
{
	GraphShowInitializer();
	static GraphShowInitializer *instance;
public:

	// InitInterface interface
public:
	virtual void init() override;
	static AbstractInitializer* getInstance();

	// AbstractInitializer interface
public:
	virtual QString getWindowName() const override;
};





#endif // GRAPHSHOWINITIALIZER_H
