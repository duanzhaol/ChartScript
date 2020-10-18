#ifndef MAINWINDOWINITIALIZER_H
#define MAINWINDOWINITIALIZER_H

#include "InitInterface/AbstractInitializer.h"

class MainWindowInitializer:public AbstractInitializer
{
	static MainWindowInitializer*instace;
public:
	MainWindowInitializer();

	static MainWindowInitializer* getInstance();

	// InitInterface interface
public:
	virtual void init() override;

	// AbstractInitializer interface
public:
	virtual QString getWindowName() const override;
};

#endif // MAINWINDOWINITIALIZER_H
