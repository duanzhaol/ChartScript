#ifndef NODESHOWINITIALIZER_H
#define NODESHOWINITIALIZER_H

#include "InitInterface/AbstractInitializer.h"

class NodeShowInitializer:public AbstractInitializer
{
	static NodeShowInitializer *instance;
public:
	NodeShowInitializer();
	static NodeShowInitializer* getInstance();


	// InitInterface interface
public:
	virtual void init() override;

	// AbstractInitializer interface
public:
	virtual QString getWindowName() const override;
};

#endif // NODESHOWINITIALIZER_H
