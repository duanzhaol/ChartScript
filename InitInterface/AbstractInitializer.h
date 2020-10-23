#ifndef INITINTERFACE
#define INITINTERFACE

#include <QWidget>

/**
 * @abstract AbstractInitializer
 * @brief
 * 抽象初始化器，所有初始化器的父类
 * 初始化器包括其所有子类，如主窗口、表格窗口、编程窗口、设计窗口的初始化
 */
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
