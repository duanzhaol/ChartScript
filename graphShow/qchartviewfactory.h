#ifndef QCHARTVIEWFACTORY_H
#define QCHARTVIEWFACTORY_H
#include<QChartView>
#include "GraphicsScene.h"
#include "mywindow.h"
/**
 * @brief 	在工厂中可以获得正确设定过的view

 */
class QChartViewFactory
{
public:
    QChartViewFactory();
    /**
     * @brief
     * 获得根据传入的sc，并正确设置的view
     * @param 该view对应和的scene
     * @return view的指针
     */
    QtCharts::QChartView* createView(GraphicsScene *sc,myWindow *win);

};

#endif // QCHARTVIEWFACTORY_H
