#include "qchartviewfactory.h"

QChartViewFactory::QChartViewFactory()
{

}

QtCharts::QChartView *QChartViewFactory::createView(GraphicsScene *sc)
{
    QtCharts::QChartView *view=new QtCharts::QChartView();
    view->setScene(sc);
    view->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);//shua'xin'f刷新方式，重要
    view->show();
    //view->setRubberBand(QtCharts::QChartView::RectangleRubberBand);//设置缩放模式
    view->setDragMode(QGraphicsView::RubberBandDrag);//重要
    return view;
}
