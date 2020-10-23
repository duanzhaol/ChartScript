#ifndef MAINWINDOWINITIALIZER_H
#define MAINWINDOWINITIALIZER_H

#include "InitInterface/AbstractInitializer.h"
/**
 * @brief
 * 程序住主窗口初始化器，初始化整个程序的资源，生成主窗口
 * @ingroup MainWindow
 */
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

/**
 * @mainpage
 * ChartSceript项目的代码文档
 */
