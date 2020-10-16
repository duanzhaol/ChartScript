#ifndef INITINTERFACE
#define INITINTERFACE

#include <QWidget>

class AbstractInitializer{
protected:
	QWidget*widget = nullptr;
public:
	AbstractInitializer();
	virtual void init() = 0;
	QWidget*getWidget();
	virtual QString getWindowName()const = 0;
};

#endif //INITINTERFACE
